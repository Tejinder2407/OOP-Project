/* Citation and Sources...
Final Project Milestone 2
Module : iProduct
Filename: iProduct.cpp
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
#include "iProduct.h"

namespace sdds {

    // Destructor
    iProduct::~iProduct() {


    };

    
    std::ostream& operator<<(std::ostream& os, const iProduct& product) {

        return product.display(os);


    };

    std::istream& operator>>(std::istream& istr, iProduct& product) {

        return product.read(istr);

    };


}