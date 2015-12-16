//Jay Rosen
//This program uses Filter.h header file to read an input file and write to output file the UPPER CASE data from input file

#include"Filter.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
	// local variables and class objects
	ifstream input;
	ofstream upper;
	Upper up;
	string inFile, upperFile, yes_no;
	inFile = "inParagraph.txt";
	upperFile = "outParagraph.txt";

	cout << "\n\n\t\t This program will modify inParagraph.txt.\n\n\t\t Is inParagraph.txt available in source folder? (y/n) ";
	cin >> yes_no;
	if (yes_no == "y" || yes_no == "Y")
	{
		// open the text file with the data to be transformed
		input.open(inFile, ios::in);
		while (input.fail()) // verifies file can be opened
		{
			cout << "\n\n\t\t ERROR: Input file cannot be opened.";
			cout << "\n\n\t\t Re-enter file name: ";
			cin >> inFile;
			input.open(inFile, ios::in);
		}
	}

	if (yes_no == "n" || yes_no == "N")
	{
		cout << "\n\n\t\t Move inParagraph.txt to source folder and try again.\n\n\t\t ";
		return 0;
	}

	cout << "\n\n\t\t Transform outParagraph.txt to all UPPER CASE? (y/n): ";
	cin >> yes_no;

	if (yes_no == "y" || yes_no == "Y")
	{
		// opens the file to write the upper case transformed data to
		upper.open(upperFile, ios::out | ios::trunc);
		// verifies if file can be opened
		if (upper.fail())
		{
			cout << "\n\n\t\t Upper case file cannot be opened";
			return 0;
		}
		up.doFilter(input, upper);
		cout << "\a\n\n\t\t outParagraph.txt HAS BEEN WRITTEN IN UPPERCASE!\n\n\t\t ";
	}

	if (yes_no == "n" || yes_no == "N")
	{
		cout << "\n\n\t\t Program Terminated. outParagraph.txt has not been modified. \n\n\t\t ";
		return 0;
	}

	// close open files
	input.close();
	upper.close();

	cout << "\n\n\t\t ";
	system("pause");
	return 0;
}