/**
 * name: Ryan calderon
 * 
 * file: lab 2 main file 
 * 
 * This file is the where the main code will go for 
 * our Magic Square object orientated program
 * 
*/

#include "Magic.h"
#include "Magic.cpp"


using namespace std;

int main()
{
    magicSquare myMagic; //declare and generate magic square
    myMagic.print_magic();

    if(myMagic.test_magic())
    {
        cout << endl;
        cout << "Magic Test Passes and the sum is "
                << myMagic.magic_sum() << endl;

    }

    else{
        cout << endl;
        cout << "Magic Test Fails" << endl;
        
    }

    return 0;

}