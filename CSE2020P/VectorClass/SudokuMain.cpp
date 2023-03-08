

// main.cpp
// Main file for sudoku solver 
// create sudoku solver via algorithm given in Horstmann, Big C++, Chapter 6
#include <iostream> 
#include <cassert>
#include "Sudoku.h" //Pull class functions

using namespace std;
int main()
{
    Vector<Vector <int> > sud;
    read_sudoku(sud);
    //read the chosen file for the sudoku table

    print_sudoku(sud);
    //output the file and any changes made to it
    if (test_sudoku(sud))
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
             
    }
    return 0;


}
