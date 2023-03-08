

// main.cpp
// Main file for sudoku solver 
// create sudoku solver via algorithm given in Horstmann, Big C++, Chapter 6
#include <iostream> 
#include <cassert>
#include <utility>
#include "Vector.h"//Vector Library
#include "Sudoku.h" //Pull class functions

using namespace std;
int main()
{
    Vector<Vector<int> > mysudoku;
    read_sudoku(mysudoku);
    //read the chosen file for the sudoku table

    print_sudoku(mysudoku);
    //output the file and any changes made to it
    if (test_sudoku(mysudoku))
    //test if the sudoku follows the rules of sudoku
    {
        cout << endl;
        cout << "YES, this is a solved 6x6 Sudoku :)"
            << endl << endl;
    }
    else
    {
        cout << endl;
        cout << "TOO BAD ... this is not yet a 6x6 Sudoku solution :("
             << endl
             << endl;
        
        cout << "Solving the rest...." << "\n\n";
        Vector<pair<int, int> > z_cells;
        z_cells = find_empty(mysudoku);
        //call to sudoku filling function

        cout << "These cells still needs values: " << endl;

        for(int i = 0; i < z_cells.size(); ++i)
        {
            cout << "(" << z_cells[i].first << "," << z_cells[i].second << ")\t";
            //format each outputted set of integers
            //\t activates a tab after the first set is outputted
        }

        //cells with zero (row,col)
        cout << endl << endl;

        if(fixSudo(mysudoku, z_cells) == 1) 
        {
            cout << "Now Solved :) ";
            cout << endl;
            print_sudoku(mysudoku);
        }
        else{
            cout << "Could not find the solution by just filling in missing numbers.";
        }
        
    }
    return 0;


}

