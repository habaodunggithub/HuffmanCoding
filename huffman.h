#include <queue>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

const int MAXCHAR = 256;

template <typename T>
struct cmp {
    bool operator()(const T& a, const T& b) const {
        return a->freq > b->freq;
    }
};

struct HuffmanNode {
    char key;
    int freq;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode();
    HuffmanNode(char _key);
};

class Huffman {
protected:
    string inpFile, outFile;
    vector<int> huffCodes;
    vector<int> codeLen;
    HuffmanNode* root;
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, cmp<HuffmanNode*>> pq;
    void traverse(HuffmanNode*, int, int, vector<int>&);

public:
    Huffman(string, string);
    void createMinHeap();
    void createHuffmanTree();
    void calculateCode();
    void compress();
    // void decompress();
    // void recreateHuffmanTree();
};
