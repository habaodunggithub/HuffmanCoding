#include <iostream>
#include "huffman.h"

int main(int argc, char** argv) {
    string query(argv[1]);
    if (query == "--encode") {
        HuffmanEncoder encoder(argv[2], argv[3]);
        encoder.encode();
    }
    else if (query == "--decode") {
        HuffmanDecoder decoder(argv[2], argv[3]);
        decoder.decode();
    }
    else
        cout << "Invalid query!\n";

    return 0;
}
