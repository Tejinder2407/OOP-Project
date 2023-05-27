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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <string.h>
#include "Utils.h"
using namespace std;
namespace sdds
{
    // The ut object of type Utils that is accessible to any file including "Utils.h" to call the Utils
    // methods
    Utils ut;

    void Utils::testMode(bool testmode)
    {
        m_testMode = testmode;
    }
    void Utils::getSystemDate(int* year, int* mon, int* day)
    {
        if (m_testMode)
        {
            if (day)
                *day = sdds_testDay;
            if (mon)
                *mon = sdds_testMon;
            if (year)
                *year = sdds_testYear;
        }
        else
        {
            time_t t = std::time(NULL);
            tm lt = *localtime(&t);
            if (day)
                *day = lt.tm_mday;
            if (mon)
                *mon = lt.tm_mon + 1;
            if (year)
                *year = lt.tm_year + 1900;
        }
    }
    int Utils::daysOfMon(int month, int year) const
    {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = (month >= 1 && month <= 12 ? month : 13) - 1;
        return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }
    void Utils::alocpy(char*& destination, const char* source)
    {

        delete[] destination;
        destination = nullptr;

        if (source && source[0])
        {
            destination = new char[strlen(source) + 1];
            strcpy(destination, source);
        }
    }
    int Utils::getint(const char* prompt)
    {

        if (prompt)
            cout << prompt;
        bool result = false;
        int vlu{ 0 };
        do
        {
            cin >> vlu;
            if (!cin || cin.peek() != '\n')
            {

                cin.clear();
                cin.ignore(1000, '\n');
            }
            else
            {
                result = true;
            }

        } while (!result && cout << "Invalid Integer, retry: ");

        return vlu;
    }
    int Utils::getint(int min, int max, const char* prompt, const char* errMes)
    {

        bool result = false;

        int vlu{ 0 };
        if (prompt)
            cout << prompt;
        do
        {
            vlu = getint();

            if (vlu >= min && vlu <= max)
            {
                result = true;
            }
            else
            {
                if (errMes)
                    cout << errMes << ", retry: ";
                else
                {
                    cout << "Value out of range [" << min << "<=val<=" << max << "]: ";
                }
            }

        } while (!result);

        return vlu;
    }
    double Utils::getdouble(const char* prompt)
    {

        if (prompt)
            cout << prompt;
        bool result = false;
        double value{ 0 };
        do
        {
            cin >> value;
            if (!cin || cin.peek() != '\n')
            {

                cin.clear();
                cin.ignore(1000, '\n');
            }
            else
            {
                result = true;
            }

        } while (!result && cout << "Invalid number, retry: ");

        return value;
    }
    double Utils::getdouble(double min, double max, const char* prompt, const char* errMes)
    {

        bool result = false;

        double value{ 0 };
        if (prompt)
            cout << prompt;
        do
        {
            value = getdouble();

            if (value >= min && value <= max)
            {
                result = true;
            }
            else
            {
                if (errMes)
                    cout << errMes << ", retry: ";
                else
                {
                    cout.setf(ios::fixed);
                    cout.precision(2);
                    cout << "Value out of range [" << min << "<=val<=" << max << "]: ";
                }
            }

        } while (!result);

        return value;
    }
}