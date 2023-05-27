/*
    ==================================================
    Milestone 5: OOP244ZDD
    ==================================================
    Name   : Tejinder Singh
    ID     : 129121216
    Email  : ktejinder-singh@myseneca.ca
    Section: ZDD
*/

#define _CRT_SECURE_NO_WARNINGS



#include "iProduct.h"

namespace sdds {

    // Destructor
    iProduct::~iProduct() {


    };

    // Insertion and Extraction operator
    std::ostream& operator<<(std::ostream& os, const iProduct& product) {

        return product.display(os);


    };

    std::istream& operator>>(std::istream& istr, iProduct& product) {

        return product.read(istr);

    };


}