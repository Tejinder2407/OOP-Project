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
#include "Utilities.h"

char sdds::Utilities::m_delimiter = '|';

void sdds::Utilities::setFieldWidth(size_t newWidth) {
    m_widthField = newWidth;
}

size_t sdds::Utilities::getFieldWidth() const {
    return m_widthField;
}

string sdds::Utilities::extractToken(const string& str, size_t& next_pos, bool& more) {

    if (str[next_pos] == m_delimiter || next_pos >= str.length()) {
        more = false;
        throw invalid_argument("Invalid next_pos arguement");
    }

    string token = "";
    string white_space = "";

    while (next_pos < (size_t)str.length()) {
        if (str[next_pos] != ' ') {
            if (str[next_pos] == '\n' || str[next_pos] == '\r') {
                break;
            } else if (str[next_pos] == m_delimiter) {
                if (m_widthField < token.length()) {
                    m_widthField = token.length();
                }
                more = true;
                next_pos++;
                return token;
            } else {
                if (token.length() > 0) {
                    token += white_space + str[next_pos];
                    white_space = "";
                } else {
                    token += str[next_pos];
                    white_space = "";
                }

                if (next_pos == (size_t)str.length() - 1) {
                    if (m_widthField < token.length()) {
                        m_widthField = token.length();
                    }
                    more = false;
                    next_pos++;
                    return token;
                }
            }
        } else {
            white_space += ' ';
        }
        next_pos++;
    }

    more = false;
    return token;
}
