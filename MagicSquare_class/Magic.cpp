/**
 * Name: Ryan Calderon
 * File: Class definition file for class functions and data
 * 
 * 
*/

#include "Magic.h"

using namespace std;

magicSquare::magicSquare()

{
    //initialize
    dim = 0;
    magicSum = 0;
    mag.clear();

    read_square();
    dim = mag[0].size();
    //magicSum = row_sum(0);

}

void magicSquare::read_square() 
//Pull the values from text files and put values in vectors
{

    ifstream inp; // create a stream to read from 
    vector<int> nums;
    inp.open("square11A.txt"); //Open the text file with the magic squares
    int next; // temp variable to help add values 

    inp >> next;
    while(!inp.fail())
    {
        nums.push_back(next); //Add each value to the vector one by one 
        inp >> next;

    }
    inp.close(); //Close the stream 

    assert(sqrt(nums.size()) == floor(sqrt(nums.size())));
    //Test the size of the magic square

    int n = static_cast<int>(sqrt(nums.size()));

    int k = 0;

    for (int i = 0; i <= n; i++)
    {
        vector <int> row;
        for(int j = 1; j <= n; j++) //add values to row vector
        {
            row.push_back(nums[k]);
            k++;

        }
        mag.push_back(row);

    }
    return;

}

void magicSquare::print_magic()
{

    cout << endl;

    for(int i = 0; i < mag.size(); i++) 
    //use vector size function to make a for print function
    {
        for( int j = 0; j < mag.size(); j++){
            if(mag[i][j] == 0){
                cout << left << setw(6) << "~" << "  " ; // test whether the value is zero or not 
            }

            else {
                cout << left << setw(6) << mag[i][j] << "  "; //spaces out the printed values
            }
        }
        cout << endl;

    }
    cout << endl;
    return;
}

bool magicSquare:: test_magic()
{
    //int dim = mag[0].size();
    int rsum = row_sum(0); //The Row sum 

    for (int i = 1; i < dim; i++)
    {
        if(row_sum(i) != rsum) //Function for the rum sums testing
        {
            return false;

        }
    }

    for(int i = 0; i < dim; i++)
    {
        if(col_sum(i) != rsum){
            return false;  //Function to test column sums 

        }
    }
    if (diag1_sum() != rsum || diag2_sum() != rsum)
    {
        return false;
    }

    magicSum = rsum;
    return true;

}

int magicSquare::row_sum(int i)
{
    // No longer need these int dim = mag[0].size();
    int sum = 0;

    for(int j = 0; j < dim; j++)
    {
        sum += mag[i][j]; 
        //add each value from the magic square to the sum value
        //sum each row, i is row, j is column 

    }
    return sum;
}

int magicSquare::col_sum(int j)
{
    //int dim = mag[0].size();
    int sum = 0;

    for(int i = 0; i < dim; i++) //Sum each column of the magic Square 
    {
        sum += mag[i][j];

    }
    return sum;

}

// sum of main diagonal

int magicSquare::diag1_sum()
{
    int dim = mag[0].size(); //temp variable to hold the size 
    int sum = 0; //Sum variable 
    for(int i = 0; i < dim; i++)
    {
        sum += mag[i][i]; //sum up the diagonal values of the main diagonal 

    }
    return sum;

}

// sum of off diagonal
int magicSquare::diag2_sum()
{
    int dim = mag[0].size(); //temp variable to hold the size value 
    int sum = 0; //sum variable 

    for(int i = dim - 1, j = 0; j < dim; i--, j++)
    {
        sum += mag[i][j]; //sum up the off diagonal values and store them

    }

    return sum;

}

int magicSquare::magic_sum()
{

    return magicSum;
    

}