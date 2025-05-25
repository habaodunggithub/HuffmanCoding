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

## 🛠️ Cách sử dụng
Di chuyển đường dẫn đến folder dự án và gõ câu lệnh sau trên cửa sổ dòng lệnh:

<pre> run.bat </pre>

Khi chạy, chương trình sẽ hiển thị Menu như sau:
```
1. Encode                                      # Nén tệp
2. Decode                                      # Giải nén tệp
3. Encode and measure average execution time   # Đo thời gian nén trung bình
4. Decode and measure average execution time   # Đo thời gian giải nén trung bình
5. Quit.                                       # Thoát chương trình  
```

> Đối với hàm các hàm decode, người dùng cần phải encode file đó trước khi tiến hành decode để tránh lỗi truy cập

1. Encode (Nén tệp)
- Chọn một trong các tệp mẫu có sẵn hoặc tự nhập đường dẫn tệp.

- Chọn thuật toán nén: Static Huffman hoặc Adaptive Huffman.

- Kết quả sẽ được lưu trong thư mục data/compressed/.

2. Decode (Giải nén tệp)
- Chọn một tệp đã nén tương ứng.

- Chọn thuật toán đã dùng để nén trước đó.

- Kết quả được lưu vào data/result/.

3. Encode and measure average execution time
- Tương tự mục (1) nhưng có thêm tùy chọn số lần chạy để tính thời gian trung bình nén.

4. Decode and measure average execution time
- Tương tự mục (2) nhưng có thêm tùy chọn số lần chạy để tính thời gian trung bình giải nén.

Nếu muốn mã hóa tập tin từ người dùng có thể chọn option `1`:
```
1. a.txt: contains only one character 'a'.
2. aaa.txt: contains 100.000 character 'a'.
3. alphabet.txt: contains 100.000 repeating alphabet characters.
4. random.txt: contains 100.000 random characters.
5. user-selected file.
```
Sau đó chọn `5` và nhập tên file. Với lựa chọn `user-selected file`, cần nhập đường dẫn chính xác đến tệp văn bản hoặc để cùng đường dẫn với folder dự án.

Khi muốn giải nén chọn option `2`, `5`, `1`  và quan sát kết quả ở folder data/result/.

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
