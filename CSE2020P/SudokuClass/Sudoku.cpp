
#include "Sudoku.h"

Sudoku::Sudoku()
{
    Sudok.clear();

    readFile();
    print_Sudo();

}
// Constructor

// Functions
void Sudoku::readFile()
{
    ifstream inp; // create a stream to reaed from 
    vector<int> nums;
    inp.open("Sudoku.txt"); //Open the text file with the magic squares
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
        Sudok.push_back(row);

    }
    return;

 }
bool Sudoku::testSudoku()
{
    for(int i = 0; i < 6; i++){
        if(!testRow(i)){
            return false;
        }
    }
    for(int i = 0; i < 6; i++){
        if(!testCol(i))
        {
            return false;
        }
    }
    for(int i = 0; i < 6; i++)
    {
        if(!testSect(i))
        {
            return false;
        }
    }
    return true;
}

void Sudoku::print_Sudo()
{
    cout << endl;
    for(int i = 0; i < Sudok.size(); i++) 
    //use vector size function to make a for print function
    {
        for(int j = 0; j < Sudok.size(); j++)
        {
            cout << left << setw(6) << Sudok[i][j] << " "; // test whether the value is zero or not 

        }
        cout << endl;
    }
    cout << endl;
    return;
}

bool Sudoku::testRow(int i)
{
    set<int> nums;
    for(int n = 0; n < 6; n++){

        if( 0 < Sudok[i][n] && Sudok[i][n] <= 6)
        {
            nums.insert(Sudok[i][n]);
        }

        else
        {
            return false;
        }
    
    }
    if(!(nums.size() == 6))
    {
        return false;
    }
    else{
        return true;
    }
}

bool Sudoku::testCol(int n)
{
    set<int> nums;
    for(int i = 0; i < 6; i++){

        if( 0 < Sudok[i][n] && Sudok[i][n] <= 6)
        {
            nums.insert(Sudok[i][n]);
        }

        else
        {
            return false;
        }
    
    }
    if(!(nums.size() == 6))    {
        return false;
    }
    else
    {
        return true;
    }
}

//Function to check each 2 by 3 section to see if 
//they contain numbers 1-6

bool Sudoku::testSect(int j)
{
    set<int> nums;
    for(int i = j/2*2; i <= j/2*2+1; i++)
    {
        for(int a = j*3%6; a <= j*3%6+2; a++){

        

            if(1 <= Sudok[i][a] && Sudok[i][a] <= 6)
            {
                nums.insert(Sudok[i][a]);
            }

            else
            {
                return false;
            }
        }
    
    }
    if(!(nums.size() == 6))    {
        return false;
    }
    else{
        return true;
    }
}

