/* Citation and Sources...
Final Project Milestone 2
Module : Date
Filename: Date.cpp
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


#include "Date.h"
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
namespace sdds {

    int maxYearValue = 2030;
    bool Date::validate() {
        bool date_valid = false;
       
        int current_year;
        ut.testMode(false);
        ut.getSystemDate(&current_year);

        if (year >= current_year && year <= maxYearValue) {
           
            if (month >= 1 && month <= 12) {
                
                int daysInMonth = ut.daysOfMon(month, year);
                if (day >= 1 && day <= daysInMonth) {
                    
                    status.clear();
                    date_valid = true;
                }
                else {
                    status.set("Invalid day in date", 3);

                };
            }
            else {
               
                status.set("Invalid month in date", 2);

            };

        }
        else {
           
            status.set("Invalid year in date", 1);

        };

        return date_valid;
    };

    // Unique Date Value.
    int Date::uniqueDateValue() const {
        int unique_value = year * 372 + month * 31 + day;
        return unique_value;

    };

    
    Date::Date() {

        ut.getSystemDate(&year, &month, &day);
        status.set(nullptr);
        format = true;



    };

    // If all three values are provided.
    Date::Date(int Year, int Month, int Day) {
        year = Year;
        month = Month;
        day = Day;
        status.set(nullptr);
        format = true;

        // Validating date
        validate();

    };

    // Destructor
    Date::~Date() {




    };


    bool Date::operator==(const Date& date) const {
        bool Equal;
        if (uniqueDateValue() == date.uniqueDateValue()) {
            Equal = true;

        }
        else {

            Equal = false;
        };

        return Equal;


    };

    bool Date::operator!=(const Date& date) const {
        bool NotEqual;
        if (uniqueDateValue() != date.uniqueDateValue()) {
            NotEqual = true;
        }
        else {
            NotEqual = false;

        };


        return NotEqual;
    };

    bool Date::operator>(const Date& date) const {
        bool Greater;
        if (uniqueDateValue() > date.uniqueDateValue()) {
            Greater = true;

        }
        else {
            Greater = false;

        };

        return Greater;
    };

    bool Date::operator<(const Date& date) const {
        bool Less;
        if (uniqueDateValue() < date.uniqueDateValue()) {
            Less = true;

        }
        else {
            Less = false;
        };
        return Less;
    };

    bool Date::operator>=(const Date& date) const {
        bool GreaterEqual;
        if (uniqueDateValue() >= date.uniqueDateValue()) {
            GreaterEqual = true;

        }
        else {
            GreaterEqual = false;

        };
        return GreaterEqual;
    };

    bool Date::operator<=(const Date& date) const {
        bool LessEqual;
        if (uniqueDateValue() <= date.uniqueDateValue()) {
            LessEqual = true;

        }
        else {

            LessEqual = false;
        };
        return LessEqual;

    };

    // State Accessor
    const Status& Date::state() {


        return status;
    };

    void Date::formatted(bool toFormat) {
        format = toFormat;

    };

    // Bool type conversion
    Date::operator bool() const {
        return (bool)status;

    };

    // write
    std::ostream& Date::write(std::ostream& os) const {
        if (format == true) {
            os << year << "/";
            os.fill('0');
            os.width(2);
            os << month;
            os << "/";
            os.width(2);
            os << day;
        }
        else {
            int yearPrint = year - 2000;

            os << yearPrint;
            os.fill('0');
            os.width(2);
            os << month;
            os.width(2);
            os << day;

        };



        return os;

    };

    //read
    std::istream& Date::read(std::istream& istr) {
        int date_entered;
        istr >> date_entered;
        if (istr.fail()) {
            status.set("Invalid date value");
            // istr.setstate(ios::failbit);
        }
        else {
            // determinig number of digits
            double x1 = (double)date_entered / 1000000;

            if (x1 >= 0.1) {
                // 6 digit
                int tempYear = date_entered / 10000;

                year = tempYear + 2000;
                int remain = date_entered - (tempYear * 10000);

                int tempMonth = remain / 100;
                month = tempMonth;
                int remain2 = remain - (tempMonth * 100);
                day = remain2;

            }
            else if (x1 >= 0.001) {
                // 4 digit
                ut.testMode(true);
                ut.getSystemDate(&year);
                int tempMonth = (double)date_entered / 100;
                month = tempMonth;
                int remain2 = date_entered - (tempMonth * 100);
                day = remain2;
            }
            else {
                // 2 digit
                ut.testMode(true);
                ut.getSystemDate(&year);
                month = 0;
                day = date_entered;

            };

            if (validate()) {

            }
            else {
                istr.setstate(ios::failbit);
            };

        };
        return istr;
    };






    // IO overloads
    std::ostream& operator<<(std::ostream& os, const Date& date) {
        return date.write(os);

    };

    std::istream& operator>>(std::istream& istr, Date& date) {
        return date.read(istr);

    };

    // set
    void Date::setEmpty() {
        year = 0;
        day = 0;
        month = 0;
        status.set(nullptr);
        format = true;


    };

    // Copy Assignment.
    Date& Date::operator=(const Date& src) {
        year = src.year;
        month = src.month;
        day = src.day;
        format = src.format;
        status = src.status;
        return *this;
    };

    // Writing date to file
    void Date::save(std::ofstream& ofstr)const {
        int yearPrint = year - 2000;

        ofstr << yearPrint;
        ofstr.fill('0');
        ofstr.width(2);
        ofstr << month;
        ofstr.width(2);
        ofstr << day;



    };

    // Setting Date.
    void Date::setDate(int dateSet) {
        int tempYear = dateSet / 10000;

        year = tempYear + 2000;
        int remain = dateSet - (tempYear * 10000);

        int tempMonth = remain / 100;
        month = tempMonth;
        int remain2 = remain - (tempMonth * 100);
        day = remain2;



    };




}
