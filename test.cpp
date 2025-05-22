#include "test.h"

void computeBitLengthAndEntropy(const vector<int>& freq, const vector<int>& codeLen) {
    double totalFreq = 0.0;
    for (int f : freq) {
        totalFreq += f;
    }
    if (totalFreq == 0) {
        cout << "Total frequency is zero. Nothing to compute." << endl;
        return;
    }

    double avgBitLength = 0.0;
    double entropy = 0.0;

    for (int i = 0; i < 256; ++i) {
        int f = freq[i];
        int len  = codeLen[i];

        if (f > 0 && len > 0) {
            double p = f * 1.0 / totalFreq;
            avgBitLength += p * len;
            entropy += -p * log2(p);
        }
    }

    cout << fixed << setprecision(6);
    cout << "Average code length (bits/character): " << avgBitLength << endl;
    cout << "Entropy (bits/character):             " << entropy << endl;
    cout << "Efficiency:                           " << (entropy / avgBitLength) * 100 << " %" << endl;
}

void testFromFileList(const string &listPath) {
    ifstream listFile(listPath);
    if (!listFile) {
        return;
    }

    string fileName;
    while (getline(listFile, fileName)) {
        if (fileName.empty()) continue;

        HuffmanEncoder encoder(fileName + ".txt", fileName + ".huf");
        encoder.encode();
        computeBitLengthAndEntropy(encoder.freq, encoder.codeLen);
        encoder.deleteHuffmanTree();

        std::cout << "-----------------------------\n";
    }

    listFile.close();
}
