/*
    ==================================================
    Milestone3: OOP435ZCC
    ==================================================
    Name   : Tejinder Singh
    ID     : 129121216
    Email  : ktejinder-singh@myseneca.ca
    Section: ZCC
*/



#include <iostream>
#include <iomanip>
#include "Station.h"
#include "Utilities.h"

size_t sdds::Station::m_widthField = 0;
int sdds::Station::id_generator = 0;

sdds::Station::Station(const string& record) {
    Utilities utilities;
    size_t nextpos = 0;
    bool more = true;
    
    id = ++id_generator;
    name = utilities.extractToken(record, nextpos, more);
    nextSerialNum = stoi(utilities.extractToken(record, nextpos, more));
    numItems = stoi(utilities.extractToken(record, nextpos, more));
    m_widthField = m_widthField > utilities.getFieldWidth() ? m_widthField : utilities.getFieldWidth();
    description = utilities.extractToken(record, nextpos, more);
}

const string& sdds::Station::getItemName() const {
    return name;
}

size_t sdds::Station::getNextSerialNumber() {
    return nextSerialNum++;
}

size_t sdds::Station::getQuantity() const {
    return numItems;
}

void sdds::Station::updateQuantity() {
    if (numItems > 0) {
        numItems--;
    }
}

void sdds::Station::display(ostream& os, bool full) const {
    os << std::right;
    os << setw(3) << setfill('0') << id << " | ";
    os << left << setfill(' ') << setw(m_widthField + 1) << name << " | ";
    os << right << setw(6) << setfill('0') << nextSerialNum << " | ";

    if (full) {
        os << setfill(' ');
        os << right;
        os << setw(4) << numItems << " | " << description;
    }

    os << endl;
}