//==========================================================
//
// Title:      Lab 04
// Course:     CSC 1501
// Lab Number: 4
// Author:     Sadeem Shamoun
// Date:       2/12/2020
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

bool normal(bool p)
{
	if (p)
		return true;
	else
		return false;
}

bool nation(bool p)
{
	if (p)
		return false;
	else
		return true;
}

bool disjunct(bool p, bool q)
{
	if (p && q)
		return true;
	else
		return false;
}

bool conjunct(bool p, bool q)   
{
	if (p || q)
		return true;
	else
		return false;
}

bool xOr(bool p, bool q)
{
	if (p == q)
		return false;
	else
		return true;
}

bool nAnd(bool p, bool q)
{
	if (p && q)
		return false;
	else
		return true;
}

bool xNor(bool p, bool q)
{
	if (p != q)
		return false;
	else
		return true;
}


int main()
{
	bool p[8] = { true, true, true, true, false, false, false, false };
	bool q[8] = { true, true, false, false, true, true, false, false };
	bool r[8] = { true, false, true, false, true, false, true, false };
	cout << "|   A   |   B   |   C   |  A.B  |  A+C  |  B+C  |  (A.B)XOR[(A+C).(B+C)]  |" << endl;
	for (int i = 0; i < 8; i++)
	{
		bool A = disjunct(conjunct(p[i], r[i]), conjunct(q[i], r[i]));
		bool B = xOr(disjunct(p[i], q[i]), A);
		cout << setw(5) << normal(p[i]) <<
			setw(w) << normal(q[i]) <<
			setw(w) << normal(r[i]) <<
			setw(w) << disjunct(p[i], q[i]) <<
			setw(w) << conjunct(p[i], r[i]) <<
			setw(w) << conjunct(q[i], r[i]) <<
			setw(w+6) << B << endl;
	}
	cout << "|   A   |   B   |   C   |  (A.'B)'  |  A+C  |  B+'C  |  (A.'B)'+[(A+C)XOR(B+'C)]  |" << endl;
	for (int i = 0; i < 8; i++)
	{
		bool A = nation(nAnd(p[i], q[i]));
		bool B = xOr(conjunct(p[i], r[i]), nation(conjunct(q[i], r[i])));
		bool C = conjunct(A, B);
		cout << setw(5) << normal(p[i]) <<
			setw(w) << normal(q[i]) <<
			setw(w) << normal(r[i]) <<
			setw(w+2) << A <<
			setw(w+2) << conjunct(p[i], r[i]) <<
			setw(w) << conjunct(q[i], nation(r[i])) <<
			setw(w+11) << C << endl;
	}
	cout << "|   A   |   B   |   C   |  A+B  |  A+'C  |  (BxNorC) |  (A+B)xNOR[(A+'C)+'(BxNorC)]  |" << endl;
	for (int i = 0; i < 8; i++)
	{
		bool A = conjunct(p[i], q[i]);
		bool B = nAnd(nation(conjunct(p[i], r[i])), xNor(q[i], nation(r[i])));
		bool C = xNor(A, B);
		cout << setw(5) << normal(p[i]) <<
			setw(w) << normal(q[i]) <<
			setw(w) << normal(r[i]) <<
			setw(w) << conjunct(p[i], q[i]) <<
			setw(w) << nation(conjunct(p[i], r[i])) <<
			setw(w+3) << xNor(q[i], r[i]) <<
			setw(w+15) << C << endl;
	}

}