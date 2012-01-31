// main.cpp - Email Checker program main entry point
// Written by Sam Springer

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Email validation function
bool IsValid(const string& emailAddress);

void main()
{
	// Input file to read email addresses from
	ifstream in("Email.txt");

	// Output file to write 0s and 1s to
	ofstream out("Result.txt");

	// 0. While we are not at the end of file...
	while(!in.eof())
	{
		string emailAddress;

		// 1. Read an email from Email.txt, capturing an entire line
		getline(in, emailAddress);

		// 2. Validate email address
		bool isValid = IsValid(emailAddress);

		// 3. Write result to Result.txt
		out << isValid << ' ' << emailAddress << endl;
	}

	system("pause");
}







// Provide user with information on what the program is doing.
// Write out the valid characters, much fewer than invalid characters
// Do not hard code constants, use variable names
// Make a function for . and - rules
// Can use find to look for .. .- -. --
// Read 4.1
// Quiz on Tuesday