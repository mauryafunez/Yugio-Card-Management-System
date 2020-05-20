#include "cardClasses.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

//Constructor for card class
card::card()
{
	amount = 0;
	card_name = "Blank";
	description = "Blank";
	card_type = "Blank";
	category = "Blank";
	attack = 0;
	defense = 0;
}

//Destructor for card class
card::~card()
{
}

//Constructor for repeat info class
repeatInfo::repeatInfo()
{
}

//Destructor for repeat info class
repeatInfo::~repeatInfo()
{
}

//Checks if we failed to open the file
void openError(fstream& file) {
	if (!file) {
		cout << "Unable to open file";
		exit(1); // terminate with error
	}
}

//Verifies if we have already input the card or deck
bool verifyDouble(string name, fstream& file, int& option) {
	if (option == 1) {
		string line;
		char answer;
		int fileCounter = 0;

		//Get the copied file
		vector<string> backUp = copyFile(file);

		//Tell me all the places where I find the same name and what the line says
		repeatInfo cardRepeat = showIterations(file, backUp, name);

		//Let's check if it is the actual name or if it just contains that part of the name
		int containSize = cardRepeat.iterations.size();
		int* nameInfo = new int[containSize];
		bool a = nameCheck(cardRepeat, name, nameInfo, containSize);

		//Now that we know which one is the repeated card, we make the change on the correct line of the backUp.


		//With the right change made to our backUp, we can rewrite the text file.
		delete[] nameInfo;

	}
	file.close();
	return false;
}

//Here we copy the whole file so we can make changes in the middle of the file. 
vector<string> copyFile(fstream& file) {
	string line;
	vector<string> container;
	file.open("cardInventory.txt");
	openError(file);

	while (file)
	{
		getline(file, line);
		container.push_back(line);
	}

	file.close();
	return container;
}

//Checks if the name is actually the same or if it only contains part of the name.
bool nameCheck(repeatInfo container, string name, int* nameInfo, int containSize) {

	//Here we make sure that the name is just the name and not just part of the name
	for (int i = 0; i < containSize; i++) {
		size_t positionStart = container.iterations[i].find('\t');
		string cutBeginning = container.iterations[i].substr(positionStart + 1);
		size_t verifyNameEnd = cutBeginning.find('\t');
		string verifyName = cutBeginning.substr(0, verifyNameEnd);

		if ( verifyName == name) {
			nameInfo[i] = true;
		}
		else
		{
			nameInfo[i] = false;
		}
	}

	return* nameInfo;

	//Here we have to increment the amount of copies.
	//for (int n = 0; n < containSize; n++) {
	//	if (nameInfo[n] == true) {
	//		size_t positionEnd = container.iterations[n].find("\t");
	//		string incrementCopies = container.iterations[n].substr(0, positionEnd);
	//		string theRest = container.iterations[n].substr(positionEnd, '\n'),
	//		int increment = stoi(incrementCopies) + 1;
	//		container.iterations[n] = to_string(increment) + theRest;
	//	}
	//}
}

//I will probably have to change it so that the person can choose what text file to open.
repeatInfo showIterations(fstream& file, vector<string> backUp, string name) {
	file.open("cardInventory.txt");
	openError(file);

	int fileCounter = backUp.size();
	repeatInfo cardRepeat;

	for (int i = 0; i < fileCounter; i++) {
		if (backUp[i].find(name) != -1) {
			cardRepeat.iterations.push_back(backUp[i]);
			cardRepeat.positions.push_back(i);
		}
	}
	file.close();
	return cardRepeat;
}
