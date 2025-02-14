# File Organizer

A simple **C++ program** that organizes files in a directory by categorizing them based on their extensions. It automatically moves files into subfolders like **Documents, Images, Videos, Code, Archives, and Executables**.

## Features
Uses **C++ std::filesystem** for file handling  
Automatically categorizes files based on extensions  
Creates directories dynamically if they don't exist  
Cross-platform support for **Windows, Linux, and macOS**  
Easy-to-use command-line tool  

## Installation
### Prerequisites
- C++ compiler supporting C++17 (e.g., **g++**, **MSVC**, **Clang**)

### Compile and Run
```sh
# Compile the program
 g++ file_organizer.cpp -o file_organizer -std=c++17

# Run the program
 ./file_organizer /path/to/directory
```

## Usage
1. Provide the directory path as a command-line argument.
2. The program will create folders based on file extensions.
3. Files are moved into respective folders automatically.

## Example
```
Input Directory: /Downloads
Files:
  - document.pdf  → Moved to /Downloads/Documents/
  - picture.jpg   → Moved to /Downloads/Images/
  - video.mp4     → Moved to /Downloads/Videos/
```

## Potential Improvements
🔹 **Support for user-defined categories**  
🔹 **Interactive mode for file sorting**  
🔹 **Logging feature to track moved files**  
