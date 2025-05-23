#include "sideFunc.h"
#include "huffman.h"

void processQuery() {
    cout << "Option list:\n";
    cout << "1. Encode\n";
    cout << "2. Decode\n";
    cout << "3. Encode and measure average execution time\n";
    cout << "4. Decode and measure average execution time\n";
    cout << "Enter your option: ";
    int choice;
    cin >> choice;

    if (choice == 1) 
        processChoice1();
    else if (choice == 2)
        processChoice2();
    else if (choice == 3)
        processChoice3();
    else if (choice == 4) 
        processChoice4();
    else
        cout << "Invalid.\n";
}

void processChoice1() {
    cout << "Choose file to encode:\n";
    cout << "1. a.txt: contains only one character 'a'.\n";
    cout << "2. aaa.txt: contains 100.000 character 'a'.\n";
    cout << "3. alphabet.txt: contains 100.000 repeating alphabet characters.\n";
    cout << "4. random.txt: contains 100.000 random characters.\n";
    cout << "Enter your option: ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        HuffmanEncoder encoder("TheArtificialCorpus/a.txt", "Compressed/a.huf");
        encoder.encode();
    }
    else if (choice == 2) {
        HuffmanEncoder encoder("TheArtificialCorpus/aaa.txt", "Compressed/aaa.huf");
        encoder.encode();
    }
    else if (choice == 3) {
        HuffmanEncoder encoder("TheArtificialCorpus/alphabet.txt", "Compressed/alphabet.huf");
        encoder.encode();
    }
    else if (choice == 4) {
        HuffmanEncoder encoder("TheArtificialCorpus/random.txt", "Compressed/random.huf");
        encoder.encode();
    }
    else 
        cout << "Invalid!.\n";
}

void processChoice2() {
    cout << "Choose file to decode:\n";
    cout << "1. a.huf: encoded from a.txt.\n";
    cout << "2. aaa.huf: encoded from aaa.txt.\n";
    cout << "3. alphabet.huf: encoded from alphabet.txt.\n";
    cout << "4. random.huf: encoded from random.txt.\n";
    cout << "Enter your option: ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        HuffmanDecoder decoder("Compressed/a.huf", "Result/result_a.txt");
        decoder.decode();
    }
    else if (choice == 2) {
        HuffmanDecoder decoder("Compressed/aaa.huf", "Result/result_aaa.txt");
        decoder.decode();
    }
    else if (choice == 3) {
        HuffmanDecoder decoder("Compressed/alphabet.huf", "Result/result_alphabet.txt");
        decoder.decode();
    }
    else if (choice == 4) {
        HuffmanDecoder decoder("Compressed/random.huf", "Result/result_random.txt");
        decoder.decode();
    }
    else 
        cout << "Invalid!.\n";
}

void processChoice3() {
    cout << "Choose file to encode:\n";
    cout << "1. a.txt: contains only one character 'a'.\n";
    cout << "2. aaa.txt: contains 100.000 character 'a'.\n";
    cout << "3. alphabet.txt: contains 100.000 repeating alphabet characters.\n";
    cout << "4. random.txt: contains 100.000 random characters.\n";
    cout << "Enter your option: ";
    int choice;
    cin >> choice;

    cout << "Enter the number of executions to calculate the average execution time: ";
    int times;
    cin >> times;

    if (choice == 1) {
        HuffmanEncoder encoder("TheArtificialCorpus/a.txt", "Compressed/a.huf");
        encoder.encodeAndMeasure(times);
    }
    else if (choice == 2) {
        HuffmanEncoder encoder("TheArtificialCorpus/aaa.txt", "Compressed/aaa.huf");
        encoder.encodeAndMeasure(times);
    }
    else if (choice == 3) {
        HuffmanEncoder encoder("TheArtificialCorpus/alphabet.txt", "Compressed/alphabet.huf");
        encoder.encodeAndMeasure(times);
    }
    else if (choice == 4) {
        HuffmanEncoder encoder("TheArtificialCorpus/random.txt", "Compressed/random.huf");
        encoder.encodeAndMeasure(times);
    }
    else 
        cout << "Invalid!.\n";
}

void processChoice4() {
    cout << "Choose file to decode:\n";
    cout << "1. a.huf: encoded from a.txt.\n";
    cout << "2. aaa.huf: encoded from aaa.txt.\n";
    cout << "3. alphabet.huf: encoded from alphabet.txt.\n";
    cout << "4. random.huf: encoded from random.txt.\n";
    cout << "Enter your option: ";
    int choice;
    cin >> choice;

    cout << "Enter the number of executions to calculate the average execution time: ";
    int times;
    cin >> times;

    if (choice == 1) {
        HuffmanDecoder decoder("Compressed/a.huf", "Result/result_a.txt");
        decoder.decodeAndMeasure(times);
    }
    else if (choice == 2) {
        HuffmanDecoder decoder("Compressed/aaa.huf", "Result/result_aaa.txt");
        decoder.decodeAndMeasure(times);
    }
    else if (choice == 3) {
        HuffmanDecoder decoder("Compressed/alphabet.huf", "Result/result_alphabet.txt");
        decoder.decodeAndMeasure(times);
    }
    else if (choice == 4) {
        HuffmanDecoder decoder("Compressed/random.huf", "Result/random.txt");
        decoder.decodeAndMeasure(times);
    }
    else 
        cout << "Invalid!.\n";
}