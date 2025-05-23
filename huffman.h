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
    Huffman();
    Huffman(string, string);
    virtual ~Huffman();

    vector<int> freq;
    vector<int> huffCodes;
    vector<int> codeLen;
    void createHuffmanTree();
    void deleteBottomUp(HuffmanNode*);
    void deleteHuffmanTree();
};

class HuffmanEncoder: public Huffman {
public:
    HuffmanEncoder();
    HuffmanEncoder(string, string);
    ~HuffmanEncoder();

    void countFrequency();
    void traverse(HuffmanNode*, int, int, vector<int>&);
    void assignCode();
    void encode();
    void encodeAndMeasure(string, int);
};

class HuffmanDecoder: public Huffman {
public:
    HuffmanDecoder();
    HuffmanDecoder(string, string);
    ~HuffmanDecoder();

    void decode();
    void decodeAndMeasure(string, int);
};
