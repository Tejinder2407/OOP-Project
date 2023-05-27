/* Citation and Sources...
Final Project Milestone 2
Module : Status
Filename: Status.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include "Status.h"
#include <iostream>
#include <cstring>
namespace sdds {
    Status::Status(const char* Description) {
        if (Description != nullptr && strlen(Description) > 0) {
            // Setting the description.
            description = new char[strlen(Description) + 1];
            strcpy(description, Description);
        }
        else {
            description = nullptr;

        };

        errorCode = 0;
    };

    Status::~Status() {
        delete[] description;

    };

    
    Status::Status(const Status& srcStatus) {
        if (srcStatus.description != nullptr) {
            description = new char[strlen(srcStatus.description) + 1];
            strcpy(description, srcStatus.description);
        }
        else {
            description = nullptr;

        };


        errorCode = srcStatus.errorCode;
    };

    // Copy Assignment Operator.
    Status& Status::operator=(const Status& srcStatus) {
        delete[] description;
        if (srcStatus.description != nullptr) {
            description = new char[strlen(srcStatus.description) + 1];
            strcpy(description, srcStatus.description);

        }
        else {
            description = nullptr;

        };

        errorCode = srcStatus.errorCode;

        return *this;
    };

    // Assignment Operator Overloads.
    // Assigning to Int.
    Status& Status::operator=(int newCode) {
        errorCode = newCode;

        return *this;

    };

    // Assigning to string.
    Status& Status::operator=(const char* newDescription) {
        delete[] description;
        if (newDescription != nullptr && strlen(newDescription) > 0) {
            description = new char[strlen(newDescription) + 1];
            strcpy(description, newDescription);

        }
        else {
            description = nullptr;
        };
        return *this;
    };

    
    Status::operator int() const {
        return errorCode;

    };

    Status::operator const char* () const {

        return description;

    };

    Status::operator bool() const {
        bool object_valid;
        if (description != nullptr && strlen(description) > 0) {
            object_valid = false;

        }
        else {
            object_valid = true;
        };
        return object_valid;
    };

    // clear

    Status& Status::clear() {
        delete[] description;
        description = nullptr;
        errorCode = 0;

        return *this;

    };

    // Insertion operator overload.
    std::ostream& operator<<(std::ostream& os, const Status& status) {
        if (int(status) != 0) {
            os << "ERR#" << (int)status << ": ";

        };
        if (bool(status) == false) {
            os << (const char*)status;

        };
        return os;

    };

    //set.
    void Status::set(const char* Description, int code) {

        if (Description != nullptr && strlen(Description) > 0) {
            delete[] description;
            description = new char[strlen(Description) + 1];
            strcpy(description, Description);
        }
        else {
            description = nullptr;
        };
        errorCode = code;

    };


}
