/**
 * 
 * 
 * Ryan Calderon 
 * 
 * Header file redo for the Sudoku class
*/

#ifndef SUDOKU_H_
#define SUDOKU_H_

#include "Vector.h"
using namespace std;

// function prototypes ("function declarations")
void read_sudoku(Vector<Vector<int> >&);
void print_sudoku(const Vector<Vector<int> >&);
bool test_sudoku(const Vector<Vector<int> >&);
bool row_1to6(int, const Vector<Vector<int> >&);
bool col_1to6(int, const Vector<Vector<int> >&);
bool rect_1to6(int n, const Vector<Vector<int> >& sud);
void rec_rows_cols(int, Vector<int>&, Vector<int>&);


#endif