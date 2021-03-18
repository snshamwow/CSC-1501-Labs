//
//  Lab05.cpp
//  CSC 1501
//
//  Created by Sadeem Shamoun on 2/23/20.
//  Copyright © 2020 Sadeem Shamoun. All rights reserved.
//

#include <cstdlib>  // For several general-purpose functions
#include <fstream>  // For file handling
#include <iomanip>  // For formatted output
#include <iostream>  // For cin, cout, and system
#include <string>  // For string data type
#include <cmath>
using namespace std;  // So "std::cout" may be abbreviated to "cout"

double fn(double n)
{
	if (fmod(n, 3) == 0)
		return (n / 3);
	else
		return floor(n);
}

double fmn(double m, double n)
{
	if (m >= n)
		return sqrt(m - n);
	else
		return pow(m-n, 2);
}

double flmn(double l, double m, double n)
{
	if ((m >= l && m <= n) || (m >= n && m <= l)) {
		return m;
	}
	if ((n >= l && n <= m) || (n > m&& n <= l)) {
		return n;
	}
	if ((l >= m && l < n) || (l <= m && l >= n)) {
		return l;
	}
	else {
		return 16;
	}
}

int main()
{
	const int w = 6;
	cout << setprecision(3);
	double n = -4;
	cout << "|  n  | f(n) |" << endl;
	for (int i = 0; i < 17; i++)
	{
		cout << setw(w-2) << n <<
		setw(w) << fn(n) << endl;

		n += .5;
	}
	cout << endl;
	
	int nA[9] = { 0, 0, 0, 1, 1, 1, 2, 2, 2 };
	int mA[9] = { 0, 1, 2, 1, 1, 2, 0, 1, 2 };
	
	int m;
	m = 0;
	cout << "|  n  |  m  | out |" << endl;
	for (int i = 0; i < 9; i++)
	{
		cout << setw(w - 2) << nA[i] <<
			setw(w) << mA[i] <<
			setw(w) << fmn(mA[i], nA[i]) << endl;

		n += 1;
		m += 1;
	}
	cout << endl;

	int lA[8] = { 0, 0, 0, 0, 2, 2, 2, 2};
	int mmA[8] = { 1, 1, 3, 3, 1, 1, 3, 3};
	int nnA[8] = { 2, 4, 2, 4, 2, 4, 2, 4};
	m = 1;
	n = 2;
	int l;
	l = 0;
	cout << "|  l  |  m  |  n  | 2ndLg |" << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << setw(w - 2) << lA[i] <<
			setw(w) << mmA[i] <<
			setw(w) <<nnA[i] <<
			setw(w+1) << flmn(lA[i], mmA[i], nnA[i]) << endl;

		n += 2;
		m += 2;
		l += 2;
	} 
}