#include "../include/sideFunc.h"
#include "../include/huffman.h"
#include "../include/AdaptiveHuffmanCoding.h"

void processQuery() {
    int choice;
    while (true) {
        cout << "Option list:\n";
        cout << "1. Encode\n";
        cout << "2. Decode\n";
        cout << "3. Encode and measure average execution time\n";
        cout << "4. Decode and measure average execution time\n";
        cout << "5. Quit.\n";
        cout << "Enter your choice: ";
        cin >> choice;
    
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
    int choice, algo;
    cout << "Choose file to encode:\n";
    cout << "1. a.txt: contains only one character 'a'.\n";
    cout << "2. aaa.txt: contains 100.000 character 'a'.\n";
    cout << "3. alphabet.txt: contains 100.000 repeating alphabet characters.\n";
    cout << "4. random.txt: contains 100.000 random characters.\n";
    cout << "5. user-selected file.\n";
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "Choose compress algorithm:\n";
    cout << "1. Static Huffman Coding.\n";
    cout << "2. Adaptive Huffman Coding.\n";
    cout << "Enter your choice: ";
    cin >> algo;

    if (algo == 1) {
        if (choice == 1) {
            HuffmanEncoder encoder("data/TheArtificialCorpus/a.txt", "data/compressed/staticHuffman/a.huf");
            encoder.encode();
        }
        else if (choice == 2) {
            HuffmanEncoder encoder("data/TheArtificialCorpus/aaa.txt", "data/compressed/staticHuffman/aaa.huf");
            encoder.encode();
        }
        else if (choice == 3) {
            HuffmanEncoder encoder("data/TheArtificialCorpus/alphabet.txt", "data/compressed/staticHuffman/alphabet.huf");
            encoder.encode();
        }
        else if (choice == 4) {
            HuffmanEncoder encoder("data/TheArtificialCorpus/random.txt", "data/compressed/staticHuffman/random.huf");
            encoder.encode();
        }
        else if (choice == 5) {
            string filePath;
            cout << "Enter file path: ";
            cin >> filePath;
            HuffmanEncoder encoder(filePath, "data/compressed/staticHuffman/userSample.huf");
            encoder.encode();
        }
        else 
            cout << "Invalid!.\n";
    }
    else if (algo == 2) {
        AdaptiveHuffmanCoding encoder;
        if (choice == 1) {
            encoder.inpFile = "data/TheArtificialCorpus/a.txt";
            encoder.outFile = "data/compressed/adaptiveHuffman/a.huf";
            encoder.Encode();
        }
        else if (choice == 2) {
            encoder.inpFile = "data/TheArtificialCorpus/aaa.txt";
            encoder.outFile = "data/compressed/adaptiveHuffman/aaa.huf";
            encoder.Encode();
        }
        else if (choice == 3) {
            encoder.inpFile = "data/TheArtificialCorpus/alphabet.txt";
            encoder.outFile = "data/compressed/adaptiveHuffman/alphabet.huf";
            encoder.Encode();
        }
        else if (choice == 4) {
            encoder.inpFile = "data/TheArtificialCorpus/random.txt";
            encoder.outFile = "data/compressed/adaptiveHuffman/random.huf";
            encoder.Encode();
        }
        else if (choice == 5) {
            string filePath;
            cout << "Enter file path: ";
            cin >> filePath;
            encoder.inpFile = filePath;
            encoder.outFile = "data/compressed/adaptiveHuffman/userSample.huf";
            encoder.Encode();
        }
        else 
            cout << "Invalid!.\n";
    }
    else
        cout << "Invalid!.\n";
}

void processChoice2() {
    int choice, algo;
    cout << "Choose file to decode:\n";
    cout << "1. a.txt: contains only one character 'a'.\n";
    cout << "2. aaa.txt: contains 100.000 character 'a'.\n";
    cout << "3. alphabet.txt: contains 100.000 repeating alphabet characters.\n";
    cout << "4. random.txt: contains 100.000 random characters.\n";
    cout << "5. user-selected file.\n";
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "Choose compress algorithm:\n";
    cout << "1. Static Huffman Coding.\n";
    cout << "2. Adaptive Huffman Coding.\n";
    cout << "Enter your choice: ";
    cin >> algo;

    if (algo == 1) {
            if (choice == 1) {
            HuffmanDecoder decoder("data/compressed/staticHuffman/a.huf", "data/result/staticHuffman/result_a.txt");
            decoder.decode();
        }
        else if (choice == 2) {
            HuffmanDecoder decoder("data/compressed/staticHuffman/aaa.huf", "data/result/staticHuffman/result_aaa.txt");
            decoder.decode();
        }
        else if (choice == 3) {
            HuffmanDecoder decoder("data/compressed/staticHuffman/alphabet.huf", "data/result/staticHuffman/result_alphabet.txt");
            decoder.decode();
        }
        else if (choice == 4) {
            HuffmanDecoder decoder("data/compressed/staticHuffman/random.huf", "data/result/staticHuffman/result_random.txt");
            decoder.decode();
        }
        else if (choice == 5) {
            HuffmanDecoder decoder("data/compressed/staticHuffman/userSample.huf", "data/result/staticHuffman/result_userSample.txt");
            decoder.decode();
        }
        else 
            cout << "Invalid!.\n";
    }
    else if (algo == 2) {
        AdaptiveHuffmanCoding decoder;
        if (choice == 1) {
            decoder.inpFile = "data/compressed/adaptiveHuffman/a.huf";
            decoder.outFile = "data/result/adaptiveHuffman/result_a.txt";
            decoder.Decode();
        }
        else if (choice == 2) {
            decoder.inpFile = "data/compressed/adaptiveHuffman/aaa.huf";
            decoder.outFile = "data/result/adaptiveHuffman/result_aaa.txt";
            decoder.Decode();
        }
        else if (choice == 3) {
            decoder.inpFile = "data/compressed/adaptiveHuffman/alphabet.huf";
            decoder.outFile = "data/result/adaptiveHuffman/result_alphabet.txt";
            decoder.Decode();
        }
        else if (choice == 4) {
            decoder.inpFile = "data/compressed/adaptiveHuffman/random.huf";
            decoder.outFile = "data/result/adaptiveHuffman/result_random.txt";
            decoder.Decode();
        }
        else if (choice == 5) {
            decoder.inpFile = "data/compressed/adaptiveHuffman/userSample.huf";
            decoder.outFile = "data/result/adaptiveHuffman/result_userSample.txt";
            decoder.Decode();
        }
        else 
            cout << "Invalid!\n";
    }
    else
        cout << "Invalid!\n";
}

void processChoice3() {
    int choice, algo;
    cout << "Choose file to encode:\n";
    cout << "1. a.txt: contains only one character 'a'.\n";
    cout << "2. aaa.txt: contains 100.000 character 'a'.\n";
    cout << "3. alphabet.txt: contains 100.000 repeating alphabet characters.\n";
    cout << "4. random.txt: contains 100.000 random characters.\n";
    cout << "5. user-selected file.\n";
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "Choose compress algorithm:\n";
    cout << "1. Static Huffman Coding.\n";
    cout << "2. Adaptive Huffman Coding.\n";
    cout << "Enter your choice: ";
    cin >> algo;

    cout << "Enter the number of executions to calculate the average execution time: ";
    int times;
    cin >> times;

    if (algo == 1) {
        if (choice == 1) {
            HuffmanEncoder encoder("data/TheArtificialCorpus/a.txt", "data/compressed/staticHuffman/a.huf");
            encoder.encodeAndMeasure("data/TheArtificialCorpus/a.txt", times);
        }
        else if (choice == 2) {
            HuffmanEncoder encoder("data/TheArtificialCorpus/aaa.txt", "data/compressed/staticHuffman/aaa.huf");
            encoder.encodeAndMeasure("data/TheArtificialCorpus/aaa.txt", times);
        }
        else if (choice == 3) {
            HuffmanEncoder encoder("data/TheArtificialCorpus/alphabet.txt", "data/compressed/staticHuffman/alphabet.huf");
            encoder.encodeAndMeasure("data/TheArtificialCorpus/alphabet.txt", times);
        }
        else if (choice == 4) {
            HuffmanEncoder encoder("data/TheArtificialCorpus/random.txt", "data/compressed/staticHuffman/random.huf");
            encoder.encodeAndMeasure("data/TheArtificialCorpus/random.txt", times);
        }
        else if (choice == 5) {
            string filePath;
            cout << "Enter file path: ";
            cin >> filePath;
            HuffmanEncoder encoder(filePath, "data/compressed/staticHuffman/userSample.huf");
            encoder.encodeAndMeasure(filePath, times);
        }
        else 
            cout << "Invalid!\n";
    }
    else if (algo == 2) {
        AdaptiveHuffmanCoding encoder;
        if (choice == 1) {
            encoder.EncodeAndMeasure("data/TheArtificialCorpus/a.txt", times);
        }
        else if (choice == 2) {
            encoder.EncodeAndMeasure("data/TheArtificialCorpus/aaa.txt", times);
        }
        else if (choice == 3) {
            encoder.EncodeAndMeasure("data/TheArtificialCorpus/alphabet.txt", times);
        }
        else if (choice == 4) {
            encoder.EncodeAndMeasure("data/TheArtificialCorpus/random.txt", times);
        }
        else if (choice == 5) {
            string filePath;
            cout << "Enter file path: ";
            cin >> filePath;
            encoder.EncodeAndMeasure(filePath, times);
        }
        else 
            cout << "Invalid!\n";
    }
    else
        cout << "Invalid!.\n";
}

void processChoice4() {
    int choice, algo;
    cout << "Choose file to decode:\n";
    cout << "1. a.txt: contains only one character 'a'.\n";
    cout << "2. aaa.txt: contains 100.000 character 'a'.\n";
    cout << "3. alphabet.txt: contains 100.000 repeating alphabet characters.\n";
    cout << "4. random.txt: contains 100.000 random characters.\n";
    cout << "5. user-selected file.\n";
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "Choose compress algorithm:\n";
    cout << "1. Static Huffman Coding.\n";
    cout << "2. Adaptive Huffman Coding.\n";
    cout << "Enter your choice: ";
    cin >> algo;

    cout << "Enter the number of executions to calculate the average execution time: ";
    int times;
    cin >> times;

    if (algo == 1) {
        if (choice == 1) {
            HuffmanDecoder decoder("data/compressed/staticHuffman/a.huf", "data/result/staticHuffman/result_a.txt");
            decoder.decodeAndMeasure("data/compressed/staticHuffman/a.huf", times);
        }
        else if (choice == 2) {
            HuffmanDecoder decoder("data/compressed/staticHuffman/aaa.huf", "data/result/staticHuffman/result_aaa.txt");
            decoder.decodeAndMeasure("data/compressed/staticHuffman/aaa.huf", times);
        }
        else if (choice == 3) {
            HuffmanDecoder decoder("data/compressed/staticHuffman/alphabet.huf", "data/result/staticHuffman/result_alphabet.txt");
            decoder.decodeAndMeasure("data/compressed/staticHuffman/alphabet.huf", times);
        }
        else if (choice == 4) {
            HuffmanDecoder decoder("data/compressed/staticHuffman/random.huf", "data/result/staticHuffman/random.txt");
            decoder.decodeAndMeasure("data/compressed/staticHuffman/random.huf", times);
        }
        else if (choice == 5) {
            HuffmanDecoder decoder("data/compressed/staticHuffman/userSample.huf", "data/result/staticHuffman/result_userSample.txt");
            decoder.decodeAndMeasure("data/compressed/staticHuffman/userSample.huf", times);
        }
        else 
            cout << "Invalid!\n";
    }
    else if (algo == 2) {
        AdaptiveHuffmanCoding decoder;
        if (choice == 1) {
            decoder.DecodeAndMeasure("data/compressed/adaptiveHuffman/a.huf", times);
        }
        else if (choice == 2) {
            decoder.DecodeAndMeasure("data/compressed/adaptiveHuffman/aaa.huf", times);
        }
        else if (choice == 3) {
            decoder.DecodeAndMeasure("data/compressed/adaptiveHuffman/alphabet.huf", times);
        }
        else if (choice == 4) {
            decoder.DecodeAndMeasure("data/compressed/adaptiveHuffman/random.huf", times);
        }
        else if (choice == 5) {
            decoder.DecodeAndMeasure("data/compressed/adaptiveHuffman/userSample.huf", times);
        }
        else 
        cout << "Invalid!.\n";
        
    }
    else 
        cout << "Invalid!\n";
}