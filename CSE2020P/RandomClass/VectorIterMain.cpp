/**
 * Name: Ryan Calderon
 * 
 * File: Iterators.cpp
 * 
 * This file will create iterators to iterate/point for the 
 * vector class. This file will use the Vector data structure 
 * 
*/


#include "Vector.h"
#include <algorithm>//allows for utility functions 
//Gives access to sort, find, etc.
#include <iostream>
#include "Random.h" //Utility file given by KV

using namespace std;

int main()
{
    Vector<int> myvec;

    random_vector(25, 1, 100, myvec, 0);

    Vector<int>::iterator itr;

    cout << "Vector myvec printed with iterators: " << endl;
    
    //Our vector printed out as is without sorting or changes
    for(itr = myvec.begin(); itr != myvec.end(); itr++)
    {
        cout << *itr << " ";
    }
    cout << "\n\n";

    sort(myvec.begin(), myvec.end());
    //Sort our vector and reprint the vector 
    //Sort class function from algorithm library

    cout << "Vector myvec now sorted: " << endl;
    for(itr = myvec.begin(); itr != myvec.end(); itr++)
    {
        cout << *itr << " ";
    }

    cout << endl << endl;

    //Finding a target/value in our vector without a search function

    int tofind;

    cout << "Find which value in myvec? ";
    cin >> tofind;
    cout << "\n\n";

    //use the find class function from algorithm library
    if(find(myvec.begin(), myvec.end(), tofind) != myvec.end())
    {
        cout << "Found Value!" << tofind << " :-)";

    }

    else
    {
        cout << "Value " << tofind << " not found :-(";
    }

    cout << endl << endl;

    //Obtain the maximum value in our vector without max function

    Vector<int>::iterator max;
    Vector<int>::iterator min;
    //new vectors for the maximum and minimum values

    max = max_element(myvec.begin(), myvec.end());
    //puts the highest values from vector into its own seperate vector
    min = min_element(myvec.begin(), myvec.end());
    //puts the lowest value from vector into its own seperate vector

    cout << "The maximal and minimal values are: " << *max << " and "
        << *min << endl << endl;

    //Fill the vector with values to fill in all spots

    fill(myvec.begin(), myvec.end(), 7);
    //fills up the vector with the value of 7;

    cout << "Vector myvec covered in 7s: " << endl;

    for(itr = myvec.begin(); itr != myvec.end(); itr++)
    {
        cout << *itr << " "; 
        //print out the pointed to values
    }

    cout << endl << endl;

    return 0; //end the int main()

}