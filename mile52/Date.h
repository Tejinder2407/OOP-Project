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


    };

    // IO operators overloads.
    std::ostream& operator<<(std::ostream& os, const Date& date);
    std::istream& operator>>(std::istream& istr, Date& date);





}
#endif // !SDDS_HealthCard_H


