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
#include <cmath>  // For math operations
using namespace std;  // So "std::cout" may be abbreviated to "cout"

int fn(int a)
{
	if (a == 0)
		return 1;
	else 
	{
		int temp = a - 1;
		temp = fn(temp) * a;
		return temp;
	}
}

int sn(int a)
{
	if (a == 0)
		return 0;

	return sn(a - 1) + a + a - 1; // recursive case
}

int gcd(int a, int b)
{
	if (b != 0)
		return gcd(b, a % b);
	else
		return a;
}

int main()
{
	//first table
	const int w = 6;
	cout << "|  n  |  n!  |" << endl;
	for (int i = 1; i < 8; i++)
	{
		cout << setw(w - 2) << i <<
			setw(w+1) << fn(i) << endl;
	}

	//second table
	cout << "|  n  |  n^2  |" << endl;
	for (int i = 1; i < 8; i++)
	{
		cout << setw(w - 2) << i <<
			setw(w + 2) << sn(i) << endl;
	}

	//third table
	int i = 0, j = 8, k = 12;
	int m[100];
	int n[100];

	while (i < 82)
	{
		i++;
		m[i] = j;
		n[i] = k;
		if (i % 9 == 0)
			j++;
		if (k % 20 == 0)
			k = 11;
		k++;
	}

	i = 1, j = 8, k = 12;
	cout << "|  m  |  n  | GCD |" << endl;
	while (i < 82)
	{
		cout << setw(w - 2) << m[i] <<
			setw(w) << n[i] << 
			setw(w) << gcd(m[i], n[i]) << endl;
		i++, j++, k++;
	}
}