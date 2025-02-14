#include <iostream>
#include <filesystem>
#include <map>

namespace fs = std::filesystem;

void organizeFiles(const std::string& directoryPath) {
    // Define file categories based on extensions
    std::map<std::string, std::string> fileCategories = {
        {".txt", "Documents"},
        {".pdf", "Documents"},
        {".docx", "Documents"},
        {".png", "Images"},
        {".jpg", "Images"},
        {".jpeg", "Images"},
        {".mp4", "Videos"},
        {".mkv", "Videos"},
        {".mp3", "Music"},
        {".cpp", "Code"},
        {".py", "Code"},
        {".exe", "Executables"},
        {".zip", "Archives"},
        {".rar", "Archives"}
    };

    // Ensure the provided path is a valid directory
    if (!fs::exists(directoryPath) || !fs::is_directory(directoryPath)) {
        std::cerr << "Invalid directory path!" << std::endl;
        return;
    }

    // Iterate over files in the directory
    for (const auto& entry : fs::directory_iterator(directoryPath)) {
        if (fs::is_regular_file(entry)) {
            std::string filePath = entry.path().string();
            std::string extension = entry.path().extension().string();

            // Check if file extension has a category
            if (fileCategories.find(extension) != fileCategories.end()) {
                std::string categoryFolder = directoryPath + "/" + fileCategories[extension];

                // Create category folder if it doesn't exist
                if (!fs::exists(categoryFolder)) {
                    fs::create_directory(categoryFolder);
                }

                // Move file to the corresponding folder
                std::string newFilePath = categoryFolder + "/" + entry.path().filename().string();
                fs::rename(filePath, newFilePath);
                std::cout << "Moved: " << filePath << " -> " << newFilePath << std::endl;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    // Ensure user provides a directory path
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <directory_path>" << std::endl;
        return 1;
    }

    std::string directoryPath = argv[1];
    organizeFiles(directoryPath);

    return 0;
}