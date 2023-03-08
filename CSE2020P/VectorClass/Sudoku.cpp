/**
 * 
 * Ryan Calderon
 * 
 * Function definition file for our sudoku class
*/


#include <iostream>
#include <iomanip>
#include <cassert>
#include "Vector.h"
#include <string>
#include <fstream>
#include "Sudoku.h"


using namespace std;

// reads 6x6 sudoku puzzle; 
void read_sudoku(Vector<Vector<int> >& sud)
{
    ifstream inp;
    Vector<int> nums;
    // create a stream that can read a file
    string file;
    cout << endl;
    cout << "Which sudoku textfile?: ";
    cin >> file;
    // Access requested file

    inp.open(file);
    //open file

    int next;
    inp >> next; //temporary variable to hold values 

    while (!inp.fail())
    //If the exists, this happens
    {
        nums.push_back(next);
        inp >> next; 
    }
    inp.close();
    //closes the file to avoid data corruption

    assert(nums.size() == 36);

    int k = 0;
    for (int i = 1; i <= 6; i++)
    {
        Vector<int> row; 
        //create new Vector to hold row 

        for (int j = 1; j <= 6; j++)
        {
            row.push_back(nums[k]);
            k++;
            //add value to the row Vector
        }
        
        sud.push_back(row); //add entire row Vector to the sudoku Vector
        
    }
    return;
}

void print_sudoku(const Vector<Vector<int> >& sud)
//print out the sudoku
{

    assert(sud.size() == 6 && sud[0].size() == 6);
    
    cout << endl;
    //add a barrier at the top of the output
    cout << "+------+-------+" << endl; 
    for (int i = 0; i < 6; i++)
    {
        cout << "|"; 
        //seperate each section of 3x2 rectangles 
        for (int j = 0; j < 6; j++)
            if ((j + 1) % 3 == 0)
                if (sud[i][j] == 0)
                    cout << left << setw(2) << "_"
                         << "| ";
                else
                    cout << left << setw(2) << sud[i][j] << "| ";
            else 
                if (sud[i][j] == 0)
                cout << left << setw(2) << "_";
                //seperate each row and column 
                else
                    cout << left << setw(2) << sud[i][j];
        if ((i + 1) % 2 == 0)
            cout << endl
                << "+------+-------+" << endl;
                //bottom barrier, goe at end of all output 
        else
            cout << endl;
    }
    cout << endl;
    return;
}

bool test_sudoku(const Vector<Vector<int> >& sud)
{
    assert(sud.size() == 6 && sud[0].size() == 6);

    for (int i = 0; i < 6; i++){
        if (!row_1to6(i, sud))
            return false;
    }
    for (int i = 0; i < 6; i++){
        if (!col_1to6(i, sud))
            return false;
    }
    for (int i = 0; i < 6; i++){
        if (!rect_1to6(i, sud))
            return false;
    }
   return true;
}

//check each row to see if each has numbers 1-6 and no repeats 
bool row_1to6(int i, const Vector<Vector<int> >& sud)
{
    for (int k = 1; k <= 6; k++)
    {
        bool found = false;
        for (int j = 0; j < 6; j++)
        {
            if (k == sud[i][j])
            {
                found = true;
                break;
            }
        }
        if (!found)
            return false; // k not in row i
    }
    // pass: each k in{ 1..6 } was found in row i;
    return true;
}

//check each column to see if each has numbers 1-6 and no repeats 
bool col_1to6(int j, const Vector<Vector<int> >& sud)
{
    for (int k = 1; k <= 6; k++)
    {
        bool found = false;
        for (int i = 0; i < 6; i++)
        {
            if (k == sud[i][j])
            {
                found = true;
                break;
            }
        }
        if (!found)
            return false; // k not in col j
    }
    // pass: each k in{ 1..6 } was found in col j;
    return true;
}

//check each 3x2 rectangle to see if each has numbers 1-6 and no repeats 
bool rect_1to6(int n, const Vector<Vector<int> >& sud)
{
    Vector<int> rownos;
    Vector<int> colnos;
    rec_rows_cols(n, rownos, colnos);

    for (int k = 1; k <= 6; k++)
    {
        bool found = false;

        for (int i = 0; i < 2; i++)
        {
            int r = rownos[i];
            for (int j = 0; j < 3; j++)
            {
                int c = colnos[j];
                if (k == sud[r][c])
                {
                    found = true;
                    break;
                }
            }
            if (found)
                break;
        }
        if (!found)
            return false;
    }
    return true;
}


void rec_rows_cols(int n, Vector<int>& rownos, Vector<int>& colnos)
{
    assert(0 <= n && n < 6);
    
    Vector<int> rows01(2);
    rows01[0] = 0;
    rows01[1] = 2;
    Vector<int> rows23(2);
    rows01[0] = 2;
    rows01[1] = 3;
    Vector<int> rows45(2);
    rows01[0] = 4;
    rows01[1] = 5;
    Vector<int> cols012(3);
    cols012[0] = 0;
    cols012[1] = 1;
    cols012[2] = 2;
    Vector<int> cols345(3);
    cols345[0] = 3;
    cols345[1] = 4;
    cols345[2] = 5;

    if (n == 0)
    {
        rownos = rows01;
        colnos = cols012;
    }
    else if (n == 1)
    {
        rownos = rows01;
        colnos = cols345;
    }
    else if (n == 2)
    {
        rownos = rows23;
        colnos = cols012;
    }
    else if (n == 3)
    {
        rownos = rows23;
        colnos = cols345;
    }
    else if (n == 4)
    {
        rownos = rows45;
        colnos = cols012;
    }
    else
    {
        rownos = rows45;
        colnos = cols345;
    }
    return;
}