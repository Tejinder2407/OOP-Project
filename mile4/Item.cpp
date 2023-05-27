/* Citation and Sources...
Final Project Milestone 2
Module : Item
Filename: Item.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include "Item.h"
#include <cstring>
#include <iostream>
#include <fstream>
#include "Utils.h"
#include <iomanip>
using namespace std;
namespace sdds {

    

    bool Item::linear() const {
        return m_linear;

    };

   

    Item::Item() {
        
        m_price = 0;
        m_qty = 0;
        m_qtyNeeded = 0;
        m_sku = 0;
        m_linear = false;
        m_description = nullptr;
        
        m_state.set(nullptr);
    };

   
    Item::~Item() {
        delete[] m_description;

    };

   
    Item::Item(const Item& src) {
        m_price = src.m_price;
        m_qty = src.m_qty;
        m_qtyNeeded = src.m_qtyNeeded;
        m_sku = src.m_sku;
        m_linear = src.m_linear;

        if (src.m_description != nullptr) {
            m_description = new char[strlen(src.m_description) + 1];
            strcpy(m_description, src.m_description);
        }
        else {
            m_description = nullptr;
        };

        m_state.set(nullptr);
        m_state = src.m_state;
    };


    // Copy assignment operator
    Item& Item::operator=(const Item& src) {
        m_price = src.m_price;
        m_qty = src.m_qty;
        m_qtyNeeded = src.m_qtyNeeded;
        m_sku = src.m_sku;
        m_linear = src.m_linear;

        delete[] m_description;

        if (src.m_description != nullptr) {
            m_description = new char[strlen(src.m_description) + 1];
            strcpy(m_description, src.m_description);
        }
        else {
            m_description = nullptr;

        };

        m_state = src.m_state;
        return *this;
    };

    
    int Item::qtyNeeded()const {
        return m_qtyNeeded;


    };

    int Item::qty()const {
        return m_qty;

    };

    Item::operator double()const {
        return m_price;

    };

    Item::operator bool()const {
        return bool(m_state);

    };

  
    int Item::operator-=(int qty) {
        m_qty -= qty;

        return m_qty;
    };
    int Item::operator+=(int qty) {
        m_qty += qty;

        return m_qty;
    };
    void Item::linear(bool isLinear) {
        m_linear = isLinear;

    };

  
    void Item::clear() {
        m_state.clear();

    };

    
    bool Item::operator==(int sku)const {
        bool return_value;
        if (m_sku == sku) {
            return_value = true;

        }
        else {
            return_value = false;
        };
        return return_value;
    };

    bool Item::operator==(const char* description)const {
        bool return_value;
        if (m_description == nullptr || description == nullptr) {
            return_value = false;
        }
        else if (strstr(m_description, description) != NULL) {
            return_value = true;

        }
        else {
            return_value = false;
        };
        return return_value;

    };

   
    ofstream& Item::save(std::ofstream& ofstr)const {
        if (m_state) {
            

            ofstr << m_sku;
            ofstr << "\t";
            ofstr << m_description;
            ofstr << "\t";
            ofstr << m_qty;
            ofstr << "\t";
            ofstr << m_qtyNeeded;
            ofstr << "\t";
            ofstr << fixed << setprecision(2) << m_price;
        }
        else {
            
        };
        return ofstr;

    };

    
    ifstream& Item::load(std::ifstream& ifstr) {
        if (ifstr.peek() == EOF) {
            ifstr.get();
        }
        else {
            delete[] m_description;
            
            ifstr >> m_sku;

            ifstr.get();
            
            char tpDescription[1000] = "\0";
            int i = 0;
            while (ifstr.peek() != '\t') {
                tpDescription[i] = ifstr.get();
                i += 1;
            };

            m_description = new char[strlen(tpDescription) + 1];
            strcpy(m_description, tpDescription);

            ifstr.get();

          
            ifstr >> m_qty;
            ifstr.get();
          
            ifstr >> m_qtyNeeded;
            ifstr.get();
           
            ifstr >> m_price;

            ifstr.get();


            if (ifstr.bad()) {
                m_state.set("Input file stream read failed!");

            };
        };
        return ifstr;
    };

   
    ostream& Item::display(std::ostream& ostr)const {
        if (m_linear == true) {
            ostr.fill(' ');
            ostr.width(5);
            ostr << m_sku;
            ostr << " | ";
            if (strlen(m_description) > 35) {
                for (int i = 0; i <= 34; i++) {
                    ostr << m_description[i];

                };
            }
            else {
                ostr.unsetf(ios::right);
                ostr.setf(ios::left);
                ostr.width(35);
                ostr << m_description;

            };

            ostr << " | ";
            ostr.width(4);
            ostr.setf(ios::right);
            ostr << m_qty;
            ostr << " | ";
            ostr.width(4);
            ostr << m_qtyNeeded;
            ostr << " | ";
            ostr.width(7);
            ostr << fixed << setprecision(2) << m_price;
            ostr << " |";
        }
        else {
            // descriptive
            ostr << "AMA Item:" << endl;
            ostr << m_sku << ": " << m_description << endl;
            ostr << "Quantity Needed: " << m_qtyNeeded << endl;
            ostr << "Quantity Available: " << m_qty << endl;
            ostr << "Unit Price: $" << fixed << setprecision(2) << m_price << endl;
            double needed_fund = (m_qtyNeeded - m_qty) * m_price;
            ostr << "Needed Purchase Fund: $" << fixed << setprecision(2) << needed_fund << endl;

        };

        return ostr;
    };

    // Read Sku
    int Item::readSku(std::istream& istr) {
        cout << "SKU: ";
        int sku = (int)ut.getIntegerWithRange(99999, 40000, istr);
        m_sku = sku;
        return m_sku;
    };

    // Read
    istream& Item::read(std::istream& istr) {
        delete[] m_description;
        (*this).clear();
        cout << "AMA Item:" << endl;
        cout << "SKU: " << m_sku << endl;
        cout << "Description: ";
        char tempDes[1000] = "\0";
        int i = 0;
        while (istr.peek() != '\n') {
            tempDes[i] = istr.get();
            i += 1;
        };
        m_description = new char[strlen(tempDes) + 1];
        strcpy(m_description, tempDes);
        istr.get();
        cout << "Quantity Needed: ";
        m_qtyNeeded = (int)ut.getIntegerWithRange(9999, 1, istr);
        cout << "Quantity On Hand: ";
        m_qty = (int)ut.getIntegerWithRange(m_qtyNeeded, 0, istr);
        cout << "Unit Price: $";
        m_price = ut.getDoubleWithRange(9999.0, 0.0, istr);
        if (istr.fail()) {
            m_state.set("Console entry failed!");
        };
        return istr;
    };

   
    void Item::setSku(int squ) {
        m_sku = squ;

    };

    void Item::setStatus(const char* Status) {
        m_state.set(Status);

    };

    void Item::printState(std::ostream& ostr) const {
        ostr << m_state;
    };
}
