// Lab6.cpp : Defines the entry point for the console application.
//
using namespace std;
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

struct Data {
	unsigned int numberOfChars;
	unsigned int nameLength;
	string charName;
	short int charStrentgh;
	short int charIntelligence;
	short int charAgility;
	unsigned int charHitpoints;
	unsigned intcharMaxHitpoints;
	float charPhysicalArmor;
	float charMagicalArmor;
	unsigned int charInventoryCount;
	unsigned int invNameLength;
	std::string invName;
	unsigned int invValue;
	float invWeight;
};

class Inventory {
private:
	unsigned int charInventCount;
	unsigned int inventoryNameLength;
	string inventoryName;
	unsigned int inventoryValue;
	float inventoryWeight;

public:
	Inventory();
	Inventory(string invenName, unsigned int invenValue, float invenWeight);
	unsigned int GetinventoryNameLength();
	string GetinventoryName();
	unsigned int GetinventoryValue();
	float GetinventoryWeight();
	void Display() const;

};

Inventory::Inventory()
{
	inventoryName = "unknown";
	inventoryValue = 0;
	inventoryWeight = 0.0;
}

Inventory::Inventory(string invenName, unsigned int invenValue, float invenWeight)
{
	inventoryName = invenName;
	inventoryValue = invenValue;
	inventoryWeight = invenWeight;
}

unsigned int Inventory::GetinventoryNameLength()
{
	return inventoryNameLength;
}

string Inventory::GetinventoryName()
{
	return inventoryName;
}

unsigned int Inventory::GetinventoryValue()
{
	return inventoryValue;
}

float Inventory::GetinventoryWeight()

{
	return inventoryWeight;
}

void Inventory::Display() const {
	cout << inventoryName << ", " << inventoryValue << ", " << inventoryWeight << endl;
}

class Character {
private:
	unsigned int lengthOfName;
	string name;
	short int strength;
	short int intelligence;
	short int agility;
	unsigned int hitpoints;
	unsigned int maxHitpoints;
	float physicalArmor;
	float magicalArmor;
	unsigned int inventoryCount;
	unsigned int inventoryValue;
	unsigned int count;

public:
	Character();
	Character(string charName, short int charStrength, short int charIntelligence, short int charAgility, unsigned int charHitpoints, unsigned int Maxhitpoints, float charPhysicalArmor, float charMagicalArmor, unsigned int inventoryCount, unsigned int inventoryValue);
	unsigned int GetLengthOfName();
	string GetName();
	short int GetStrength();
	short int GetIntelligence();
	short int GetAgility();
	unsigned int GetHitpoints();
	unsigned int GetMaxHitpoints();
	float GetPhysicalArmor();
	float GetMagicalArmor();
	unsigned int GetInventoryCount();
	unsigned int GetInventoryValue();
	void AddInventory(const Inventory *i);
	void showInventory(unsigned int Invcount) const;
	void ShowCharacter();
	Inventory* charInventory;
};

Character::Character()
{
	name = "unknown";
	strength = 0;
	intelligence = 0;
	agility = 0;
	hitpoints = 0;
	maxHitpoints = 0;
	physicalArmor = 0.0;
	magicalArmor = 0.0;
	inventoryCount = 0;
	inventoryValue = 0;
	count = 0;
	charInventory = new Inventory[inventoryCount];
}

Character::Character(string charName, short int charStrength, short int charIntelligence, short int charAgility,
	unsigned int charHitpoints, unsigned int charMaxhitpoints, float charPhysicalArmor, float charMagicalArmor, unsigned int invCount, unsigned int invValue)
{
	name = charName;
	strength = charStrength;
	intelligence = charIntelligence;
	agility = charAgility;
	hitpoints = charHitpoints;
	maxHitpoints = charMaxhitpoints;
	physicalArmor = charPhysicalArmor;
	magicalArmor = charMagicalArmor;
	inventoryCount = invCount;
	inventoryValue = invValue;
	count = 0;
	charInventory = new Inventory[inventoryCount];
}

void Character::AddInventory(const Inventory *i)
{
	if (count <= inventoryCount) {
		charInventory[count] = *i;
		count++;
	}
	else
	{
		cout << "Max inventory reached" << endl;
	}
}

unsigned int Character::GetLengthOfName()
{
	return lengthOfName;
}

string Character::GetName()
{
	return name;
}

short int Character::GetStrength()
{
	return strength;
}

short int Character::GetIntelligence()
{
	return intelligence;
}

short int Character::GetAgility()
{
	return agility;
}

unsigned int Character::GetHitpoints()
{
	return hitpoints;
}

unsigned int Character::GetMaxHitpoints()
{
	return maxHitpoints;
}

float Character::GetPhysicalArmor()
{
	physicalArmor = physicalArmor * 100;
	return physicalArmor;
}

float Character::GetMagicalArmor()
{
	magicalArmor = magicalArmor * 100;
	return magicalArmor;
}

unsigned int Character::GetInventoryCount()
{
	return inventoryCount;
}

unsigned int Character::GetInventoryValue()
{
	return inventoryValue;
}

void Character::ShowCharacter()
{
	cout << "Name: " << name << endl;
	cout << "Str: " << strength << endl;
	cout << "Int: " << intelligence << endl;
	cout << "Agi: " << agility << endl;
	cout << "HP: " << hitpoints << " / " << maxHitpoints << endl;
	cout << "Armor: " << physicalArmor * 100 << "%" << endl;
	cout << "Magic armor: " << magicalArmor * 100 << "%" << endl;
	cout << "Inventory: " << endl;
}

void Character::showInventory(unsigned int Invcount) const
{
	//  GetVehicleList();
	if (Invcount != 0) {
		for (unsigned int i = 0; i < Invcount; i++)
		{
			charInventory[i].Display();
		}
		cout << endl;
	}
	else
		cout << "Inventory empty." << endl;
}


void mostItems(vector<Character>& inarr, unsigned int noelements)
{
	unsigned int mostItemsID = 0;
	unsigned int mostItems = 0;
	for (unsigned int i = 0; i < noelements; i++) {
		if (inarr[i].GetInventoryCount() > mostItems) {
			mostItems = inarr[i].GetInventoryCount();
			mostItemsID = i;
		}

	}

	inarr[mostItemsID].ShowCharacter();
	inarr[mostItemsID].showInventory(inarr[mostItemsID].GetInventoryCount());

}

void showHeroes(vector<Character>& inarr, unsigned int noelements)
{
	for (unsigned int i = 0; i < noelements; i++) {
		//for (unsigned int j = 0; j < inarr[i].GetInventoryCount(); i++) {
		//	inarr[j].AddInventory(j);
		//}

		inarr[i].ShowCharacter();
		//	for (unsigned int j = 0; j < inarr[i].GetInventoryCount(); j++) {
		//		inarr[i].showInventory();
		//	}
		inarr[i].showInventory(inarr[i].GetInventoryCount());
		cout << "" << endl;
	}
}

void strongestHero(vector<Character>& inarr, unsigned int noelements)
{
	unsigned int StrongestID;
	short int Strongest;
	StrongestID = 0;
	Strongest = 0;
	for (unsigned int i = 0; i < noelements; i++)
	{
		if (inarr[i].GetStrength() > Strongest) {
			StrongestID = i;
			Strongest = inarr[i].GetStrength();
		}
	}
	inarr[StrongestID].ShowCharacter();
	inarr[StrongestID].showInventory(inarr[StrongestID].GetInventoryCount());



	//	inarr[i].showInventory(inarr[i].GetInventoryCount());
	cout << "" << endl;
}

void mostValHero(vector<Character>& inarr, unsigned int noelements)
{
	unsigned int mostValHeroID = 0;
	unsigned int mostValue = 0;
	for (unsigned int i = 0; i < noelements; i++) {
		if (inarr[i].GetInventoryValue() > mostValue) {
			mostValue = inarr[i].GetInventoryValue();
			mostValHeroID = i;
		}

	}
	inarr[mostValHeroID].ShowCharacter();
	inarr[mostValHeroID].showInventory(inarr[mostValHeroID].GetInventoryCount());

}


void twoClumsiestHeroes(vector<Character>& inarr, unsigned int noelements)
{
	unsigned int ClumsiestID;
	short int Clumsiest;
	short int Clumsiest2;
	unsigned int ClumsiestID2;
	ClumsiestID = 0;
	ClumsiestID2 = 0;
	/*
	if (inarr[0].GetAgility() < inarr[1].GetAgility()) {
		ClumsiestID = 0;
		Clumsiest = inarr[0].GetAgility();
		Clumsiest2 = inarr[1].GetAgility();
		ClumsiestID2 = 1;
	}
	else {
		ClumsiestID = 1;
		Clumsiest = inarr[1].GetAgility();
		ClumsiestID2 = 0;
		Clumsiest2 = inarr[0].GetAgility();
	}
	*/
	for (unsigned int i = 2; i < noelements; i++) {
		if (inarr[i].GetAgility() < Clumsiest && inarr[i].GetAgility() < Clumsiest2) {
			ClumsiestID = i;
			Clumsiest = inarr[i].GetAgility();
		}
		else if (inarr[i].GetAgility() > Clumsiest && inarr[i].GetAgility() < Clumsiest2) {
			ClumsiestID2 = i;
			Clumsiest2 = inarr[i].GetAgility();
		}
	}
	cout << "Clumsiest hero:" << endl;
	inarr[ClumsiestID].ShowCharacter();
	inarr[ClumsiestID].showInventory(inarr[ClumsiestID].GetInventoryCount());
	cout << "" << endl;
	cout << "Second clumsiest hero: " << endl;
	inarr[ClumsiestID2].ShowCharacter();
	inarr[ClumsiestID2].showInventory(inarr[ClumsiestID2].GetInventoryCount());

}



void smartHero(vector<Character>& inarr, unsigned int noelements) {

	short int Smarts;
	Smarts = 18;
	for (unsigned int i = 0; i < noelements; i++) {
		if (inarr[i].GetIntelligence() > Smarts) {
			inarr[i].ShowCharacter();
			inarr[i].showInventory(inarr[i].GetInventoryCount());

		}
	}

}

unsigned int loadData(vector<Character>& character, string fileName, unsigned int startIndex)
{
	Data CharData;
	unsigned int numberOfElements = startIndex;
	vector<Inventory> inventory;
	inventory.resize(5);
	std::ifstream loadfile(fileName, std::ios_base::binary);
	if (loadfile.good())
	{
		//Data CharData;
		loadfile.read((char*)&CharData.numberOfChars, sizeof(CharData.numberOfChars)); // read int bytes
																					   //std::cout << "No of Characters: " << CharData.numberOfChars << std::endl;
		character.resize(CharData.numberOfChars + startIndex);
		//Loop thru number of Characters

		for (unsigned int i = 0; i < CharData.numberOfChars; i++) {
			loadfile.read((char*)&CharData.nameLength, sizeof(CharData.nameLength)); // read int bytes
																					 //std::cout << "Character Name Legth: " << CharData.nameLength << std::endl;
																					 //Read Name
			std::string tempName;
			tempName.resize(CharData.nameLength);
			loadfile.read(&tempName[0], CharData.nameLength);
			CharData.charName = tempName.substr(0, tempName.length() - 1);
			//std::cout << "Player1 name: " << CharData.charName << std::endl;

			loadfile.read((char*)&CharData.charStrentgh, sizeof(CharData.charStrentgh)); // read int bytes
																						 //std::cout << "charStrentgh: " << CharData.charStrentgh << std::endl;

			loadfile.read((char*)&CharData.charIntelligence, sizeof(CharData.charIntelligence)); // read int bytes
																								 //std::cout << "charIntelligence: " << CharData.charIntelligence << std::endl;

			loadfile.read((char*)&CharData.charAgility, sizeof(CharData.charAgility)); // read int bytes
																					   //std::cout << "charAgility: " << CharData.charAgility << std::endl;

			loadfile.read((char*)&CharData.charHitpoints, sizeof(CharData.charHitpoints)); // read int bytes
																						   //std::cout << "charHitpoints: " << CharData.charHitpoints << std::endl;

			loadfile.read((char*)&CharData.intcharMaxHitpoints, sizeof(CharData.intcharMaxHitpoints)); // read int bytes
																									   //std::cout << "intcharMaxHitpoints: " << CharData.intcharMaxHitpoints << std::endl;

			loadfile.read((char*)&CharData.charPhysicalArmor, sizeof(CharData.charPhysicalArmor)); // read int bytes
																								   //std::cout << "charPhysicalArmor: " << CharData.charPhysicalArmor << std::endl;

			loadfile.read((char*)&CharData.charMagicalArmor, sizeof(CharData.charMagicalArmor)); // read int bytes
																								 //std::cout << "charMagicalArmor: " << CharData.charMagicalArmor << std::endl;

			loadfile.read((char*)&CharData.charInventoryCount, sizeof(CharData.charInventoryCount)); // read int bytes
																									 //std::cout << "charInventoryCount: " << CharData.charInventoryCount << std::endl;
																									 //Loop thru number of Inventory Items
			unsigned int invenValue = 0;
			inventory.resize(CharData.charInventoryCount + 1);
			for (unsigned int j = 0; j< CharData.charInventoryCount; j++) {
				loadfile.read((char*)&CharData.invNameLength, sizeof(CharData.invNameLength)); // read int bytes
																							   //std::cout << "invNameLength: " << CharData.invNameLength << std::endl;

				std::string tempInvName;
				tempInvName.resize(CharData.invNameLength);
				loadfile.read(&tempInvName[0], CharData.invNameLength);
				CharData.invName = tempInvName.substr(0, tempInvName.length() - 1);
				//std::cout << "invName: " << CharData.invName << std::endl;

				loadfile.read((char*)&CharData.invValue, sizeof(CharData.invValue)); // read int bytes
																					 //std::cout << "invValue: " << CharData.invValue << std::endl;

				loadfile.read((char*)&CharData.invWeight, sizeof(CharData.invWeight)); // read int bytes
																					   //	std::cout << "invWeight: " << CharData.invWeight << std::endl;

				inventory[j] = Inventory(CharData.invName, CharData.invValue, CharData.invWeight);
				invenValue = invenValue + CharData.invValue;

			}
			character[numberOfElements] = Character(CharData.charName, CharData.charStrentgh, CharData.charIntelligence, CharData.charAgility, CharData.charHitpoints, CharData.intcharMaxHitpoints, CharData.charPhysicalArmor, CharData.charMagicalArmor, CharData.charInventoryCount, invenValue);

			for (unsigned int i = 0; i < CharData.charInventoryCount; i++) {
				character[numberOfElements].AddInventory(&inventory[i]);
			}
			numberOfElements++;
		}
	}

	loadfile.close();

	return numberOfElements;

}

int main()

{
	unsigned int startingIndex = 0;
	cout << "Which file(s) to open?\n";
	cout << "1. fantasyheroes.dat" << endl;
	cout << "2. superheroes.dat" << endl;
	cout << "3. Both files" << endl;
	int option;
	cin >> option;
	/* Load hero files here *///SAMPLE_heroes.dat
	vector<Character> character;
	vector<Inventory> inventory;

	if (option == 1) {
		startingIndex = loadData(character, "fantasyheroes.dat", 0);
		//startingIndex = loadData(character, "SAMPLE_heroes.dat", 0);
		//cout << "Last Index: " << startingIndex << endl; // for testing
		//cout << "" << endl; // for testing
		//cout << character[0].GetName() << endl; // for testing
		//character[0].showInventory(3); // for testing
		//cout << endl; // for testing
	}
	if (option == 2) {
		startingIndex = loadData(character, "superheroes.dat", 0);
		//cout << "Last Index: " << startingIndex << endl; // for testing
		//cout << "" << endl; // for testing
	}
	if (option == 3) {
		startingIndex = loadData(character, "fantasyheroes.dat", 0);
		//startingIndex = loadData(character, "SAMPLE_heroes.dat", 0);
		//	cout << "****************" << endl;  // for testing
		//	system("Pause");  // for testing
		startingIndex = loadData(character, "superheroes.dat", startingIndex);
		//startingIndex = loadData(character, "SAMPLE_heroes.dat", startingIndex);
		// totalSets = totalSets + numberOfSets;
		//cout << "Total number of sets: " << startingIndex << endl;  // for testing
		//cout << "" << endl;  //for testing
		//cout << character[20].GetName() << endl;
		//character[20].showInventory(character[20].GetInventoryCount());
		//cout << endl;
	}
	cout << "1. Print all heroes" << endl;
	cout << "2. Hero with the most items" << endl;
	cout << "3. Strongest hero" << endl;
	cout << "4. Heroes with greater than 18 intelligence" << endl;
	cout << "5. 2 clumsiest heroes" << endl;
	cout << "6. Hero with the most valuable stuff" << endl;
	cout << endl;

	cin >> option;

	/* Work your magic here */

	if (option == 1) {
		showHeroes(character, startingIndex);
	}
	if (option == 2) {
		mostItems(character, startingIndex);
	}

	if (option == 3) {
		strongestHero(character, startingIndex);
	}
	if (option == 4) {
		smartHero(character, startingIndex);
	}
	if (option == 5)
	{
		twoClumsiestHeroes(character, startingIndex);
	}
	if (option == 6) {
		mostValHero(character, startingIndex);
	}
	/*======= Load data from file(s) =======*/
	//	system("pause");
	return 0;
}
