//====================================================
// Daniel Rutledge
// 10/14/18
// Assignment 1
//====================================================
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

struct wordInfo // My structure of values.
{
	string word;
	int frequency;
};

wordInfo deletePunct(wordInfo); // Removes any and all punctuation from the tempWord.
wordInfo convertCase(wordInfo); // Converts every character in tempWord into a lower case letter.
void alphabetize(vector<wordInfo>& infoVector); // Reorganizes the data in the vector to ascending alphabetical order.
int duplicate(wordInfo, vector<wordInfo>& infoVector); // Searches for duplicates in the vector and eliminates them.
void displayInfo(vector<wordInfo>& infoVector); // Displays the contents of the vector.

int main()
{
	wordInfo tempWord; // A temporary working copy of each word in the text.
	vector<wordInfo> infoVector; // Holds all the data for each word.
	ifstream inputFile;
	inputFile.open("text.txt");
	if (!inputFile) // If there's no file...
	{
		cout << "Error. File read failed.\n";
	}
	int inputCount = 0; // Index keeps track of how many elements have been put in the vector.
	int exists; // If exists = -1, the word doesn't already exist. If it does, exists is the subscript in the vector of that word.
	cout << "Word:          Frequency:\n";
	cout << "==============================\n";

	while (inputFile)
	{
		if (inputFile)
			inputFile >> tempWord.word;
		inputCount++;
		tempWord = deletePunct(tempWord); 
		tempWord = convertCase(tempWord);
		exists = duplicate(tempWord, infoVector);
		if (exists == -1)
		{
			tempWord.frequency = 1;
			infoVector.push_back(tempWord);
		}
		else if (exists != -1)
		{
			infoVector[exists].frequency++;
		}
	}
	alphabetize(infoVector);
	displayInfo(infoVector);

	return 0;
}

wordInfo deletePunct(wordInfo tempWord) // This function deletes all the punctuation.
{
	for (int count = 0; count < tempWord.word.length(); count++)
	{
		if (ispunct(tempWord.word[count]))
		{
			tempWord.word[count] = tempWord.word[count] + 1;
			tempWord.word.resize(tempWord.word.length() - 1);
		}
	}
	
	return tempWord;
}

wordInfo convertCase(wordInfo tempWord) // This function makes everything lower case.
{
	bool upper;
	for (int count = 0; count < tempWord.word.size() - 1; count++)
	{
		upper = isupper(tempWord.word[count]);
		if (upper = true)
		{
			tempWord.word[count] = tolower(tempWord.word[count]);
		}
	}
	return tempWord;
}

void alphabetize(vector<wordInfo>& infoVector) // This function was recycled from the final project.
{
	bool swap;
	wordInfo temp;

	do
	{
		swap = false;
		for (int count = 0; count < (infoVector.size() - 1); count++)
		{
			if (infoVector[count].word > infoVector[count + 1].word)
			{
				temp = infoVector[count];
				infoVector[count] = infoVector[count + 1];
				infoVector[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}

int duplicate(wordInfo tempWord, vector<wordInfo>& infoVector) // This function returns the address of each duplicate word or a -1 if there aren't any.
{
	int count = 0;
	int position = -1;
	bool found = false;
	while (count < infoVector.size() && !found)
	{
		if (infoVector[count].word == tempWord.word)
		{
			found = true;
			position = count;
		}
		count++;
	}
	return position;
}

void displayInfo(vector<wordInfo>& infoVector) // Outputs all the words.
{
	for (int count = 0; count < infoVector.size() ; count++)
	{
		cout << left << setw(20) << infoVector[count].word << left <<setw(20) << infoVector[count].frequency << endl;
	}
}