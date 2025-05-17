#include <queue>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

const int MAXCHAR = 256;
const int MAXBUFF = 1000;

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
    vector<int> freq;
    vector<int> huffCodes;
    vector<int> codeLen;
    HuffmanNode* root;

public:
    Huffman(string, string);
    void createHuffmanTree();
    void deleteHuffmanTree(HuffmanNode*);
};

class HuffmanEncoder: public Huffman {
public:
    HuffmanEncoder(string, string);
    void countFrequency();
    void traverse(HuffmanNode*, int, int, vector<int>&);
    void assignCode();
    void encode();
};

class HuffmanDecoder: public Huffman {
public:
    HuffmanDecoder(string, string);
    void decode();
};
