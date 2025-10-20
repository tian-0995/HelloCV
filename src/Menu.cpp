#include "Menu.h"
#include "Crypto.h"
#include "FileHandler.h"
#include <iostream>
#include <limits>

void Menu::showMainMenu() {
    std::cout << "\n=== 简易文本加密解密工具 ===\n";
    std::cout << "1. 文本加密\n";
    std::cout << "2. 文本解密\n";
    std::cout << "3. 文件加密\n";
    std::cout << "4. 文件解密\n";
    std::cout << "5. 退出\n";
    std::cout << "请选择功能 (1-5): ";
}

void Menu::handleChoice(int choice) {
    switch (choice) {
        case 1:
            textEncryptionMenu();
            break;
        case 2:
            textDecryptionMenu();
            break;
        case 3:
            fileEncryptionMenu();
            break;
        case 4:
            fileDecryptionMenu();
            break;
        case 5:
            std::cout << "感谢使用\n";
            break;
        default:
            std::cout << "请重新输入\n";
    }
}

void Menu::textEncryptionMenu() {
    std::cout << "\n=== 文本加密 ===\n";
    
    std::string text = getStringInput("请输入要加密的文本: ");
    int key = getIntInput("请输入密钥 (整数): ");
    
    std::string encrypted = Crypto::encryptText(text, key);
    std::cout << "加密结果: " << encrypted << std::endl;
    
    std::string xorKey = getStringInput("请输入 XOR 加密密钥: ");
    std::string xorEncrypted = Crypto::xorEncrypt(text, xorKey);
    std::cout << "XOR 加密结果: " << xorEncrypted << std::endl;
}

void Menu::textDecryptionMenu() {
    std::cout << "\n=== 文本解密 ===\n";
    
    std::string text = getStringInput("请输入要解密的文本: ");
    int key = getIntInput("请输入密钥 (整数): ");
    
    std::string decrypted = Crypto::decryptText(text, key);
    std::cout << "解密结果: " << decrypted << std::endl;
    
    // XOR 解密
    std::string xorKey = getStringInput("请输入 XOR 解密密钥: ");
    std::string xorDecrypted = Crypto::xorDecrypt(text, xorKey);
    std::cout << "XOR 解密结果: " << xorDecrypted << std::endl;
}

void Menu::fileEncryptionMenu() {
    std::cout << "\n=== 文件加密 ===\n";
    
    std::string inputFile = getStringInput("请输入要加密的文件路径: ");
    
    if (!FileHandler::fileExists(inputFile)) {
        std::cout << "文件不存在\n";
        return;
    }
    
    try {
        std::string content = FileHandler::readFile(inputFile);
        int key = getIntInput("请输入密钥 (整数): ");
        
        std::string encrypted = Crypto::encryptText(content, key);
        std::string outputFile = "encrypted_" + inputFile;
        
        if (FileHandler::writeFile(outputFile, encrypted)) {
            std::cout << "加密结果已保存到: " << outputFile << std::endl;
        } else {
            std::cout << "保存文件失败！\n";
        }
    } catch (const std::exception& e) {
        std::cout << "错误: " << e.what() << std::endl;
    }
}

void Menu::fileDecryptionMenu() {
    std::cout << "\n=== 文件解密 ===\n";
    
    std::string inputFile = getStringInput("请输入要解密的文件路径: ");
    
    if (!FileHandler::fileExists(inputFile)) {
        std::cout << "文件不存在！\n";
        return;
    }
    
    try {
        std::string content = FileHandler::readFile(inputFile);
        int key = getIntInput("请输入密钥 (整数): ");
        
        std::string decrypted = Crypto::decryptText(content, key);
        std::string outputFile = "decrypted_" + inputFile;
        
        if (FileHandler::writeFile(outputFile, decrypted)) {
            std::cout << "解密结果已保存到: " << outputFile << std::endl;
        } else {
            std::cout << "保存文件失败！\n";
        }
    } catch (const std::exception& e) {
        std::cout << "错误: " << e.what() << std::endl;
    }
}

int Menu::getIntInput(const std::string& prompt) {
    int value;
    std::cout << prompt;
    while (!(std::cin >> value)) {
        std::cout << "输入无效，请输入整数: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(); 
    return value;
}

std::string Menu::getStringInput(const std::string& prompt) {
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    return input;
}
