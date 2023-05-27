/* 
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

    
    unsigned int Utils::getIntegerWithRange(unsigned int maxValue, unsigned int minValue, std::istream& istr) {
        bool keep_asking = true;
        double retrn_vlu;
        do {
            double Num;
            char a;
            if (istr.peek() == '\n')
            {
                
                cout << "Invalid Integer, retry: ";
                
                istr.get();

            }
            else if (istr.peek() == ' ') {
                
                cout << "Invalid Integer, retry: ";
                
                while (istr.get() != '\n') {

                };
            }
            else
            {
                
                istr >> Num;
                if (istr.fail())
                {
                    
                    istr.clear();
                    cout << "Invalid Integer, retry: ";

                    while (istr.get() != '\n')
                    {
                        
                    };

                }
                else
                {
                    a = istr.get();
                    if (a == '\n')
                    {

                        
                        if (Num >= minValue && Num <= maxValue)
                        {
                             
                            keep_asking = false;
                            retrn_vlu = Num;

                        }
                        else
                        {
                            
                            cout << "Value out of range [" << minValue << "<=val<=" << maxValue << "]: ";

                        };

                    }
                    else
                    {
                        
                        cout << "Invalid Integer, retry: ";

                        
                        while (istr.get() != '\n')
                        {

                        };
                    };
                };

            };

        } while (keep_asking);

        return retrn_vlu;

    };
    double Utils::getDoubleWithRange(double maxValue, double minValue, std::istream& istr) {

        bool keep_asking = true;
        double return_value;
        do {
            double Num;
            char a;
            if (istr.peek() == '\n')
            {
                
                cout << "Invalid number, retry: ";
               
                istr.get();

            }
            else if (istr.peek() == ' ') {
                
                cout << "Invalid number, retry: ";
               
                while (istr.get() != '\n') {

                };
            }
            else
            {
                istr >> Num;
                if (istr.fail())
                {
                   
                    istr.clear();
                    cout << "Invalid number, retry: ";

                    while (istr.get() != '\n')
                    {
                        
                    };

                }
                else
                {
                    a = istr.get();
                    if (a == '\n')
                    {

                        
                        if (Num >= minValue && Num <= maxValue)
                        {
                            // Right Integer. 
                            keep_asking = false;
                            return_value = Num;

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

        } while (keep_asking);

        return return_value;






    };


}
