//==========================================================
//
// Title:      Lab 02
// Course:     CSC 1501
// Lab Number: 2-1
// Author:     Sadeem Shamoun
// Date:       1/27/2020
// Description: 
//	Truth Tables
//
//==========================================================#include <conio.h> // For function getch()
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"

const int w = 8;

char pp(bool p)
{
	if (p)
		return 'T';
	else
		return 'F';
}

char qq( bool q)
{
	if (q)
		return 'T';
	else
		return 'F';
}

char nation (bool p, bool q)
{
	if (p || q)
		return 'F';
	else
		return 'T';
}

char disjunct (bool p, bool q)
{
	if (p && q)
		return 'T';
	else
		return 'F';
}

char conjunct (bool p, bool q)
{
	if (p || q)
		return 'T';
	else
		return 'F';
}

char xOr (bool p, bool q)
{
	if (p == q)
		return 'F';
	else
		return 'T';
}

char implies (bool p, bool q)
{
	if (!p || q)
		return 'T';
	else
		return 'F';
}

char ifaf (bool p, bool q)
{
	if (p == q)
		return 'T';
	else
		return 'F';
}

int main()
{
	const string OUTPUT_FILE_NAME = "prog1output.txt";
	ofstream outFile;
	outFile.open(OUTPUT_FILE_NAME);
	if (!outFile.is_open())
		cout << "Error: unable to open file '"
		<< OUTPUT_FILE_NAME << "'." << endl << endl;
	else
	{
		bool p[4] = { true, true, false, false};
		bool q[4] = { true, false, true, false};
		
		outFile << "|   p   |   q   |  !p   |  !q   |  p&q  |  p|q  |  p^q  | p->q  | p<->q |" << endl;
		for (int i = 0; i < 4; i++)
		{
			outFile << setw(5)<< pp(p[i]) <<
				setw(w) << qq(q[i]) <<
				setw(w) << nation(p[i], 0) <<
				setw(w) << nation(q[i], 0) <<
				setw(w) << disjunct(p[i], q[i]) <<
				setw(w) << conjunct(p[i], q[i]) <<
				setw(w) << xOr(p[i], q[i]) << 
				setw(w) << implies(p[i], q[i]) << 
				setw(w) << ifaf(p[i], q[i]) << endl;
		}
	}
}