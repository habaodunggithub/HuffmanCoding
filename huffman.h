#pragma once

#include <queue>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

const int MAXCHAR = 256;
const int BUFFSIZE = 4096;

struct HuffmanNode {
    char key;
    int freq;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode();
    HuffmanNode(char _key);
};

struct MinHeap {
    vector<HuffmanNode*> minHeap;

    MinHeap();

    int size();
    int leftChild(int);
    int rightChild(int);
    int parent(int);
    void shift(int, int);
    void heapify();
    void insertNode(HuffmanNode*);
    HuffmanNode* pop();
    bool isEmpty();
};

class Huffman {
protected:
    string inpFile, outFile;
    HuffmanNode* root;

public:
    vector<int> freq;
    vector<int> huffCodes;
    vector<int> codeLen;
    Huffman(string, string);
    void createHuffmanTree();
    void deleteBottomUp(HuffmanNode*);
    void deleteHuffmanTree();
};

class HuffmanEncoder: public Huffman {
public:
    HuffmanEncoder(string, string);
    void countFrequency();
    void traverse(HuffmanNode*, int, int, vector<int>&);
    void assignCode();
    void encode();
    void encodeAndMeasure(string, int);
};

class HuffmanDecoder: public Huffman {
public:
    HuffmanDecoder(string, string);
    void decode();
    void decodeAndMeasure(string, int);
};
