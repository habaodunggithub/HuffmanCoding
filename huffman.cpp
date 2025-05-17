#include "huffman.h"
#include <iostream>

HuffmanNode::HuffmanNode() {
    freq = 0;
    left = right = nullptr;
}

HuffmanNode::HuffmanNode(char _key) {
    key = _key;
    freq = 0;
    left = right = nullptr;
}

Huffman::Huffman(string _inpFile, string _outFile) {
    inpFile = _inpFile;
    outFile = _outFile;
    freq.resize(MAXCHAR, 0);
    huffCodes.resize(MAXCHAR);
    codeLen.resize(MAXCHAR);
    root = nullptr;
}

void Huffman::createHuffmanTree() {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, cmp<HuffmanNode*>> pq;
    for (int i = 0; i < MAXCHAR; i++)
        if (freq[i]) {
            HuffmanNode* p = new HuffmanNode(char(i));
            p->freq = freq[i];
            pq.push(p);
        }

    if (pq.size() == 1) {
        root = new HuffmanNode(pq.top()->key);
        root->freq = pq.top()->freq;
        return;
    }

    while (pq.size() > 1) {
        root = new HuffmanNode();
        root->left = pq.top();
        root->freq += root->left->freq;
        pq.pop();

        root->right = pq.top();
        root->freq += root->right->freq;
        pq.pop();

        pq.push(root);
    }
}

void Huffman::deleteHuffmanTree(HuffmanNode* p) {
    if (!p)
        return;
    deleteHuffmanTree(p->left);
    deleteHuffmanTree(p->right);
    delete p;
}

HuffmanEncoder::HuffmanEncoder(string _inpFile, string _outFile): Huffman(_inpFile, _outFile) {};

void HuffmanEncoder::countFrequency() {
    ifstream inp(inpFile);

    char c;
    while (inp.get(c))
        freq[c]++;
    inp.close();
}

void HuffmanEncoder::traverse(HuffmanNode* root, int code, int len, vector<int> &huffCodes) {
    if (!root->left && !root->right) {
        huffCodes[root->key] = code;
        codeLen[root->key] = len;
        return;
    }
    if (root->left) traverse(root->left, code << 1, len+1, huffCodes);
    if (root->right) traverse(root->right, (code << 1) | 1, len+1, huffCodes);
}

void HuffmanEncoder::assignCode() {
    huffCodes.resize(MAXCHAR);
    codeLen.resize(MAXCHAR);
    traverse(root, 0, 0, huffCodes);
}

void HuffmanEncoder::encode() {
    countFrequency();
    createHuffmanTree();
    assignCode();

    ifstream inp(inpFile);
    ofstream out(outFile, ios::binary);

    // Write frequency array to output file
    for (int i = 0; i < MAXCHAR; i++)
        out.write(reinterpret_cast<char*>(&freq[i]), sizeof(int));

    uint64_t bitBuffer = 0;
    int bitCount = 0;
    char c;

    while (inp.get(c)) {
        int code = huffCodes[c];
        int len = codeLen[c];

        bitBuffer <<= len;
        bitBuffer |= code;
        bitCount += len;

        while (bitCount >= 8) {
            uint8_t byte = (bitBuffer >> (bitCount - 8)) & 0xFF;
            out.put(byte);
            bitCount -= 8;
        }
    }

    if (bitCount > 0) {
        uint8_t byte = (bitBuffer << (8 - bitCount)) & 0xFF;
        out.put(byte);
    }

    inp.close();
    out.close();
    deleteHuffmanTree(root);
    root = nullptr;
}

HuffmanDecoder::HuffmanDecoder(string _inpFile, string _outFile): Huffman(_inpFile, _outFile) {};

void HuffmanDecoder::decode() {
    ifstream inp(inpFile, ios::binary);
    ofstream out(outFile);

    int charCount = 0; // Avoid decode padding bits
    for (int i = 0; i < MAXCHAR; i++) {
        inp.read(reinterpret_cast<char*>(&freq[i]), sizeof(int));
        charCount += freq[i];
    }

    createHuffmanTree();
    HuffmanNode* p = root;

    int i = 0;
    char byte;
    char buffer[MAXBUFF];
    while (inp.read(&byte, 1) && charCount) {
        for (int j = 7; j >= 0 && charCount; j--) {
            int bit = (byte >> j) & 1;
            if (bit)
                p = p->right;
            else
                p = p->left;
            if (!p->left && !p->right) {
                buffer[i%MAXBUFF] = p->key;
                p = root;
                i++;
                charCount--;

                if (i%MAXBUFF == 0)
                    out << buffer;
            }
        }
    }

    // Leftover
    if (i%MAXBUFF != 0)
        for (int j = 0; j < i%MAXBUFF; j++)
            out << buffer[j];

    inp.close();
    out.close();
    deleteHuffmanTree(root);
    root = nullptr;
}
