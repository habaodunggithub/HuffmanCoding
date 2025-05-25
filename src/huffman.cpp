#include "../include/huffman.h"
#include <iostream>
#include <cstdint>
#include <chrono>

HuffmanNode::HuffmanNode() {
    freq = 0;
    left = right = nullptr;
}

HuffmanNode::HuffmanNode(char _key) {
    key = _key;
    freq = 0;
    left = right = nullptr;
}

Huffman::Huffman() {
}

Huffman::Huffman(string _inpFile, string _outFile) {
    inpFile = _inpFile;
    outFile = _outFile;
    root = nullptr;

    huffCodes.resize(MAXCHAR, 0);
    codeLen.resize(MAXCHAR, 0);
    freq.resize(MAXCHAR, 0);
}

Huffman::~Huffman() {
}

void Huffman::createHuffmanTree() {
    MinHeap pq;
    for (int i = 0; i < MAXCHAR; i++)
        if (freq[i]) {
            HuffmanNode* p = new HuffmanNode(char(i));
            p->freq = freq[i];
            pq.insertNode(p);
        }

    if (pq.size() == 1) {
        root = pq.pop();
        return;
    }

    while (pq.size() > 1) {
        root = new HuffmanNode();
        root->left = pq.pop();
        root->freq += root->left->freq;

        root->right = pq.pop();
        root->freq += root->right->freq;

        pq.insertNode(root);
    }
}

void Huffman::deleteBottomUp(HuffmanNode* p) {
    if (!p)
        return;
    deleteBottomUp(p->left);
    deleteBottomUp(p->right);
    delete p;
}

void Huffman::deleteHuffmanTree() {
    deleteBottomUp(root);
    root = nullptr;
}

HuffmanEncoder::HuffmanEncoder() {

}

HuffmanEncoder::HuffmanEncoder(string _inpFile, string _outFile): Huffman(_inpFile, _outFile) {};

HuffmanEncoder::~HuffmanEncoder() {
    deleteHuffmanTree();
}

void HuffmanEncoder::countFrequency() {
    ifstream inp(inpFile);
    freq.resize(MAXCHAR, 0);

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
    huffCodes.resize(MAXCHAR, 0);
    codeLen.resize(MAXCHAR, 0);
    if (!root->left && !root->right) {
        huffCodes[root->key] = 0;
        codeLen[root->key] = 1;
        return;
    }
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
}

void HuffmanEncoder::encodeAndMeasure(string inFile, int times) {
    unsigned long long sum = 0;
    for (int i = 0; i < times; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        HuffmanEncoder encoder(inFile, "data/temp/temp_code_" + std::to_string(i) + ".huf");
        encoder.encode();
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        sum += duration.count();
    }
    std::cout << "Average time for encode: " << sum/times << "\n";
}

HuffmanDecoder::HuffmanDecoder() {

}

HuffmanDecoder::HuffmanDecoder(string _inpFile, string _outFile): Huffman(_inpFile, _outFile) {};

HuffmanDecoder::~HuffmanDecoder() {
    deleteHuffmanTree();
}

void HuffmanDecoder::decode() {
    ifstream inp(inpFile, ios::binary);
    ofstream out(outFile);

    int charCount = 0; // Avoid decode padding bits
    for (int i = 0; i < MAXCHAR; i++) {
        inp.read(reinterpret_cast<char*>(&freq[i]), sizeof(int));
        charCount += freq[i];
    }

    createHuffmanTree();

    // Huffman tree has 1 node
    if (!root->left && !root->right) {
        for (int i = 0; i < charCount; i++)
            out.put(root->key);
        inp.close();
        out.close();
        return;
    }

    int outIdx = 0;
    char rawBuff[BUFFSIZE];
    char outBuff[BUFFSIZE];
    HuffmanNode* p = root;

    while (charCount) {
        inp.read(rawBuff, BUFFSIZE);
        streamsize bytesRead = inp.gcount();

        if (bytesRead == 0)
            break;

        for (int i = 0; i < bytesRead && charCount; i++) {
            unsigned char byte = rawBuff[i];
            for (int j = 7; j >= 0 && charCount; j--) {
                int bit = (byte >> j) & 1;
                if (bit)
                    p = p->right;
                else
                    p = p->left;
                if (!p->left && !p->right) {
                    outBuff[outIdx++] = p->key;
                    p = root;
                    charCount--;

                    if (outIdx == BUFFSIZE) {
                        out.write(outBuff, outIdx);
                        outIdx = 0;
                    }
                }
            }
        }
    }

    // Leftover
    if (outIdx > 0)
        out.write(outBuff, outIdx);

    inp.close();
    out.close();
}

void HuffmanDecoder::decodeAndMeasure(string inFile, int times) {
    unsigned long long sum = 0;
    for (int i = 0; i < times; ++i) {
        HuffmanDecoder decoder(inFile,  "data/temp/temp_output_" + std::to_string(i) + ".txt");
        auto start = std::chrono::high_resolution_clock::now();
        decoder.decode();
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        sum += duration.count();
    }
    std::cout << "Average time for decode: " << sum/times << "\n";
}