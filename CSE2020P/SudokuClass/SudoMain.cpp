/**
 * Main file for our Sudoku class program 
 * 
 * Ryan Calderon
 * CSE 2020
 * 
*/

#include "Sudoku.cpp"


int main(){

    Sudoku mySudoku;

    mySudoku.print_Sudo();

    if(mySudoku.testSudoku())
    {
        cout << " The Sudoku grid passed this Sudoku Solution tester\n\n";

    }

    else
    {
        cout << "The Sudoku grid failed this Sudoku Solution Tester\n\n";

    }
    return 0;

}