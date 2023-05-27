/*
    ==================================================
    Milestone 3: OOP244ZDD
    ==================================================
    Name   : Tejinder Singh
    ID     : 129121216
    Email  : ktejinder-singh@myseneca.ca
    Section: ZDD
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
#include <iostream>
#include <string>
#include <fstream>
#include "Item.h"
#include "Utils.h"
#include <cstring>

namespace sdds
{
    bool Item::linear() const {
        return m_isLinear;
    }

    Item::Item() {}
    Item::Item(const Item& src) {
        *this = src;
    }
    Item& Item::operator=(const Item& src) {

        if (this != &src) {
            ut.alocpy(m_desc, src.m_desc);
            m_price = src.m_price;
            m_quantity = src.m_quantity;
            m_needed = src.m_needed;
            m_isLinear = src.m_isLinear;

        }
        return *this;
    }
    Item::~Item() {
        delete[] m_desc;

    }
    int Item::qtyNeeded() const {
        return m_needed;
    }
    int Item::qty() const {
        return m_quantity;
    }
    Item::operator double() const {
        return m_price;
    }
    Item::operator bool() const {
        return m_state.operator bool();
    }
    int Item::operator-=(int qty) {
        m_quantity -= qty;
        return m_quantity;

    }
    int Item::operator+=(int qty) {
        m_quantity += qty;
        return m_quantity;

    }
    void Item::linear(bool isLinear) {
        m_isLinear = isLinear;

    }
    void Item::clear() {
        m_state.clear();

    }
    bool Item::operator==(int sku) const {
        return m_sku == sku;

    }
    bool Item::operator==(const char* description) const {
        return description && m_desc && strstr(m_desc, description) != nullptr;

    }
    int Item::readSku(std::istream& istr) {
        std::cout << "SKU: ";
        m_sku = ut.getint(40000, 99999);

        return m_sku;

    }
    std::ofstream& Item::save(std::ofstream& ofstr) const {

        if (*this) {
            ofstr << '\n' << m_sku << '\t' << m_desc << '\t' << m_quantity << '\t' << m_needed << '\t';
            ofstr.setf(std::ios::fixed);
            ofstr.precision(2);
            ofstr << m_price;
        }
        return ofstr;

    }
    std::ifstream& Item::load(std::ifstream& ifstr) {
        std::string tp;
        ifstr >> m_sku;
        ifstr.ignore();
        getline(ifstr, tp, '\t');
        if (tp != "") {
            ut.alocpy(m_desc, tp.c_str());
        }
        ifstr >> m_quantity;
        ifstr.ignore();
        ifstr >> m_needed;
        ifstr.ignore();
        ifstr >> m_price;
        ifstr.ignore();
        if (!ifstr) {
            m_state = "Input file stream read failed!";
        }
        return ifstr;

    }
    std::ostream& Item::display(std::ostream& ostr) const {
        if (*this) {
            if (m_isLinear) {
                ostr << m_sku << " | ";
                ostr.width(35);
                ostr.setf(std::ios::left);
                if (strlen(m_desc) > 35) {
                    ostr << std::string(m_desc).substr(0, 35) << " | ";
                }
                else {
                    ostr << m_desc << " | ";
                }
                ostr.unsetf(std::ios::left);
                ostr.width(4);
                ostr.setf(std::ios::right);
                ostr << m_quantity << " | ";
                ostr.width(4);
                ostr << m_needed << " | ";
                ostr.width(7);
                ostr.setf(std::ios::fixed);
                ostr.precision(2);
                ostr << m_price << " |";
                ostr.unsetf(std::ios::right);
                ostr.unsetf(std::ios::fixed);

            }
            else {
                ostr << "AMA Item:" << std::endl;
                ostr << m_sku << ": " << m_desc << std::endl;
                ostr << "Quantity Needed: " << m_needed << std::endl;
                ostr << "Quantity Available: " << m_quantity << std::endl;
                ostr << "Unit Price: $";
                ostr.setf(std::ios::fixed);
                ostr.precision(2);
                ostr << m_price << std::endl;
                ostr << "Needed Purchase Fund: $";
                ostr.precision(2);
                double vlu = (m_needed - m_quantity) * m_price;
                ostr << vlu << std::endl;

            }
        }
        else {
            ostr << m_state;
        }

        return ostr;

    }
    std::istream& Item::read(std::istream& istr) {
        delete[] m_desc;

        std::string tp;

        std::cout << "AMA Item:\n" << "SKU: " << m_sku << '\n';
        istr.ignore();
        std::cout << "Description: ";
        getline(istr, tp, '\n');
        if (tp != "") {
            ut.alocpy(m_desc, tp.c_str());
        }
        std::cout << "Quantity Needed: ";
        m_needed = ut.getint(1, 9999);
        std::cout << "Quantity On Hand: ";
        m_quantity = ut.getint(0, m_needed);
        std::cout << "Unit Price: $";
        m_price = ut.getdouble(0.0, 9999.0);
        if (!istr && !std::cin) {
            m_state = "Console Entry failed";
        }




        return istr;

    }
}