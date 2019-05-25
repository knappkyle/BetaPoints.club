// Copyright 2018 ©, Kyle Knapp, All rights reserved.
// lambadaChee.club

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void betaPointInput(string names[], int points[]);
void betaPointSort(string names[], int points[]);
void betaPointFile(string names[], int points[]);

const int MAX_NAMES = 41;

int main()
{
	int points[MAX_NAMES];

	string names[] { "Austin Belcher", "Jarred Magers","Cameron Pulling","Mike Dziak","Blake Burton","Juan Moreno","Justus Smith","Avery Sciore","Nick Thum","Garrett West","Dillion Belcher","Ryan Osborn","Andrew Luptak","Brendan McCarthy","Justin Belle","Jared Sater","Steve Shivak","Dylan Nguyen","Kylor Kauahi","Ian Herb","Josh Peterson","Jake Hyppa","Kevin Michel","Nick Miranda","Marco Solis","Patrick Leahy","Danny Fulop","Jay Shiltz","Bryson Mann","Mitchell Fink","Noah Dubasik","Tyler Nutt","Andrew Arnold","Evan Wolfe","Casey Hayes","Mikey Baumberger","Hunter Crossley","Luke Darrow","Colton Stevens","Harbir Multani","Tayshon Dickerson" };

	betaPointInput(names, points);
	betaPointSort(names, points);
	betaPointFile(names, points);

	system("pause");
	return 0;
}


//==============================================================================================
// Manually input beta point score one by one and stores data into points[] array			   =
//==============================================================================================
void betaPointInput(string names[], int points[])
{
	cout << right << setw(50) << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
	cout << right << setw(55) << "INPUT TOTAL BETA POINT SCORE" << endl;
	cout << right << setw(50) << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;

	for (int i = 0; i < MAX_NAMES; i++)
	{
		cout << right << setw(40) << names[i] << " : ";
		cin >> points[i];
	}
}


//==============================================================================================
// Sorts points[] array from highest to lowest then assigns the names[] array to sorted points =
//==============================================================================================
void betaPointSort(string names[], int points[])
{
	for (int k = 40; k >= 0; k--)
	{
		for (int x = 0; x < MAX_NAMES; x++)
		{
			if (points[x] < points[x + 1])
			{
				int temp = points[x + 1];

				points[x + 1] = points[x];
				points[x] = temp;

				string temp_name = names[x + 1];

				names[x + 1] = names[x];
				names[x] = temp_name;
			}

		}
	}

	cout << endl;
	cout << right << setw(50) << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
	cout << right << setw(40) << "SORTED" << endl;
	cout << right << setw(50) << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;

	for (int i = 1; i < MAX_NAMES; i++)
	{
		cout << right << setw(40) << names[i] << ":" << points[i] << endl;
	}

}


//==============================================================================================
// Creates file "total.txt" and prints the newly sorted arrays into an HTML file syntax		   =
//==============================================================================================
void betaPointFile(string names[], int points[])
{

	ofstream outfile;
	outfile.open("total.txt");

	outfile << "<b>" << endl;
	outfile << "<tr>" << endl;
	outfile << "<th style=\"text - align:center\">Name</th>" << endl;
	outfile << "<th style=\"text - align:center\">Beta Points</th>" << endl;
	outfile << "<b>" << endl;
	outfile << "<tr>" << endl;

	for (int e = 1; e < MAX_NAMES; e++)
	{
		outfile << "<tr>" << endl;
		outfile << "<td>" << names[e] << "</td>" << endl;
		outfile << "<td>" << points[e] << "</td>" << endl;
		outfile << "</tr>" << endl;
	}
	outfile << "</b>" << endl;

}