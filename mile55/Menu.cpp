/*
    ==================================================
    Milestone 5: OOP244ZDD
    ==================================================
    Name   : Tejinder Singh
    ID     : 129121216
    Email  : ktejinder-singh@myseneca.ca
    Section: ZDD
*/

#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include <iostream>
#include <cstring>
using namespace std;
namespace sdds {

    // Default Constructor
    Menu::Menu() {
        setEmpty();
    };

    // 2 Argument Conctructor
    Menu::Menu(const char* MenuContext, unsigned int NumberOptions) {
        if (NumberOptions <= 15 && NumberOptions >= 1 && MenuContext != nullptr && strlen(MenuContext) > 0) {
            noOfOptions = NumberOptions;
            menuContext = new char[strlen(MenuContext) + 1];
            strcpy(menuContext, MenuContext);

        }
        else {
            // Set Empty
            setEmpty();
        };


    };

    // Destructor
    Menu::~Menu() {
        delete[] menuContext;

    };

    // setEmpty
    void Menu::setEmpty() {
        menuContext = nullptr;
        noOfOptions = -1;

    };

    // run
    unsigned int Menu::run() const {
        cout << menuContext;
        cout << "0- Exit" << endl;
        cout << "> ";
        unsigned int optionNumber = ut.getIntegerWithRange(noOfOptions);
        return optionNumber;

    };

    void Menu::set(const char* MenuContext, unsigned int NumberOptions) {
        delete[] menuContext;
        menuContext = new char[strlen(MenuContext) + 1];
        strcpy(menuContext, MenuContext);
        noOfOptions = NumberOptions;
    };


}