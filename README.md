# Classical Cipher Algorithms

A C++ console application that demonstrates three classical cryptography techniques: Rail Fence Cipher, Vigenère Cipher, and Playfair Cipher.

## Project Overview

Classical Cipher Algorithms is a simple educational console project built to demonstrate how traditional encryption and decryption methods work. The application provides a text-based menu that lets users choose a cipher, enter input, and see the encrypted or decrypted result immediately.

The project is designed for students and beginners who want to understand the core ideas behind classical cryptography through clean, modular C++ code. Each cipher is implemented in a separate source file, making the code easier to read, test, and extend.

## Features

- Interactive menu-driven console interface
- Encryption and decryption support for three classical ciphers
- Separate source files for each algorithm
- Lightweight implementation using only standard C++ libraries
- Beginner-friendly structure for learning cryptography concepts

## Algorithms Used

### Rail Fence Cipher
A transposition cipher that arranges text in a zigzag pattern across multiple rows and then reads the rows sequentially to produce the ciphertext.

### Vigenère Cipher
A polyalphabetic substitution cipher that shifts each letter using a repeating keyword.

### Playfair Cipher
A digraph-based substitution cipher that encrypts letters in pairs using a 5×5 key matrix built from a keyword.

## Project Structure

```text
Classical Cipher Algorithms/
├── main.cpp
├── rail_fence.cpp
├── vignere.cpp
├── playfair.cpp
└── cipher
```

## Requirements

- C++ compiler with C++11 or later support
- Linux, macOS, or Windows
- Terminal or command prompt

## How to Compile

### Linux/macOS

```bash
g++ *.cpp -o cipher
./cipher
```

### Windows (MinGW)

```bash
g++ *.cpp -o cipher.exe
cipher.exe
```

## How to Use

1. Run the program.
2. Choose a cipher from the main menu:
   - `1` for Rail Fence Cipher
   - `2` for Vigenère Cipher
   - `3` for Playfair Cipher
   - `0` to exit
3. Select whether you want to encrypt or decrypt.
4. Enter the required values:
   - **Rail Fence Cipher:** plain text/cipher text and row count
   - **Vigenère Cipher:** plain text/cipher text and key
   - **Playfair Cipher:** plain text/cipher text and key
5. View the resulting encrypted or decrypted output on the screen.

### Notes

- The Rail Fence and Vigenère implementations remove spaces and convert text to lowercase before processing.
- The Playfair implementation also removes spaces and converts text to lowercase.
- For Vigenère, the key is repeated to match the length of the message.
- For Playfair, the key is used to generate a 5×5 matrix with `j` merged into `i`.

## Resources Used

This project uses only the C++ Standard Library.

References:

- https://www.geeksforgeeks.org/playfair-cipher-with-examples/
- https://www.geeksforgeeks.org/vigenere-cipher/
- https://www.geeksforgeeks.org/rail-fence-cipher-encryption-decryption/

## Future Improvements

- GUI version
- File encryption support
- Additional classical ciphers such as Caesar, Hill, and Columnar Transposition
- Better Playfair preprocessing for repeated letters and padding

## Author

- Name: Hrithik Dev Nath 
- Student ID: 0562310005101012
- Department: Computer Science and Engineering
- University: North East University Bangladesh

## Supervised By:
- [Muhammad Nadim](https://www.linkedin.com/in/muhammadnadim018/) 
  (Lecturer, Dept. of CSE @NEUB)

# CipherSuite
