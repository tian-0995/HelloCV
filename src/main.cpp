#include "Menu.h"
#include <iostream>

int main() {
    int choice = 0;
    
    do {
        Menu::showMainMenu();
        choice = Menu::getIntInput("");
        Menu::handleChoice(choice);
    } while (choice != 5);
    
    return 0;
}
