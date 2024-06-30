//
// Created by Toudonou on 6/29/2024.
//

#ifndef FILEUTILS_H
#define FILEUTILS_H
#include <fstream>
#include <iostream>
#include <string>

namespace sparky {
    class FileUtils {
    public:
        static std::string read_file(const std::string &filepath) {
            std::ifstream file(filepath);
            std::string line;
            std::string result;

            if (!file.is_open()) {
                std::cout << "Error during file opening : " << filepath << std::endl;
                return "";
            }

            while (getline(file, line)) result.append(line).append("\n");

            return result;
        }
    };
}

#endif //FILEUTILS_H
