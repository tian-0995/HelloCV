#include "Crypto.h"
#include <cctype>

std::string Crypto::encryptText(const std::string& text, int key) {
    std::string result;
    for (char c : text) {
        result += caesarEncryptChar(c, key);
    }
    return result;
}

std::string Crypto::decryptText(const std::string& text, int key) {
    std::string result;
    for (char c : text) {
        result += caesarDecryptChar(c, key);
    }
    return result;
}

char Crypto::caesarEncryptChar(char c, int key) {
    if (!isAlpha(c)) {
        return c; 
    }
    
    char base = std::isupper(c) ? 'A' : 'a';
    return static_cast<char>((c - base + key) % 26 + base);
}

char Crypto::caesarDecryptChar(char c, int key) {
    if (!isAlpha(c)) {
        return c; 
    }
    
    char base = std::isupper(c) ? 'A' : 'a';
    return static_cast<char>((c - base - key + 26) % 26 + base);
}

bool Crypto::isAlpha(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

std::string Crypto::xorEncrypt(const std::string& text, const std::string& key) {
    std::string result = text;
    if (key.empty()) return result;
    
    for (size_t i = 0; i < text.length(); ++i) {
        result[i] = text[i] ^ key[i % key.length()];
    }
    return result;
}

std::string Crypto::xorDecrypt(const std::string& text, const std::string& key) {
    return xorEncrypt(text, key);
}
