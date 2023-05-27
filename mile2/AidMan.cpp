/*
    ==================================================
    Milestone 2: OOP244ZDD
    ==================================================
    Name   : Tejinder Singh
    ID     : 129121216
    Email  : ktejinder-singh@myseneca.ca
    Section: ZDD*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
#include "AidMan.h"
#include "Utils.h"
#include "Date.h"

namespace sdds
{
    AidMan::AidMan() : m_mainMenu(7, "1- List Items\n2- Add Item\n3- Remove Item\n4- Update Quantity\n5- Sort\n6- Ship Items\n7- New/Open Aid Database\n---------------------------------\n") {}

    AidMan::~AidMan() {
        delete[] m_file;

    }
    unsigned AidMan::menu() const {
        Date D;
        std::cout << "Aid Management System Version 0.1\n";
        std::cout << "Date: " << D << "\n";
        std::cout << "Data file: " << (m_file != nullptr ? m_file : "No file");
        std::cout << "\n---------------------------------\n";

        int Rst = m_mainMenu.run();

        return Rst;

    }
    void AidMan::run() {
        bool complete = false;
        do {
            int Mnu_Vl = menu();
            switch (Mnu_Vl) {
            case 0:
                complete = true;
                break;
            case 1:
                std::cout << "\n****List Items****\n\n";
                break;
            case 2:
                std::cout << "\n****Add Item****\n\n";
                break;
            case 3:
                std::cout << "\n****Remove Item****\n\n";
                break;
            case 4:
                std::cout << "\n****Update Quantity****\n\n";
                break;
            case 5:
                std::cout << "\n****Sort****\n\n";
                break;
            case 6:
                std::cout << "\n****Ship Items****\n\n";
                break;
            case 7:
                std::cout << "\n****New/Open Aid Database****\n\n";
                break;

            }

        } while (!complete);
        std::cout << "Exiting Program!\n";

    }
}
