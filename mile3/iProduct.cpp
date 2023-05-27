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
#include "iProduct.h"
namespace sdds {
    std::ostream& operator<<(std::ostream& os, const iProduct& i) {
        return i.display(os);
    }
    std::istream& operator>>(std::istream& is, iProduct& i) {
        return i.read(is);
    }

}