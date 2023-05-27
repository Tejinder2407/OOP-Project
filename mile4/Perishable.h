/* Citation and Sources...
Final Project Milestone 2
Module : Perishable
Filename: Perishable.h
Version 1.0
Author: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Date      Reason
2022/02/28  Preliminary release
2022/02/28  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
/*
    ==================================================
    Milestone 4 (Part-2): OOP244ZDD
    ==================================================
    Name   : Tejinder Singh
    ID     : 129121216
    Email  : ktejinder-singh@myseneca.ca
    Section: ZDD
*/
#ifndef SDDS_PERISHABLE_H
#define SDDS_PERISHABLE_H
#include "Date.h"
#include "Item.h"
#include <iostream>
namespace sdds {
    class Perishable : public Item {

    private:
        Date m_expiry;
        char* handlingInstructions;
    public:
        // Constructor
        Perishable();
        // Rule of three
        // Destructor
        ~Perishable();
        // Copy Constructor
        Perishable(const Perishable& src);
        // Copy Assignement operator
        Perishable& operator=(const Perishable& src);
        // Query
        const Date& expiry() const;
        // Input/Output Overrides.
        // Save
        std::ofstream& save(std::ofstream& ofstr)const;
        // Load
        std::ifstream& load(std::ifstream& ifstr);
        // Display
        std::ostream& display(std::ostream& ostr)const;
        // ReadSku
        int readSku(std::istream& istr);
        // Read
        std::istream& read(std::istream& istr);

        operator bool() const;
    };




}
#endif // !SDDS_HealthCard_H


