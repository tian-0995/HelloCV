#ifndef CRYPTO_H
#define CRYPTO_H
#include <string>
class Crypto {
public:
    static std::string encryptText(const std::string& text, int key);
    static std::string decryptText(const std::string& text, int key);
    static std::string xorEncrypt(const std::string& text, const std::string& key);
    static std::string xorDecrypt(const std::string& text, const std::string& key);
private:
    static char caesarEncryptChar(char c, int key);
    static char caesarDecryptChar(char c, int key);
    static bool isAlpha(char c);
};

#endif
