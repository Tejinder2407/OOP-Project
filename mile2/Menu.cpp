/*
    ==================================================
    Milestone 2: OOP244ZDD
    ==================================================
    Name   : Tejinder Singh
    ID     : 129121216
    Email  : ktejinder-singh@myseneca.ca
    Section: ZDD*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string.h>
#include "Menu.h"
#include "Utils.h"

namespace sdds
{

    Menu::Menu(unsigned noItems, const char* items)
    {
        if (!(noItems > 15 || items == nullptr))
        {
            m_items = new char[strlen(items) + 1];
            strcpy(m_items, items);
            m_noItems = noItems;
        }
    }
    Menu::~Menu()
    {
        delete[] m_items;
    }
    unsigned Menu::run() const
    {
        unsigned result{ 0 };
        std::cout << m_items;
        std::cout << "0- Exit\n> ";
        result = ut.getint(0, m_noItems);
        return result;
    }
}