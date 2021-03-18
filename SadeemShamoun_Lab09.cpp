\//
//  Lab09.cpp
//  CSC 1501
//
//  Created by Sadeem Shamoun on 3/30/20.
//  Copyright © 2020 Sadeem Shamoun. All rights reserved.
//

#include <cstdlib>  // For several general-purpose functions
#include <fstream>  // For file handling
#include <iomanip>  // For formatted output
#include <iostream>  // For cin, cout, and system
#include <string>  // For string data type
#include <cmath>  // For math operations
using namespace std;  // So "std::cout" may be abbreviated to "cout"

void permutation(string a, int x, int y)
{
    if (x == y)
        cout << a << ", ";
    else
    {
        for (int i = x; i <= y; i++)
        {
            swap(a[x], a[i]);
            permutation(a, x + 1, y);
            swap(a[x], a[i]);
        }
    }
}

void print(char set[], string prefix, int n, int k)
{
    if (k == 0)
    {
        cout << (prefix) << ", " ;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        string newPrefix;
        newPrefix = prefix + set[i];
        print(set, newPrefix, n, k - 1);
    }
}

void printAllKLength(char set[], int k, int n)
{
    print(set, "", n, k);
}

int main()
{
    cout << "---------------------------------------------" << endl;
    cout << "PROBLEM 1:" << endl;
    cout << "---------------------------------------------" << endl;
    string str = "aeiou";
    string str2 = "complexity";
    int n = str.size();
    permutation(str, 0, 4);
    cout << ", " ;
    permutation(str2, 0, 5);

    cout << "---------------------------------------------" << endl;
    cout << "PROBLEM 2:" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "aeiou: " << endl;
    char set1[] = { 'a', 'e' , 'i', 'o', 'u' };
    int k = 4;
    printAllKLength(set1, k, 5);

    cout << "complexity";
    char set2[] = { 'c', 'o', 'm', 'p', 'l', 'e', 'x', 'i', 't', 'y' };
    k = 6;
    printAllKLength(set2, k, 10);
}

