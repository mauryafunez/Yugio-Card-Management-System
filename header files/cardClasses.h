#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//This is the card object with all the attributes it needs.
class card
{
public:
	//Attributes
	string card_name, description, card_type, category;
	int attack, defense, amount;

	//Constructor and Destructor
	card();
	~card();
};

class repeatInfo
{
public:
	//Attributes
	vector<string> iterations;
	vector<int> positions;

	//Constructor and Destructor
	repeatInfo();
	~repeatInfo();
};


//Allows us to verify if there are more cards of the same name.
bool verifyDouble(string name, fstream& file, int& option);

//Checks if the name is actually the same or if it only contains part of the name.
bool nameCheck(repeatInfo container, string name, int* nameInfo, int containSize);

//Shows me all the iterations of the same name in the file and the positions where they happen
repeatInfo showIterations(fstream& file, vector<string> backUp, string name);


//Checks if we can open the file or not.
void openError(fstream& file);

//Copies the whole file and puts it in a container that we can manipulate
vector<string> copyFile(fstream& file);
