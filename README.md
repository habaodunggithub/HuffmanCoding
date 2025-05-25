# Huffman Coding

> Một dự án mã hóa và giải mã văn bản sử dụng thuật toán Huffman, được viết bằng C++ và quản lý bằng CMake.

---

## 🧠 Giới thiệu

Huffman Coding là một thuật toán nén không mất dữ liệu, thường được sử dụng để giảm dung lượng lưu trữ của văn bản. Dự án này hiện thực:

- Mã hóa văn bản (Encode)
- Giải mã văn bản (Decode)
- Đo thời gian thực thi trung bình
- Quản lý dữ liệu đầu vào/đầu ra tự động qua file

---

## 📁 Cấu trúc thư mục
HuffmanCoding/
├── build/                      # Thư mục chứa file build
├── data/                       # Thư mục chứa dữ liệu
│   ├── compressed/             # File đã được mã hóa
│   ├── result/                 # Kết quả giải mã
│   ├── temp/                   # File tạm dùng để đo thời gian
│   └── TheArtificialCorpus/    # Dữ liệu gốc
├── include/                    # Header files (.h)
│   ├── huffman.h
│   ├── minHeap.h
│   └── sideFunc.h
├── src/                        # Source code (.cpp)
│   ├── main.cpp
│   ├── huffman.cpp
│   ├── minHeap.cpp
│   ├── sideFunc.cpp
│   └── test.cpp
├── file_list.txt               # Danh sách file/dataset dùng để chạy
└── README.md                   # File mô tả dự án

## 🛠️ Cách build và chạy
```bash
cd HuffmanCoding
g++ src/huffman.cpp src/main.cpp src/minHeap.cpp src/sideFunc.cpp -o build/HuffmanCoding
build/HuffmanCoding.exe