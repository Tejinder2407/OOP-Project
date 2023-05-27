/*
    ==================================================
    Milestone 2: OOP244ZDD
    ==================================================
    Name   : Tejinder Singh
    ID     : 129121216
    Email  : ktejinder-singh@myseneca.ca
    Section: ZDD*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>

namespace sdds {



    class Menu {
        char* m_items{};
        unsigned m_noItems{};
    public:
        Menu(unsigned noItems = 0, const char* items = nullptr);
        Menu(const Menu& src) = delete;
        Menu& operator=(const Menu& src) = delete;
        ~Menu();
        unsigned run() const;


    };

}


#endif