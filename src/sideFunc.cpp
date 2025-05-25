#include "../include/sideFunc.h"
#include "../include/huffman.h"

void processQuery() {
    int choice;
    while (true) {
        cout << "Option list:\n";
        cout << "1. Encode\n";
        cout << "2. Decode\n";
        cout << "3. Encode and measure average execution time\n";
        cout << "4. Decode and measure average execution time\n";
        cout << "5. Quit.\n";
        cout << "Enter your option: ";
        cin >> choice;
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
    
        if (choice == 1) 
            processChoice1();
        else if (choice == 2)
            processChoice2();
        else if (choice == 3)
            processChoice3();
        else if (choice == 4) 
            processChoice4();
        else if (choice == 5)
            return;
        else
            cout << "Invalid.\n";
    }
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
        HuffmanEncoder encoder("data/TheArtificialCorpus/a.txt", "data/compressed/a.huf");
        encoder.encode();
    }
    else if (choice == 2) {
        HuffmanEncoder encoder("data/TheArtificialCorpus/aaa.txt", "data/compressed/aaa.huf");
        encoder.encode();
    }
    else if (choice == 3) {
        HuffmanEncoder encoder("data/TheArtificialCorpus/alphabet.txt", "data/compressed/alphabet.huf");
        encoder.encode();
    }
    else if (choice == 4) {
        HuffmanEncoder encoder("data/TheArtificialCorpus/random.txt", "data/compressed/random.huf");
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
        HuffmanDecoder decoder("data/compressed/a.huf", "data/result/result_a.txt");
        decoder.decode();
    }
    else if (choice == 2) {
        HuffmanDecoder decoder("data/compressed/aaa.huf", "data/result/result_aaa.txt");
        decoder.decode();
    }
    else if (choice == 3) {
        HuffmanDecoder decoder("data/compressed/alphabet.huf", "data/result/result_alphabet.txt");
        decoder.decode();
    }
    else if (choice == 4) {
        HuffmanDecoder decoder("data/compressed/random.huf", "data/result/result_random.txt");
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
        HuffmanEncoder encoder("data/TheArtificialCorpus/a.txt", "data/compressed/a.huf");
        encoder.encodeAndMeasure("data/TheArtificialCorpus/a.txt", times);
    }
    else if (choice == 2) {
        HuffmanEncoder encoder("data/TheArtificialCorpus/aaa.txt", "data/compressed/aaa.huf");
        encoder.encodeAndMeasure("data/TheArtificialCorpus/aaa.txt", times);
    }
    else if (choice == 3) {
        HuffmanEncoder encoder("data/TheArtificialCorpus/alphabet.txt", "data/compressed/alphabet.huf");
        encoder.encodeAndMeasure("data/TheArtificialCorpus/alphabet.txt", times);
    }
    else if (choice == 4) {
        HuffmanEncoder encoder("data/TheArtificialCorpus/random.txt", "data/compressed/random.huf");
        encoder.encodeAndMeasure("data/TheArtificialCorpus/random.txt", times);
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
        HuffmanDecoder decoder("data/compressed/a.huf", "data/result/result_a.txt");
        decoder.decodeAndMeasure("data/compressed/a.huf", times);
    }
    else if (choice == 2) {
        HuffmanDecoder decoder("data/compressed/aaa.huf", "data/result/result_aaa.txt");
        decoder.decodeAndMeasure("data/compressed/aaa.huf", times);
    }
    else if (choice == 3) {
        HuffmanDecoder decoder("data/compressed/alphabet.huf", "data/result/result_alphabet.txt");
        decoder.decodeAndMeasure("data/compressed/alphabet.huf", times);
    }
    else if (choice == 4) {
        HuffmanDecoder decoder("data/compressed/random.huf", "data/result/random.txt");
        decoder.decodeAndMeasure("data/compressed/random.huf", times);
    }
    else 
        cout << "Invalid!.\n";
}