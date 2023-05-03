/**
 * 
 * Ryan Calderon
 * File: BinaryMain.cpp
 * 
 * Main program file for lab 12 binary heap
 * 
*/

#include <iostream>
#include "BinaryHeap.h"
#include "Random.h"

using namespace std;

int main()
{
    BinaryHeap<int> myHeap; //Create a heap vector called myHeap
    Vector<int> inputs; //Create a vector to hold inputs that will be put into random vec

    rand_seed(); 
    random_vector(7, 1, 250, inputs, 0);

    for(int i = 0; i < inputs.size(); i++)
    {
        myHeap.insert(inputs[i]);
        // put all elements into the heap 
    }

    cout << endl << "This is my heap: " << endl;
    myHeap.print_heap();
    // print our heap values 

    cout << endl;
    
    cout << endl << "Taking down my heap.. " << endl;
    int theMin;
    // define min value variable

    while(!myHeap.empty())
    {
        myHeap.deleteMin(theMin);
        cout << " Deleting minimum value " << theMin << endl;
        myHeap.print_heap();
        cout << endl;
    }

    return 0;
}

