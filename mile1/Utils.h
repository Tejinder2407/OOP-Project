/*
    ==================================================
    Workshop #1 (Part-1): OOP244ZDD
    ==================================================
    Name   : Tejinder Singh
    ID     : 129121216
    Email  : ktejinder-singh@myseneca.ca
    Section: ZDD
*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H
#include <iostream>
#include<cstring>
namespace sdds {
    // Testing date values for application testing and debugging
    // these values must not change at submission time.
    const int sdds_testYear = 2022;
    const int sdds_testMon = 03;
    const int sdds_testDay = 31;
    class Utils {
        bool m_testMode = false;
    public:
        // this function will be used to get the current system date or the test date if m_testMode is true
        void getSystemDate(int* year = nullptr, int* mon = nullptr, int* day = nullptr);
        // this function will return the number of days in a month based on the year
        // 1<=mon<=12  year: four digit number (example: 2021)
        int daysOfMon(int mon, int year)const;
        // Puts the system date in test mode, where getSystemDate() function will return 2022, 03, 31
        // or whatever the three constant test dates are set to
        void testMode(bool testmode = true);
        void alocpy(char*& destination, const char* source);
        int getint(const char* prompt = nullptr);
        int getint(int min, int max, const char* prompt = nullptr, const char* errMes = nullptr);
    };
    extern Utils ut;  //provides global access to the ut instance in the Utils.cpp file
}
#endif