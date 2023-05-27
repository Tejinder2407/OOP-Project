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
#include"Status.h"
#include "Utils.h"
using namespace std;
namespace sdds {
    Status::Status(const char* description)
    {
        m_code = 0;
        if (description != nullptr)
        {
            ut.alocpy(m_description, description);
        }
    }
    Status::Status(const Status& stat)
    {


        if (stat.m_description != nullptr)
        {
            ut.alocpy(m_description, stat.m_description);
            m_code = stat.m_code;
        }
        else
        {
            delete[] m_description;
            m_description = nullptr;
            m_code = 0;
        }
    }
    Status& Status::operator =(const char* description)
    {
        if (description != nullptr)
        {
            ut.alocpy(m_description, description);
        }
        return *this;
    }
    Status& Status::operator =(int code)
    {
        m_code = code;
        return *this;

    }
    Status::operator int() const
    {
        return m_code;
    }
    Status::operator const char* () const
    {
        return m_description;
    }
    Status::operator bool() const
    {
        return m_description == nullptr;
    }
    Status& Status::clear()
    {
        if (m_description != nullptr)
        {
            delete[] m_description;
            m_description = nullptr;
            m_code = 0;
        }
        return *this;
    }
    Status::~Status()
    {
        delete[] m_description;
    }

    std::ostream& Status::print(std::ostream& ostr) const
    {

        if (m_code == 0)
        {
            ostr << m_description;
        }
        else
        {
            ostr << "ERR#" << m_code << ": ";
            ostr << m_description;
        }
        return ostr;
    }

    std::ostream& operator<<(std::ostream& os, const Status& stat)
    {
        if (stat)
        {
            
        }
        else
        {
            stat.print(os);
        }
        return os;
    }



}