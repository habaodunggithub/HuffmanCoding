#include <iostream>
#include "huffman.h"
#include "test.h"

int main(int argc, char** argv) {
    // string query(argv[1]);
    // if (query == "--encode") {
    //     HuffmanEncoder encoder(argv[2], argv[3]);
    //     encoder.encode();
    //     encoder.deleteHuffmanTree();
    // }
    // else if (query == "--decode") {
    //     HuffmanDecoder decoder(argv[2], argv[3]);
    //     decoder.decode();
    //     decoder.deleteHuffmanTree();
    // }
    // else
    //     cout << "Invalid query!\n";

    testFromFileList("file_list.txt");

    return 0;
}