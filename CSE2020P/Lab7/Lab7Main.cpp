/*
 * 
 * Name: Ryan Calderon
 * File: Lab7Main.cpp
 * 
 * postfix calculator; simple case with operands that can
 * only be single characters or single digits, no white space;
 * Kerstin Voigt, CSE 2020  Spring 2023; Lab 7 
*/

#include "Postfix.hpp"
#include<iostream>

using namespace std;
int main()
{
    string postfix;
    string ws;
    bool quit = false;
    do
    {
        cout << "Enter postfix expr: ";
        getline(cin, postfix);
        
        cout << "The postfix expr is: " << postfix;
        cout << endl << endl;

        int value = eval_postfix(postfix);
        cout << "The value of this expression is " << value << endl << endl;
        
        cout << "More? [y/n] ";
        
        char more;
        cin >> more;
        
        cout << "more is " << more << endl << endl;

        if (more != 'y' && more != 'Y')
        {
            quit = true;
        }

        // getline(cin, ws);    // NEEDED to ready off the \n left over by
    getline()

        cin.ignore();

    } 
    while (!quit);

    return 0;
}