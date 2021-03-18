//
//  Lab08.cpp
//  CSC 1501
//
//  Created by Sadeem Shamoun on 3/23/20.
//  Copyright © 2020 Sadeem Shamoun. All rights reserved.
//

#include <cstdlib>  // For several general-purpose functions
#include <fstream>  // For file handling
#include <iomanip>  // For formatted output
#include <iostream>  // For cin, cout, and system
#include <string>  // For string data type
#include <cmath>  // For math operations
using namespace std;  // So "std::cout" may be abbreviated to "cout"

void bubbleSort(int arr[])
{
	int actions = 0;
	for (int j = 0; j < 10; ++j)
	{
		for (int i = 0; i < 10 - j - 1; ++i)
		{
			if (arr[i] > arr[i + 1])
			{
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				actions = actions + 3;
			}
			actions = actions + 1;
		}
	}

	for (int i = 0; i < 10; ++i)
	{
		cout << " " << arr[i];
	}

	cout << "... " << actions << " actions performed." << endl;
}

int main()
{
	int a1[10] = { 1,3,7,5,2,4,6,8,9,10 };
	int a2[10] = { 10,9,8,7,6,5,4,3,2,1 };
	int a3[10] = { 1,10,2,9,3,8,4,7,5,6 };

	cout << "Sorted Array: ";
	bubbleSort(a1);
	
	cout << "Sorted Array: ";
	bubbleSort(a2);

	cout << "Sorted Array: ";
	bubbleSort(a3);
}
