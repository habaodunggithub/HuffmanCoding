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
}

void Huffman::createMinHeap() {
    ifstream inp(inpFile);
    vector<int> freq(MAXCHAR, 0);

    char c;
    while (inp.get(c))
        freq[c]++;
    inp.close();

    for (int i = 0; i < MAXCHAR; i++)
        if (freq[i]) {
            HuffmanNode* p = new HuffmanNode(char(i));
            p->freq = freq[i];
            pq.push(p);
        }
    inp.close();
}

void Huffman::createHuffmanTree() {
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

void Huffman::traverse(HuffmanNode* root, int code, int len, vector<int> &huffCodes) {
    if (!root->left && !root->right) {
        huffCodes[root->key] = code;
        codeLen[root->key] = len;
        return;
    }
    if (root->left) traverse(root->left, code << 1, len+1, huffCodes);
    if (root->right) traverse(root->right, (code << 1) | 1, len+1, huffCodes);
}

void Huffman::calculateCode() {
    huffCodes.resize(MAXCHAR);
    codeLen.resize(MAXCHAR);
    traverse(root, 0, 0, huffCodes);
}

void Huffman::compress() {
    createMinHeap();
    createHuffmanTree();
    calculateCode();

    ifstream inp(inpFile);
    ofstream out(outFile, ios::binary);

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
}
