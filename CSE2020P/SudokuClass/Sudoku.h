/**
 * Header file for sudoku checker program
 * 
 * Name: Ryan Calderon
 * file: Sudoku.h
 * 
*/



#ifndef SUDOKU_H
#define SUDOKU_H

#include<iostream> 
#include<iomanip>
#include <math.h>
#include <vector>
#include<fstream>
#include<set>

using namespace std;

class Sudoku
{
    private: 

        vector<vector<int> > Sudok;

    public:

        Sudoku();
        //Constructor

        //Functions
        void readFile();
        bool testSudoku();
        void print_Sudo();
        bool testRow(int);
        bool testCol(int);
        bool testSect(int);
        

};



#endif