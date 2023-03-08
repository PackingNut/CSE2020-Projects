/*
 * Name: Ryan Calderon
 * File: magicSquare.cpp
 * 
 * Program to test a magic square program discussed in lecture wednesday 1/25
 * 
 * 
*/

#include <iostream>
#include<iomanip>
#include <cassert>
#include <vector>
#include <fstream> 
#include <math.h>

using namespace std;

//Program functions

void read_square(vector<vector<int> >&); 
void print_magic(const vector<vector<int> >&);
bool test_magic(const vector<vector<int> >&, int&);
int row_sum(int i, const vector<vector<int> >&);
int col_sum(int j, const vector<vector<int> >&);
int diag1_sum(const vector<vector<int> > &);
int diag2_sum(const vector<vector<int> > &);

int main(){
    vector <vector<int> > magicSQ;

    read_square(magicSQ); // add a vector to the read function that will be filled with values 
    print_magic(magicSQ); // Show the values in the vector

    int magicSum;
    if (test_magic(magicSQ, magicSum)) //This will test if the sum is magic or not 
    {
        cout << endl;
        cout << "Magic Test Passes and the magic sum is: " << magicSum << endl;


    }

    else 
    {
        cout << endl;
        cout << "Magic Test Fails" << endl;

    }

    return 0;
}

void read_square( vector<vector<int> >& square) 
//Pull the values from text files and put values in vectors
{

    ifstream inp; // create a stream to reaed from 
    vector<int> nums;
    inp.open("square11B.txt"); //Open the text file with the magic squares
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
        square.push_back(row);

    }
    return;

}

void print_magic(const vector<vector<int> >& mag) // print out the values of the vector 
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

//true if vector of vector is magic square: row sums,
// column sums and sums of both diagonals are the same;
// output arguement int& msum takes on value of that sum;

bool test_magic(const vector<vector<int> >& mag, int& msum) 
//int& msum is output parameter, is passed by reference 
{
    
    int dim = mag[0].size();
    int rsum = row_sum(0, mag); //The Row sum 

    for (int i = 1; i < dim; i++)
    {
        if(row_sum(i, mag) != rsum) //Function for the rum sums testing
        {
            return false;

        }
    }

    for(int i = 0; i < dim; i++)
    {
        if(col_sum(i, mag) != rsum){
            return false;  //Function to test column sums 

        }
    }
    if (diag1_sum(mag) != rsum || diag2_sum(mag) != rsum)
    {
        return false;
    }

    msum = rsum;
    return true;
}

// sum of i number row of mag

int row_sum(int i, const vector<vector<int> > & mag) 
{
    int dim = mag[0].size();
    int sum = 0;

    for(int j = 0; j < dim; j++)
    {
        sum += mag[i][j]; 
        //add each value from the magic square to the sum value
        //sum each row, i is row, j is column 

    }
    return sum;

}

// sum of jth column

int col_sum(int j, const vector<vector<int> >& mag)
{
    int dim = mag[0].size();
    int sum = 0;

    for(int i = 0; i < dim; i++) //Sum each column of the magic Square 
    {
        sum += mag[i][j];

    }
    return sum;

}

// sum of main diagonal

int diag1_sum(const vector<vector<int> >& mag)
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
int diag2_sum(const vector<vector<int> >& mag)
{
    int dim = mag[0].size(); //temp variable to hold the size value 
    int sum = 0; //sum variable 

    for(int i = dim - 1, j = 0; j < dim; i--, j++)
    {
        sum += mag[i][j]; //sum up the off diagonal values and store them

    }

    return sum;

}