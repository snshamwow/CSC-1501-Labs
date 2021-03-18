//  Lab10.cpp
//  CSC 1501
//
//  Created by Sadeem Shamoun on 4/12/20.
//  Copyright © 2020 Sadeem Shamoun. All rights reserved.
//
#include <cstdlib>  // For several general-purpose functions
#include <fstream>  // For file handling
#include <iomanip>  // For formatted output
#include <iostream>  // For cin, cout, and system
#include <string>  // For string data type
#include <cmath>  // For math operations
using namespace std;  // So "std::cout" may be abbreviated to "cout"

int a[10][10], b[10][10],c[10][10],sum[10][10], mult[10][10], newanswer[10][10],r1, c1, r2, c2, i, j, k,x;

void initializeM(){

    cout << "Enter rows and columns for first matrix: ";
    cin >> r1 >> c1;
    cout << "Enter rows and columns for second matrix: ";
    cin >> r2 >> c2;
    
     // Storing elements of first matrix.
    cout << endl << "Enter elements of matrix 1:" << endl;
    for(i = 0; i < r1; ++i)
        for(j = 0; j < c1; ++j)
        {
            cout << "Enter element a" << i + 1 << j + 1 << " : ";
            cin >> a[i][j];
        }
    // Storing elements of second matrix.
    cout << endl << "Enter elements of matrix 2:" << endl;
    for(i = 0; i < r2; ++i)
        for(j = 0; j < c2; ++j)
        {
            cout << "Enter element b" << i + 1 << j + 1 << " : ";
            cin >> b[i][j];
 }
    for(i = 0; i < r1; ++i)
        for(j = 0; j < c2; ++j)
        {
            mult[i][j]=0;
        }
}

void multiplymatrices(){
     for(i = 0; i < r1; ++i)
        for(j = 0; j < c2; ++j)
            for(k = 0; k < c1; ++k)
            {
                mult[i][j] += a[i][k] * b[k][j];
            }
 cout << endl << "Output Matrix: " << endl;
    for(i = 0; i < r1; ++i){
    for(j = 0; j < c2; ++j)
    {
        cout << " " << mult[i][j];
        if(j == c2-1)
            cout << endl;
    }
}
}
void addmatrices(){
     for(i = 0; i < r1; ++i)
        for(j = 0; j < c1; ++j)
            sum[i][j] = a[i][j] + b[i][j];

    // Displaying the resultant sum matrix.
    cout << endl << "Sum of two matrices is: " << endl;
    for(i = 0; i < r1; ++i)
        for(j = 0; j < c1; ++j)
        {
            cout << sum[i][j] << "  ";
            if(j == c1 - 1)
                cout << endl;
        }
    for(i = 0; i < r1; ++i)
           for(j = 0; j < c1; ++j)
           {
               sum[i][j]=0;
           }
}
void newanswer1(){
  cout << endl << "Enter elements of matrix you wish to multiply by C & B" << endl;
           for(i = 0; i < r1; ++i)
               for(j = 0; j < c1; ++j)
               {
                   cout << "Enter element a" << i + 1 << j + 1 << " : ";
                   cin >> c[i][j];
               }
    for(i = 0; i < r1; ++i)
           for(j = 0; j < c2; ++j)
               for(k = 0; k < c1; ++k)
               {
                   newanswer[i][j] += mult[i][k] * c[k][j];
                   
               }
    for(i = 0; i < r1; ++i){
       for(j = 0; j < c2; ++j)
       {
           cout << " " << newanswer[i][j];
           if(j == c2-1)
               cout << endl;
}
    }
}

void matrixtimesscalar(){
    cout << endl << "Enter elements of matrix you wish to scale:" << endl;
          for(i = 0; i < r1; ++i)
              for(j = 0; j < c1; ++j)
              {
                  cout << "Enter element a" << i + 1 << j + 1 << " : ";
                  cin >> a[i][j];
              }
    cout<<"Enter number you wish to scale matrix by:"<<endl;
    cin>>x;
   cout << endl << "Output Matrix: " << endl;
    for(i = 0; i < r1; ++i){
    for(j = 0; j < c2; ++j)
    {
        cout << " " << x*a[i][j];
        if(j == c2-1)
            cout << endl;
    }
}
}
int main(){
    //Problem 1
    cout<<"Please enter rows and columns in (row) *space* (column) format."<<endl;
    initializeM();//initialization of Matrix A & B
    addmatrices();
    //Problem 2
    matrixtimesscalar();//initialization of desired matrix and multiplication by scalar
    cout<<endl;
    //Problem 3
     cout<<"Enter required fields of matrices A and B,respectively."<<endl;
    initializeM();//initialization of Matrix A & B for multiplication
    multiplymatrices();
    //Problem 4
    cout<<"Enter required fields of matrices B and A, respectively."<<endl;
    initializeM();//initialization of matrix B & A
    multiplymatrices();//multiplication of B and A
    //Problem 5
    cout<<"Enter required fields for matrices C and B, respectively."<<endl;
    initializeM();//initialization of matrix C & B
    multiplymatrices();
    cout<<"Enter required fields of matrix A."<<endl;
    newanswer1();
    

}
