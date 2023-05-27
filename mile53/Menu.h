/*
    ==================================================
    Milestone 5: OOP244ZDD
    ==================================================
    Name   : Tejinder Singh
    ID     : 129121216
    Email  : ktejinder-singh@myseneca.ca
    Section: ZDD
*/


#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include "Utils.h"
namespace sdds {
    class Menu {
        char* menuContext;
        unsigned int noOfOptions;

    public:
        // Default Constructor
        Menu();
        // Conctructor
        Menu(const char* MenuContext, unsigned int NumberOptions);
        // Destructor
        ~Menu();
        // setEmpty
        void setEmpty();
        // Prohibit Copying and Assigning
        Menu(const Menu& source) = delete;
        Menu& operator=(const Menu& source) = delete;

        // run() method
        unsigned int run() const;

        // UserDefined Set()
        void set(const char* MenuContext, unsigned int NumberOptions);

    };




}
#endif // !SDDS_HealthCard_H


