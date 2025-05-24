#pragma once

#include <iostream>
#include <vector>
#include "huffman.h"
using namespace std;

struct HuffmanNode;

class MinHeap {
private:
    vector<HuffmanNode*> minHeap;

public:
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