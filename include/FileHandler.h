#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>

class FileHandler {
public:
    static std::string readFile(const std::string& filePath);
    static bool writeFile(const std::string& filePath, const std::string& content);
    static bool fileExists(const std::string& filePath);
};

#endif
