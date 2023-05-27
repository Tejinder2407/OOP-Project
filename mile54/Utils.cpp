/* Citation and Sources...
Final Project Milestone 2
Module : Utils
Filename: Utils.cpp
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
#include <iostream>
#include <ctime>
#include "Utils.h"
#include <iomanip>

using namespace std;
namespace sdds {
    Utils ut;
    void Utils::testMode(bool testmode) {
        m_testMode = testmode;
    }
    void Utils::getSystemDate(int* year, int* mon, int* day) {
        if (m_testMode) {
            if (day) *day = sdds_testDay;
            if (mon) *mon = sdds_testMon;
            if (year) *year = sdds_testYear;
        }
        else {
            time_t t = std::time(NULL);
            tm lt = *localtime(&t);
            if (day) *day = lt.tm_mday;
            if (mon) *mon = lt.tm_mon + 1;
            if (year) *year = lt.tm_year + 1900;
        }
    }
    int Utils::daysOfMon(int month, int year)const {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = (month >= 1 && month <= 12 ? month : 13) - 1;
        return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }

    // User Defined
    unsigned int Utils::getIntegerWithRange(unsigned int maxValue, unsigned int minValue, std::istream& istr) {
        bool keepAsking = true;
        unsigned int returnValue;
        do {
            double Number;
            char a;
            if (istr.peek() == '\n')
            {
                // Did not enter anything.
                cout << "Invalid Integer, retry: ";
                // Clearing buffer..
                istr.get();

            }
            else if (istr.peek() == ' ') {
                // Started with space
                cout << "Invalid Integer, retry: ";
                // Clear buffer
                while (istr.get() != '\n') {

                };
            }
            else
            {
                // User entered something.
                istr >> Number;
                if (istr.fail())
                {
                    // Did not enter a number.
                    istr.clear();
                    cout << "Invalid Integer, retry: ";

                    while (istr.get() != '\n')
                    {
                        // clearing the buffer...
                    };

                }
                else
                {
                    a = istr.get();
                    if (a == '\n')
                    {

                        // It's a number.
                        if (Number >= minValue && Number <= maxValue)
                        {
                            // Right Integer. 
                            keepAsking = false;
                            returnValue = Number;

                        }
                        else
                        {
                            // User entered out of range.
                            cout << "Value out of range [" << minValue << "<=val<=" << maxValue << "]: ";

                        };

                    }
                    else
                    {
                        // Not a number
                        cout << "Invalid Integer, retry: ";

                        // clear the buffer...
                        while (istr.get() != '\n')
                        {

                        };
                    };
                };

            };

        } while (keepAsking);

        return returnValue;

    };
    double Utils::getDoubleWithRange(double maxValue, double minValue, std::istream& istr) {

        bool keepAsking = true;
        double returnValue;
        do {
            double Number;
            char a;
            if (istr.peek() == '\n')
            {
                // Did not enter anything.
                cout << "Invalid number, retry: ";
                // Clearing buffer..
                istr.get();

            }
            else if (istr.peek() == ' ') {
                // Started with space
                cout << "Invalid number, retry: ";
                // Clear buffer
                while (istr.get() != '\n') {

                };
            }
            else
            {
                // User entered something.
                istr >> Number;
                if (istr.fail())
                {
                    // Did not enter a number.
                    istr.clear();
                    cout << "Invalid number, retry: ";

                    while (istr.get() != '\n')
                    {
                        // clearing the buffer...
                    };

                }
                else
                {
                    a = istr.get();
                    if (a == '\n')
                    {

                        // It's a number.
                        if (Number >= minValue && Number <= maxValue)
                        {
                            // Right Integer. 
                            keepAsking = false;
                            returnValue = Number;

                        }
                        else
                        {
                            // User entered out of range.
                            cout << "Value out of range [" << fixed << setprecision(2) << minValue << "<=val<=" << fixed << setprecision(2) << maxValue << "]: ";

                        };

                    }
                    else
                    {
                        // Not a number
                        cout << "Invalid number, retry: ";

                        // clear the buffer...
                        while (istr.get() != '\n')
                        {

                        };
                    };
                };

            };

        } while (keepAsking);

        return returnValue;






    };


}
