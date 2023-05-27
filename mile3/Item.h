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
#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H
#include "iProduct.h"
#include "Status.h"
namespace sdds
{
    class Item : public iProduct
    {
        double m_price{};
        int m_quantity{};
        int m_needed{};
        char* m_desc{};
        bool m_isLinear{};

    protected:
        Status m_state{};
        int m_sku{};
        bool linear() const;

    public:
        Item();
        Item(const Item& src);
        Item& operator=(const Item& src);
        ~Item();
        int qtyNeeded() const;
        int qty() const;
        operator double() const;
        operator bool() const;
        int operator-=(int qty);
        int operator+=(int qty);
        void linear(bool isLinear);
        void clear();
        bool operator==(int sku) const;
        bool operator==(const char* description) const;
        int readSku(std::istream& istr);
        std::ofstream& save(std::ofstream& ofstr) const;
        std::ifstream& load(std::ifstream& ifstr);
        std::ostream& display(std::ostream& ostr) const;
        std::istream& read(std::istream& istr);
    };
}

#endif