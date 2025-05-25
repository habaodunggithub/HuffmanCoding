# Huffman Coding

> Một dự án mã hóa và giải mã văn bản sử dụng thuật toán Huffman viết bằng ngôn ngữ C++.

---

## 🧠 Giới thiệu

Huffman Coding là một thuật toán nén không mất dữ liệu, thường được sử dụng để giảm dung lượng lưu trữ của văn bản. Dự án này hiện thực:

- Mã hóa văn bản (Encode)
- Giải mã văn bản (Decode)
- Đo thời gian thực thi trung bình
- Quản lý dữ liệu đầu vào/đầu ra tự động qua file

---
## 📁 Cấu trúc thư mục
```
HuffmanCoding/
├── build/                    # Thư mục chứa dữ liệu đã lưu
├── data/                     # Thư mục chứa dữ liệu
│   ├── compressed/           # File đã được nén
│   │   ├── adaptiveHuffman/
│   │   └── staticHuffman/
│   ├── result/               # File kết quả sau khi nén
│   │   ├── adaptiveHuffman/
│   │   └── staticHuffman/
│   ├── temp/                 # File tạm dùng để hỗ trợ việc đo đạc thời gian
│   └── TheArtificialCorpus/  # Tập dữ liệu mẫu
├── include/                  # Header files (.h)
│   ├── AdaptiveHuffman.h
│   ├── huffman.h
│   ├── minHeap.h
│   ├── sideFunc.h
│   └── test.h
├── src/                      # Source code (.cpp)
│   ├── AdaptiveHuffman.cpp
│   ├── huffman.cpp
│   ├── main.cpp
│   ├── minHeap.cpp
│   ├── sideFunc.cpp
│   └── test.cpp
├── file_list.txt             # Danh sách file/dataset dùng để chạy
├── run.bat                   # File script chạy Lệnh chạy chương trình
└── README.md                 # File mô tả dự án
```

## 🛠️ Cách build và chạy
Di chuyển đường dẫn đến folder dự án và gõ câu lệnh sau:

<pre> run.bat </pre>

## Cách sử dụng

Đối với hàm các hàm decode, người dùng cần phải encode file đó trước khi tiến hành decode để tránh lỗi truy cập