// Lab10Main.cpp
// KV for CSE 2020 in Spring 2023

#include <iostream>
#include "BinarySearchTreeLab10.h"  // completed version
#include "Random.h"
using namespace std;

int main()
{
	rand_seed();
	BinarySearchTree<int> mybst;
	int how_many;
	cout << "How many random values? ";
	cin >> how_many;
	cout << endl << endl;


	for (int i = 1; i <= how_many; i++)
	{
		mybst.insert(rand_int(1, 250));
	}
	cout << endl << how_many << " values entered" << endl << endl;

	cout << "Here are the current values: " << endl;
	mybst.printElements();
	cout << endl << endl;

	cout << "Here is the structure of the BST: " << endl;
	mybst.printInternal();
	cout << endl << endl;

	cout << "Number of values contained in BST: " << mybst.size();
	cout << endl << endl;
	
	return 0;
}