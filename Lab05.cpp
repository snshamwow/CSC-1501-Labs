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


using namespace std;  // So "std::cout" may be abbreviated to "cout"

string int2binary(int n) 
{
    string s = "";
    int binaryNumber[100];
    int i = 0;

    while (n > 0) 
    {
        binaryNumber[i] = n % 2;

        n = n / 2;

        i++;
    }

    for (int j = i - 1; j >= 0; j--)
        s = s + to_string(binaryNumber[j]);

    return s;
}

string binary_add(string a, string b)
{
    string result = "";
    int s = 0;
    int long i = a.size() - 1, j = b.size() - 1;

    while (i >= 0 || j >= 0 || s == 1)
    {
        s += ((i >= 0) ? a[i] - '0' : 0);
        s += ((j >= 0) ? b[j] - '0' : 0);
        result = char(s % 2 + '0') + result;
        s /= 2;

        i--;
        j--;
    }
    return result;
}

int singleMult(string a, string b)
{
    return (a[0] - '0') * (b[0] - '0');
}

int equalLen(string& str1, string& str2)
{
    int len1 = str1.size();
    int len2 = str2.size();

    if (len1 < len2)
    {
        for (int i = 0; i < len2 - len1; i++)
            str1 = '0' + str1;
        return len2;
    }

    else if (len1 > len2)
    {
        for (int i = 0; i < len1 - len2; i++)
            str2 = '0' + str2;
    }
    return len1; // If len1 >= len2
}

long int binaryMult(string X, string Y)
{
    int n = equalLen(X, Y);
    if (n == 0) return 0;
    if (n == 1) return singleMult(X, Y);

    int fh = n / 2;
    int sh = (n - fh);

    string Xl = X.substr(0, fh);
    string Xr = X.substr(fh, sh);
    string Yl = Y.substr(0, fh);
    string Yr = Y.substr(fh, sh);

    long int P1 = binaryMult(Xl, Yl);
    long int P2 = binaryMult(Xr, Yr);
    long int P3 = binaryMult(binary_add(Xl, Xr), binary_add(Yl, Yr));

    return P1 * (1 << (2 * sh)) + (P3 - P1 - P2) * (1 << sh) + P2;
}

int main() 
{
    long int a = binaryMult(int2binary(2), int2binary(5));
    long int b = binaryMult(int2binary(3), int2binary(5));
    long int c = binaryMult(int2binary(b), int2binary(7));

    long int d = binaryMult(int2binary(2), int2binary(5));
    long int e = binaryMult(int2binary(13), int2binary(14));
    long int f = binaryMult(int2binary(a), int2binary(13));
    long int g = binaryMult(int2binary(c), int2binary(9));

    cout << int2binary(d) << endl;
    cout << int2binary(e) << endl;
    cout << int2binary(f) << endl;
    cout << int2binary(g) << endl;
}