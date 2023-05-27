/*
    ==================================================
    Milestone 2: OOP244ZDD
    ==================================================
    Name   : Tejinder Singh
    ID     : 129121216
    Email  : ktejinder-singh@myseneca.ca
    Section: ZDD*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments

#ifndef SDDS_AIDMAN_H
#define SDDS_AIDMAN_H
#include "Menu.h"
namespace sdds
{
    class AidMan
    {

        char* m_file{};
        Menu m_mainMenu{};
        unsigned menu() const;

    public:
        AidMan();
        AidMan(const AidMan& src) = delete;
        AidMan& operator=(const AidMan& src) = delete;
        ~AidMan();
        void run();
    };

}
#endif