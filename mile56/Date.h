/* Citation and Sources...
Final Project Milestone 2
Module : Date
Filename: Date.h
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



#ifndef SDDS_DATE_H
#define SDDS_DATE_H
#include <iostream>
#include "Status.h"
#include "Utils.h"
namespace sdds {



    class Date {
        // Data Members.
        int year;
        int month;
        int day;
        Status status;
        bool format;

        // Private method
        bool validate();
        int uniqueDateValue() const;



    public:
        // Constructors
        Date();
        Date(int Year, int Month, int Day);

        // Destructor
        ~Date();

        // Operator Overloads.
        bool operator==(const Date& date) const;
        bool operator!=(const Date& date) const;
        bool operator<(const Date& date)  const;
        bool operator>(const Date& date)  const;
        bool operator<=(const Date& date) const;
        bool operator>=(const Date& date) const;

        // Copy Assignment 
        Date& operator=(const Date& src);

        // State accessor
        const Status& state();

        // Formatted modifier
        void formatted(bool toFormat);

        // bool conversion
        operator bool() const;

        // write
        std::ostream& write(std::ostream& os) const;
        //read
        std::istream& read(std::istream& istr);


        // set
        void setEmpty();

        // Writing date to file.  
        void save(std::ofstream& ofstr)const;

        // Set date

        void setDate(int dateSet);
        std::ofstream& write(std::ofstream& os) const;


    };

    // IO operators overloads.
    std::ostream& operator<<(std::ostream& os, const Date& date);
    std::istream& operator>>(std::istream& istr, Date& date);





}
#endif // !SDDS_HealthCard_H


