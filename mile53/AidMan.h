/*
    ==================================================
    Milestone 5: OOP244ZDD
    ==================================================
    Name   : Tejinder Singh
    ID     : 129121216
    Email  : ktejinder-singh@myseneca.ca
    Section: ZDD
*/


#ifndef SDDS_AIDMAN_H
#define SDDS_AIDMAN_H
#include "Menu.h"
#include "Utils.h"
#include "Date.h"
#include "iProduct.h"
#include <iostream>
#include "Perishable.h"
#include "Item.h"
namespace sdds {
    const int sdds_max_num_items = 100;
    class AidMan {
    private:
        char* fileName;
        Menu menuInfo;
        // Array of iProduct pointers
        iProduct* allItems[sdds_max_num_items];
        int numberItemsArray;
        unsigned int menu() const;

        // Private methods.
        void save();
        void deallocate();
        bool load();
    public:
        // Constructor
        AidMan();
        ~AidMan();
        // Prohibit Copying and Assigning
        AidMan(const AidMan& source) = delete;
        AidMan& operator=(const AidMan& source) = delete;
        // run
        void run();
        // List
        int list(const char* sub_desc = nullptr);
        // Search for the sku and tells if sku already exist or not
        int search(int sku) const;
        // Deletes the item at a particular index.
        void remove(int index);
    };




}
#endif // !SDDS_HealthCard_H


