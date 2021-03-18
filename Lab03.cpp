//
//  main.cpp
//  Lab 03
//
//  Created by Yankun Xi on 9/23/19.
//  Copyright © 2019 Yankun Xi. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

string binary_add(string a, string b)
{
    string result;
    int s = 0; //stops when reaching 0
    int i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || s == 1)
    {
        s += ((i >= 0) ? a[i] - '0' : 0);
        s += ((j >= 0) ? b[j] - '0' : 0);
        result += char(s % 2 + '0');
        s /= 2; 
        i--, j--; //moves backwarads
    }
    return result;
}

string binary_sub(string a, string b)
{
       //String that will store the result
       string result;
       string oneComp;
       //make both numbers equal length to subtract properly
       if (a.size() < b.size())
       {
           for (int i = 0; i < (b.size() - a.size()); i++) 
                a = "0" + a;
       }
       else
       {
           for (int i = 0; i < (a.size() - b.size()); i++) 
               b = "0" + b;
       }
       //loop to take out ones complement of a
       for (int i = 0; i < a.length(); i++)
            oneComp += (((a[i]-48) == 0) ? "1" : "0");
       cout << oneComp << endl;
       //addition of ones complement with 1 to take out twos complement of a
       string twoComp = binary_add(oneComp, "1");
       cout << twoComp << endl;
       //addition of b with twos complement of a to subtract a from b
       result = binary_add(b,twoComp);
    return result;
}

int binary2int(string a)
{
    int conv[10];
    int result=0;
    //convert given number backwards
    for (int i = a.size() - 1; i >= 0; i--)
    {
        if (a[i] == '1')
        {
            conv[a.size() - i-1] = 1;
        }
        else {
            conv[a.size() - i-1] = 0;
        }
    }

    //convert binary to decimal
    for (int i = 0; i<a.size(); i++)
    {
        conv[i] *= pow(2,i);
        result += conv[i];
    }
    return result;
}

void int2binary(int b)
{
    int binaryNumber[100];

    int i = 0;

    while (b > 0) {

        binaryNumber[i] = b % 2;

        b /= 2;

        i++;

    }

    for (int j = i - 1; j >= 0; j--)
        cout << binaryNumber[j];
}

int main(int argc, const char* argv[]) {
    // insert code here...
    cout << "Problem 1: "; int2binary(34) ;cout << endl;
    cout << "Problem 2: "; int2binary(22) ;cout << endl;
    cout << "Problem 3: " << binary2int("1001") << endl;
    cout << "Problem 4: " << binary2int("111011") << endl;
    cout << "Problem 5: " << binary_add("11", "1110") << endl;
    cout << "Problem 6: " << binary_sub("111", "1010") << endl;
    
    return 0;
}
