/* Citation and Sources...
Final Project Milestone 2
Module : AidMan
Filename: AidMan.cpp
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
    Milestone 5: OOP244ZDD
    ==================================================
    Name   : Tejinder Singh
    ID     : 129121216
    Email  : ktejinder-singh@myseneca.ca
    Section: ZDD
*/

#define _CRT_SECURE_NO_WARNINGS
#include "AidMan.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
namespace sdds {
    unsigned int AidMan::menu() const {
        ut.testMode();
        cout << "Aid Management System" << endl;
        int yr, month, day;
        ut.getSystemDate(&yr, &month, &day);
        cout << "Date: ";
        cout << yr << "/";
        cout.fill('0');
        cout.width(2);
        cout << month;
        cout << "/";
        cout.width(2);
        cout << day << endl;
        if (fileName == nullptr) {
            cout << "Data file: No file" << endl;
        }
        else {
            cout << "Data file: " << fileName << endl;
        };
        cout << "---------------------------------" << endl;

        unsigned int opt = menuInfo.run();
        return opt;
    };


    // Constructor
    AidMan::AidMan() {
        fileName = nullptr;
        menuInfo.set("1- List Items\n2- Add Item\n3- Remove Item\n4- Update Quantity\n5- Sort\n6- Ship Items\n7- New/Open Aid Database\n---------------------------------\n", 7);
        numberItemsArray = 0;
        for (int i = 0; i < sdds_max_num_items; i++) {
            allItems[i] = nullptr;

        };


    };

    // Destructor
    AidMan::~AidMan() {
        delete[] fileName;

    };

    void AidMan::run() {
        bool kp_Running = true;
        do {
            unsigned int optionSelected = menu();

            if (optionSelected != 0 && fileName == nullptr && optionSelected != 7) {
                optionSelected = 7;

            };

            if (optionSelected == 0) {
                cout << "Exiting Program!" << endl;
                kp_Running = false;
                save();
                deallocate();
            }
            else if (optionSelected == 1) {
                cout << "\n****" << "List Items" << "****\n";
                list();


            }
            else if (optionSelected == 2) {
                cout << "\n****" << "Add Item" << "****\n";
                if (numberItemsArray < sdds_max_num_items) {
                    // There is still some space to store items
                    cout << "1- Perishable" << endl;
                    cout << "2- Non-Perishable" << endl;
                    cout << "-----------------" << endl;
                    cout << "0- Exit" << endl;
                    cout << "> ";
                    int optionSelected = ut.getIntegerWithRange(2, 0, cin);
                    if (optionSelected == 1 || optionSelected == 2) {
                        if (optionSelected == 1) {
                            allItems[numberItemsArray] = new Perishable;
                        }
                        else {
                            allItems[numberItemsArray] = new Item;
                        };
                        // Reading the sku 
                        int sku = allItems[numberItemsArray]->readSku(cin);
                        int index = search(sku);
                        if (index == -1) {
                            // Sku does not exist in the array
                            // Reading the rest of the information about the item
                            allItems[numberItemsArray]->read(cin);
                            // After reading, checking the state.
                            if (*(allItems[numberItemsArray])) {
                                // Good state
                                numberItemsArray += 1;
                            }
                            else {
                                // Bad state
                                // Displaying the item
                                allItems[numberItemsArray]->linear(false);
                                allItems[numberItemsArray]->display(cout);
                                // Deallocating the item
                                delete allItems[numberItemsArray];

                            };

                        }
                        else {
                            // Sku already exist
                            cout << "Sku: " << sku << " is already in the system, try updating quantity instead.\n\n";
                            // deallocating the memory
                            delete allItems[numberItemsArray];


                        };
                    }
                    else {
                        // option selected is equal to 0.
                        cout << "Aborted" << endl;
                    };
                }
                else {
                    // Array already full
                    cout << "Database full!" << endl;

                };

            }
            else if (optionSelected == 3) {
                cout << "\n****" << "Remove Item" << "****\n";
                cout << "Item description: ";
                // Taking c-string(description) as input from the user.
                char tempDesc[100] = "\0";
                int x = 0;
                while (cin.peek() != '\n') {
                    tempDesc[x] = cin.get();
                    x += 1;
                };
                cin.get();
                int noItemsPrinted = list(tempDesc);
                if (noItemsPrinted > 0) {
                    // Asking the user 'SKU' to be removed
                    cout << "Enter SKU: ";
                    int sku = ut.getIntegerWithRange(99999, 10000, cin);
                    int indexToBeRemoved = -1;
                    for (int i = 0; i < numberItemsArray; i++) {
                        if (strstr(*(allItems[i]), tempDesc) != NULL) {
                            // The item which match the given description
                            if ((int)*(allItems[i]) == sku) {
                                indexToBeRemoved = i;
                                i = numberItemsArray;
                            };
                        };

                    };

                    if (indexToBeRemoved == -1) {
                        // No itwm with the matching SKU is found
                        cout << "SKU not found!" << endl;
                    }
                    else {
                        // Matching SKU found
                        // Displaying the item
                        cout << "Following item will be removed: " << endl;
                        allItems[indexToBeRemoved]->linear(false);
                        allItems[indexToBeRemoved]->display(cout);
                        cout << endl;
                        cout << "Are you sure?" << endl;
                        cout << "1- Yes!" << endl;
                        cout << "0- Exit" << endl;
                        cout << "> ";
                        int option = ut.getIntegerWithRange(1, 0, cin);
                        if (option == 1) {
                            // User confirms item to be deleted
                            remove(indexToBeRemoved);
                            cout << "Item removed!" << endl << endl;
                        }
                        else {
                            // User does not want to remove the item
                            cout << "Aborted!" << endl << endl;

                        };

                    };
                };
            }
            else if (optionSelected == 4) {
                cout << "\n****" << "Update Quantity" << "****\n";
                // Asking user for Item description
                cout << "Item description: ";
                char tempDesc[100] = "\0";
                int i = 0;
                while (cin.peek() != '\n') {
                    tempDesc[i] = cin.get();
                    i += 1;
                };
                cin.get();
                int noProductsPrinted = list(tempDesc);
                if (noProductsPrinted > 0) {
                    cout << "Enter SKU: ";
                    int sku = ut.getIntegerWithRange(99999, 10000, cin);
                    int index = -1;
                    for (int i = 0; i < numberItemsArray; i++) {
                        if (strstr(*(allItems[i]), tempDesc) != NULL) {
                            if (sku == (int)(*allItems[i])) {
                                index = i;
                                i = numberItemsArray;
                            };

                        };



                    };

                    if (index == -1) {
                        // No match of SKU found.
                        cout << "SKU not found!\n";

                    }
                    else {
                        // Matching SKU found.
                        cout << "1- Add" << endl;
                        cout << "2- Reduce" << endl;
                        cout << "0- Exit" << endl;
                        cout << "> ";
                        int option = ut.getIntegerWithRange(2, 0, cin);
                        if (option == 1) {
                            // Add to the quantity
                            if (allItems[index]->qty() == allItems[index]->qtyNeeded()) {
                                // Quantity already fulfilled.
                                cout << "Quantity Needed already fulfilled!\n\n";

                            }
                            else {
                                // Quantity can still be increased.
                                cout << "Quantity to add: ";
                                int qtyToAdd = ut.getIntegerWithRange((allItems[index]->qtyNeeded() - allItems[index]->qty()), 1, cin);
                                *(allItems[index]) += qtyToAdd;
                                cout << qtyToAdd << " items added!\n\n";

                            };
                        }
                        else if (option == 2) {
                            // Reduce the qunatity
                            if (allItems[index]->qty() == 0) {
                                // Already the quantity is 0.
                                cout << "Quaintity on hand is zero!\n\n";

                            }
                            else {
                                // Quantity can still be reduced
                                cout << "Quantity to reduce: ";
                                int qtyToReduce = ut.getIntegerWithRange(allItems[index]->qty(), 1, cin);
                                *(allItems[index]) -= qtyToReduce;
                                cout << qtyToReduce << " items removed!\n\n";

                            };

                        }
                        else {
                            // User chooses t exit.
                            cout << "Aborted!\n\n";

                        };
                    };

                }
                else {
                    cout << "No matches found!\n";


                };

            }
            else if (optionSelected == 5) {
                cout << "\n****" << "Sort" << "****\n";

            }
            else if (optionSelected == 6) {
                cout << "\n****" << "Ship Items" << "****\n";

            }
            else if (optionSelected == 7) {
                cout << "\n****" << "New/Open Aid Database" << "****\n";
                load();

            };

        } while (kp_Running);

    };

    // Save method
    void AidMan::save() {
        if (fileName != nullptr) {
            ofstream ofstr(fileName);
            for (int i = 0; i < numberItemsArray; i++) {
                // Saving each item to the file by calling the save function.
                allItems[i]->save(ofstr);
                ofstr << endl;
            };
            // Closing the file.
            ofstr.close();
        };


    };

    // Deallocate method.
    void AidMan::deallocate() {
        // deleting the memory allocated by the iProduct pointers.
        for (int i = 0; i < numberItemsArray; i++) {
            delete allItems[i];

        };
        // Closing the file and freeing the memory.(??)

        // Setting the number of items in array to 0
        numberItemsArray = 0;



    };

    bool AidMan::load() {
        // Saving the changes to the file.
        save();
        // Deallocating all the resources.
        deallocate();

        // Inputting filename
        cout << "Enter file name: ";
        char tempName[100] = "\0";
        int i = 0;
        while (cin.peek() != '\n') {
            tempName[i] = cin.get();
            i += 1;
        };
        cin.get();
        fileName = new char[strlen(tempName) + 1];
        strcpy(fileName, tempName);
        //Opening the file to read
        ifstream ifstr(fileName);
        int noRecordsLoaded = 0;
        if (ifstr.is_open()) {
            // successful. // Reading the file
            while (ifstr.peek() != EOF) {
                char c = ifstr.peek();
                int x = c - 48;
                if (x >= 1 && x <= 3) {
                    // Perishable
                    allItems[numberItemsArray] = new Perishable;
                }
                else if (x >= 4 && x <= 9) {
                    // Item
                    allItems[numberItemsArray] = new Item;
                }
                else {
                    // Setting to fail state.
                    ifstr.setstate(ios::failbit);

                };
                allItems[numberItemsArray]->load(ifstr);

                if (allItems[numberItemsArray]) {
                    // Good State
                    noRecordsLoaded += 1;
                    numberItemsArray += 1;
                }
                else {
                    // Bad State
                    delete allItems[numberItemsArray];
                };

            };



        }
        else {
            cout << "Failed to open FN for reading!" << endl;
            cout << "Would you like to create a new data file?" << endl;
            cout << "1- Yes!" << endl;
            cout << "0- Exit" << endl;
            cout << ">";
            int optionSelected = (int)ut.getIntegerWithRange(1, 0, cin);
            if (optionSelected == 1) {
                // Creating a new file.
                ofstream ofstr(fileName);
                // Closing the file
                ofstr.close();
            };

        };
        cout << noRecordsLoaded << " records loaded!" << endl << endl;

        bool return_value;
        if (noRecordsLoaded > 0) {
            return_value = true;

        }
        else {
            return_value = false;

        };

        return return_value;
    };

    int AidMan::list(const char* sub_desc) {
        int noProductsPrinted = 0;
        int indexesPrinted[sdds_max_num_items];
        if (sub_desc == nullptr) {
            if (numberItemsArray > 0) {
                // Printing all the items, no sub decription given
                cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl;
                cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
                for (int i = 0; i < numberItemsArray; i++) {
                    cout << " ";
                    cout.fill(' ');
                    cout.width(3);
                    cout << i + 1 << " | ";
                    allItems[i]->linear(true);
                    allItems[i]->display(cout);
                    cout << endl;
                    indexesPrinted[i] = i;

                };

                cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
                noProductsPrinted = numberItemsArray;
            }
            else {
                // The list is empty
                cout << "The list is emtpy!" << endl;
            };


            if (noProductsPrinted > 0) {
                cout << "Enter row number to display details or <ENTER> to continue:" << endl;
                cout << "> ";

                if (cin.peek() == '\n') {
                    // Nothing
                    cin.get();
                    cout << endl;

                }
                else {

                    int option = (int)ut.getIntegerWithRange(noProductsPrinted, 1, cin);
                    allItems[indexesPrinted[option - 1]]->linear(false);
                    allItems[indexesPrinted[option - 1]]->display(cout);
                    cout << endl << endl;

                };



            };

        }
        else {
            int i2 = 0;
            for (int i = 0; i < numberItemsArray; i++) {
                // Checking if the subdescription exists in the description
                if (strstr(*(allItems[i]), sub_desc) != NULL) {
                    indexesPrinted[i2] = i;
                    i2 += 1;
                    noProductsPrinted += 1;
                };


            };

            if (noProductsPrinted > 0) {
                cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl;
                cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
                for (int i = 0; i < numberItemsArray; i++) {
                    if (strstr(*(allItems[i]), sub_desc) != NULL) {
                        cout << " ";
                        cout.fill(' ');
                        cout.width(3);
                        cout << i + 1 << " | ";
                        allItems[i]->linear(true);
                        allItems[i]->display(cout);
                        cout << endl;
                    };

                };
                cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;

            }
            else {
                // The list is empty
                cout << "The list is emtpy!" << endl;

            };


        };




        return noProductsPrinted;
    };

    // SKU SEARCH
    int AidMan::search(int sku) const {
        int index = -1;

        for (int i = 0; i < numberItemsArray; i++) {
            if (sku == (int)*(allItems[i])) {
                index = i;
                // Ending the loop
                i = numberItemsArray;

            };


        };

        return index;
    };

    // Delets the item a particular index.
    void AidMan::remove(int index) {
        // Freeing the memory at the 'index'
        delete allItems[index];
        allItems[index] = nullptr;

        // Shifting the iProdcut Pointers to left.
        for (int x = index; x < numberItemsArray - 1; x++) {
            allItems[x] = allItems[x + 1];

        };

        allItems[numberItemsArray - 1] = nullptr;
        numberItemsArray -= 1;

    };

}