#include <iostream>
#include "Vector.h"
#include "Random.h"
#include "BST_Set.h"

using namespace std; 

int main()
{
	rand_seed();
	Vector<int> numbers;
	random_vector(24, 1, 25, numbers, 0);  // keep range of numbers narrow
	Set<int> myset1;
	Set<int> myset2;

	// half the random numbers into myset1,
	// the other half into myset2;
	for (int i = 0; i < numbers.size(); i++)
	{
		if (i < numbers.size()/2)
			myset1.insert(numbers[i]);
		else
			myset2.insert(numbers[i]);
	}
	rand_seed();
	
	cout << endl << "Set1 with cardinality "
		<< myset1.cardinality() << ":" << endl;
	myset1.printSet();
	cout << endl;

	cout << endl << "Set2 with cardinality " 
		<< myset2.cardinality() << ":" << endl;
	myset2.printSet();
	cout << endl << endl;
	
	Set<int> myset3 = myset1.set_union(myset2);

	cout << "The union of Set1 and Set2 with cardinality "
		<< myset3.cardinality() << ":" << endl;
	myset3.printSet();
	cout << endl << endl;

	Set<int> myset4 = myset1.set_intersection(myset2);

	cout << "The intersection of Set2 and Set2 with cardinality "
		<< myset4.cardinality() << ":" << endl;
	myset4.printSet();
	cout << endl << endl;

	Set<int> myset5 = myset1.set_difference(myset2);
	
	cout << "The set difference Set1 - Set2 with cardinality " 
		<< myset5.cardinality() << ":" << endl;
	myset5.printSet();
	cout << endl << endl;

	Set<int> myset6 = myset2.set_difference(myset1);

	cout << "The set difference Set2 - Set1 with cardinality " 
		<< myset6.cardinality() << ":" << endl;
	myset6.printSet();
	cout << endl << endl;

	return 0;
}



