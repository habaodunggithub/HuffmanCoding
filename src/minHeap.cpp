#include "../include/minHeap.h"

MinHeap::MinHeap() {
    minHeap.clear();
}

int MinHeap::size() {
    return minHeap.size();
}

int MinHeap::leftChild(int x) {
    return 2*x + 1;
}

int MinHeap::rightChild(int x) {
    return 2*x + 2;
}

int MinHeap::parent(int x) {
    return (x - 1)/2;
}

void MinHeap::shift(int left, int right) {
    if (left >= right)
        return;
    int i = left;
    int j = leftChild(i);
    HuffmanNode* x = minHeap[left];
    while (j <= right) {
        if (j < right) {
            if (minHeap[j]->freq > minHeap[j + 1]->freq)
                ++j;
        }

        if (minHeap[j]->freq >= x->freq)
            break;

        swap(minHeap[i], minHeap[j]);
        i = j;
        j = leftChild(i);
    }

    minHeap[i] = x;
}

void MinHeap::heapify() {
    int i = minHeap.size()/2;
    for (; i >= 0; --i) {
        shift(i, minHeap.size() - 1);
    }
}

void MinHeap::insertNode(HuffmanNode* k) {
    minHeap.push_back(k);
    int i = minHeap.size() - 1;

    while (i != 0 && minHeap[parent(i)]->freq > minHeap[i]->freq) {
       swap(minHeap[i], minHeap[parent(i)]);
       i = parent(i);
    }
}

HuffmanNode* MinHeap::pop() {
    if (minHeap.size() <= 0)
        return nullptr;

    HuffmanNode* root = minHeap[0];
    minHeap[0] = minHeap[minHeap.size() - 1];
    minHeap.pop_back();
    heapify();

    return root;
}

bool MinHeap::isEmpty() {
    return (minHeap.size() == 0);
}
