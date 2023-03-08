// VectorMainLab5.cpp
// Calderon, Ryan
//
#include <iostream>
#include <fstream>
#include "Vector.h"
#include <algorithm>

using namespace std;

// prototypes

void print_vector(const Vector<int> &);

int main()
{
    Vector<int> myvec;
    ifstream inp;
    inp.open("lab5_input.txt");
    int next;
    inp >> next;
    while (!inp.fail())
    {
        myvec.push_back(next);
        inp >> next;
    }
    cout << endl << endl;

    cout << "The initial vector:";
    print_vector(myvec);
    
    cout << endl << endl;
    myvec.erase(myvec.size() - 1);

    cout << "After erasing value at index " << myvec.size() << ":"; // was .size()-1 which was in error
   
    print_vector(myvec);
    
    cout << endl << endl;
    myvec.erase(0);

    cout << "After erasing value at index 0:";
    print_vector(myvec);
    
    cout << endl << endl;
    myvec.erase(5);

    cout << "After erasing value at index 5:";
    
    print_vector(myvec);
    cout << endl << endl;

    Vector<int>::iterator itr;
    
    itr = myvec.begin();
    myvec.insert(itr, 333);
    
    cout << "After inserting (with iterator) value 333 in front:";
    
    print_vector(myvec);
    cout << endl << endl;
    
    itr = myvec.end();
    myvec.insert(itr, 777);
    cout << "After inserting (with iterator) value 777 at back:";
    print_vector(myvec);
    cout << endl
         << endl;
    itr = myvec.begin();
    for (int i = 1; i <= 11; i++)
        itr++;
    myvec.insert(itr, 555);
    cout << "After inserting (with iterator) value 555 in 12th place:";
    print_vector(myvec);
    cout << endl
         << endl;
    return 0;
}
void print_vector(const Vector<int> &v)
{
    cout << endl;
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}