#include <iostream>
#include "huffman.h"

int main(int argc, char** argv) {
    string query(argv[1]);
    if (query == "--encode") {
        Huffman huffman(argv[2], argv[3]);
        huffman.compress();
    }
    else if (argv[1] == "--decode") {
        cout << "Not done.\n";
    }
    else
        cout << "Not done.\n";

    return 0;
}
