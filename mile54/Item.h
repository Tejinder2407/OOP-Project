/* Citation and Sources...
Final Project Milestone 2
Module : Item
Filename: Item.h
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
    Milestone 5: OOP244ZDD
    ==================================================
    Name   : Tejinder Singh
    ID     : 129121216
    Email  : ktejinder-singh@myseneca.ca
    Section: ZDD
*/


#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H
#include "Status.h"
#include "iProduct.h"
#include <iostream>
namespace sdds {
    class Item : public iProduct {
    private:
        double m_price;
        int m_qty;
        int m_qtyNeeded;
        char* m_description;
        bool m_linear;
    protected:
        Status m_state;
        int m_sku;
        bool linear() const;
    public:
        // Constructor
        Item();
        // Rule of three.
        // Destructor
        ~Item();
        // Copy Constructor
        Item(const Item& src);
        // Copy Assignment Operator
        Item& operator=(const Item& src);
        // Public Query Overrides.
        int qtyNeeded()const;
        int qty()const;
        operator double()const;
        // returns if the iProduct is in a good state
        operator bool()const;



        // Public modifier overrides.
        int operator-=(int qty);
        int operator+=(int qty);
        void linear(bool isLinear);

        // Public modifier.
        void clear();
        // ==
        bool operator==(int sku)const;
        bool operator==(const char* description)const;

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

        // set sku
        void setSku(int squ);
        // set status
        void setStatus(const char* Status);
        void printState(std::ostream& ostr) const;
        operator const char* () const;
        operator int() const;
    };




}
#endif // !SDDS_HealthCard_H


