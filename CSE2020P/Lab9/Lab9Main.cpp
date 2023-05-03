/**
 * 
 * Name: Ryan Calderon
 * 
 * File: Lab9Main.cpp
 * 
 * This is the main file of lab 9: Lab 9 expands on our
 * previous program from lab 8, it makes changes to the 
 * searching.h file. We will follow the 5.2 module slides.
*/

#include <iostream>
#include <algorithm>
#include "Vector.h"
#include "List.h"
#include "Random.h"
#include "Searching.h"

using namespace std;

int main(){

    for( int k = 20; k <= 100; k += 20)
    {
        Vector<int> myvec;
        random_vector_norep(k, 1, 1000, myvec, 0);

        Vector<int> sortvec(myvec);
        sort(sortvec.begin(), sortvec.end());

        List<int> sortlist;
        for(int i = 0; i < sortvec.size(); i++)
        {
            sortlist.push_back(sortvec[i]);
        }

        Vector<int> five_target;
        random_vector_norep(5, 0, myvec.size() - 1, five_target, 0);

        int ops1 = 0;
        int ops2 = 0;
        int ops3 = 0;

        for(int i = 0; i < 5; i++)
        {
            int target = myvec[five_target[i]];
            linear_search_V(sortvec, target, ops1);
            linear_search_L(sortlist, target, ops2);
            binary_search_V(sortvec, target, ops3);
            cout << "\n";

            cout << "Searching linear structure of size " << myvec.size()
                <<" for target " << target << ":"
                << "\n\n";

            cout << "linear_search_V: " << ops1
                << " ops" << endl;
            cout << "linear_search_L: " << ops2
                << " ops" << endl;
            cout << "binary_search_V: " << ops3
                << " ops" << endl;
            cout << endl;


        }

    }

    return 0;
}
