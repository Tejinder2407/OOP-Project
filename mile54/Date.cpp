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
    Milestone 5: OOP244ZDD
    ==================================================
    Name   : Tejinder Singh
    ID     : 129121216
    Email  : ktejinder-singh@myseneca.ca
    Section: ZDD
*/

#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
namespace sdds {

    int maxYearValue = 2030;
    bool Date::validate() {
        bool dateValid = false;
        //Check
        int currentYear;
        ut.testMode(false);
        ut.getSystemDate(&currentYear);

        if (year >= currentYear && year <= maxYearValue) {
            // Year Valid
            // Check Month
            if (month >= 1 && month <= 12) {
                // month valid
                // check date
                int daysInMonth = ut.daysOfMon(month, year);
                if (day >= 1 && day <= daysInMonth) {
                    // day Valid
                    // everythingValid
                    status.clear();
                    dateValid = true;
                }
                else {
                    status.set("Invalid day in date", 3);

                };
            }
            else {
                // Month Invalid
                status.set("Invalid month in date", 2);

            };

        }
        else {
            // Year Invalid.
            status.set("Invalid year in date", 1);

        };

        return dateValid;
    };

    // Unique Date Value.
    int Date::uniqueDateValue() const {
        int uni_vlu = year * 372 + month * 31 + day;
        return uni_vlu;

    };

    // Constructors
    // No argument
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
        bool isEqual;
        if (uniqueDateValue() == date.uniqueDateValue()) {
            isEqual = true;

        }
        else {

            isEqual = false;
        };

        return isEqual;


    };

    bool Date::operator!=(const Date& date) const {
        bool isNotEqual;
        if (uniqueDateValue() != date.uniqueDateValue()) {
            isNotEqual = true;
        }
        else {
            isNotEqual = false;

        };


        return isNotEqual;
    };

    bool Date::operator>(const Date& date) const {
        bool isGreater;
        if (uniqueDateValue() > date.uniqueDateValue()) {
            isGreater = true;

        }
        else {
            isGreater = false;

        };

        return isGreater;
    };

    bool Date::operator<(const Date& date) const {
        bool isLess;
        if (uniqueDateValue() < date.uniqueDateValue()) {
            isLess = true;

        }
        else {
            isLess = false;
        };
        return isLess;
    };

    bool Date::operator>=(const Date& date) const {
        bool isGreaterEqual;
        if (uniqueDateValue() >= date.uniqueDateValue()) {
            isGreaterEqual = true;

        }
        else {
            isGreaterEqual = false;

        };
        return isGreaterEqual;
    };

    bool Date::operator<=(const Date& date) const {
        bool isLessEqual;
        if (uniqueDateValue() <= date.uniqueDateValue()) {
            isLessEqual = true;

        }
        else {

            isLessEqual = false;
        };
        return isLessEqual;

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
        int dateEntered;
        istr >> dateEntered;
        if (istr.fail()) {
            status.set("Invalid date value");
            // istr.setstate(ios::failbit);
        }
        else {
            // determinig number of digits
            double x1 = (double)dateEntered / 1000000;

            if (x1 >= 0.1) {
                // 6 digit
                int tempYear = dateEntered / 10000;

                year = tempYear + 2000;
                int remain = dateEntered - (tempYear * 10000);

                int tempMonth = remain / 100;
                month = tempMonth;
                int remain2 = remain - (tempMonth * 100);
                day = remain2;

            }
            else if (x1 >= 0.001) {
                // 4 digit
                ut.testMode(true);
                ut.getSystemDate(&year);
                int tempMonth = (double)dateEntered / 100;
                month = tempMonth;
                int remain2 = dateEntered - (tempMonth * 100);
                day = remain2;
            }
            else {
                // 2 digit
                ut.testMode(true);
                ut.getSystemDate(&year);
                month = 0;
                day = dateEntered;

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
        int tp_yr = dateSet / 10000;

        year = tp_yr + 2000;
        int remain = dateSet - (tp_yr * 10000);

        int tempMonth = remain / 100;
        month = tempMonth;
        int remain2 = remain - (tempMonth * 100);
        day = remain2;



    };




}
