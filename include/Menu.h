#ifndef MENU_H
#define MENU_H
#include <string>
class Menu {
public:
    static void showMainMenu();
    static void handleChoice(int choice);
    static void textEncryptionMenu();
    static void textDecryptionMenu();
    static void fileEncryptionMenu();
    static void fileDecryptionMenu();
    static int getIntInput(const std::string& prompt);
    static std::string getStringInput(const std::string& prompt);
};

#endif
