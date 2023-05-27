/*
    ==================================================
    Milestone 2: OOP244ZDD
    ==================================================
    Name   : Tejinder Singh
    ID     : 129121216
    Email  : ktejinder-singh@myseneca.ca
    Section: ZDD*/
// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments
#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H
#include <iostream>
#include<cstring>
namespace sdds {
    class Status
    {
        char* m_description{};
        int m_code;
    public:
        Status(const char* description = nullptr);
        Status(const Status& stat);
        Status& operator =(const char* description);
        Status& operator =(int code);
        operator int() const;
        operator const char* () const;
        operator bool() const;
        Status& clear();
        std::ostream& print(std::ostream& ostr) const;
        ~Status();

    };
    std::ostream& operator<<(std::ostream& os, const Status& stat);

}
#endif
