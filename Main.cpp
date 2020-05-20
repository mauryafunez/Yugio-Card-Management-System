// ManagementSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ostream>
#include <string>
#include <fstream>
#include <vector>
#include "cardClasses.h"

using namespace std; 

int main()
{
    //Main display screen. We will show the user what options he or she has. 
    cout << "\t\t===Welcome to your Yugioh Card Inventory===\n";
    cout << "\t\t Please select what you want to do by typing the appropriate number.\n";
    cout << "\t\t1. Add a card to your inventory\n";
    cout << "\t\t2. Delete a card from your inventory\n";
    cout << "\t\t3. View the cards in your inventory.\n";
    cout << "\t\t3. Make a deck.\n";
    cout << "\t\t5. Delete a previously made deck.\n";
    cout << "\t\t4. View a previously made deck\n";

    //User selects what they want. Menu will be displayed depending on what they choose.
    int option;
    cin >> option;

    cin.ignore(256, '\n');
    system("CLS");

    card insertCard;
    string input;
    fstream logCard;

    switch (option) {
        //Insert the new card into the inventory. 
        case 1:
            cout << "\t\tEnter the following information:\n" ;

            cout << "\t\t1. Name of the card: "; 
            getline(cin, input);
            insertCard.card_name = input;
            cout << "\n";

            // Function checks if name is already there. 
            verifyDouble(insertCard.card_name, logCard, option);

            if (!verifyDouble) {
                cout << "\t\t3. Attack points: ";
                cin >> insertCard.attack;
                cout << "\n";

                cout << "\t\t4. Defense Points: ";
                cin >> insertCard.defense;
                cout << "\n";

                cout << "\t\t5. Card type (Monster, Spell, Trap): ";
                cin >> insertCard.card_type;
                cout << "\n";

                cout << "\t\t6. Category of the type (Effect, continuous, fusion, etc.): ";
                cin >> insertCard.category;
                cout << "\n";

                cout << "\t\t7. Amount of cards you want to add: ";
                cin >> insertCard.amount;
                cout << "\n";

                cin.ignore(256, '\n');

                cout << "\t\t2. Description of the card: ";
                getline(cin, input);
                insertCard.description = input;
                cout << "\n";

                //Open the text file and record the card
                logCard.open("cardInventory.txt", fstream::app);

                //Want to check if the file is there.
                openError(logCard);

                logCard << to_string(insertCard.amount) + "\t" + insertCard.card_name + "\t" + to_string(insertCard.attack) + "\t" + to_string(insertCard.defense) + "\t" + insertCard.card_type + "\t" + insertCard.category + "\t" + insertCard.description + "\n";
                logCard.close();

                cout << "You have inserted a new card into the database!";
            }
            break;

        default:
            break;
    }

    cout << "You have reached the end.";
    
    return 0;
}






// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
