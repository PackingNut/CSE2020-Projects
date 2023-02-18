/**
 * Magic. h file
 * 
 * Class file for our magic square program
 * 
*/


#ifndef MAGIC_H
#define MAGIC_H

#include<vector>
#include<iostream>
#include<iomanip>
#include <string>
#include <cassert>
#include<fstream>
#include<math.h>

using namespace std;

class magicSquare
{

    private:
        int dim;
        int magicSum;

        vector<vector<int> > mag;

    public:
        
        magicSquare(); //constructor 

        //Member Functions 
        void read_square();
        void print_magic();
        bool test_magic();

        int row_sum(int);
        int col_sum(int);
        int diag1_sum();
        int diag2_sum();
        int magic_sum();





};

#endif