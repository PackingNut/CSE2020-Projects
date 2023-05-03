#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include "Vector.h"
#include "List.h"
#include "Random.h"
#include "HW3Searching.h"
using namespace std;

void data_table(Vector<Vector<int> >, string);

int main()
{
	Vector<Vector<int> > statsBSV;
	Vector<Vector<int> > statsBSL;

	rand_seed();
	for (int k = 50; k <= 250; k += 50)
	{
		Vector<int> row1, row2;

		row1.push_back(k);
		row2.push_back(k);

		cout << "*************************************" << endl;
		cout << "Data Set of Size: " << k << endl << endl;

		Vector<int> myvec;
		random_vector_norep(k, 1, 10000, myvec, 0);
		
		Vector<int> sortvec(myvec);
		sort(sortvec.begin(), sortvec.end());

		List<int> sortlst;
		for (int i = 0; i < sortvec.size(); i++)
			sortlst.push_back(sortvec[i]);
		
		Vector<int> targets;
		random_vector_norep(10, 0, myvec.size() - 1, targets, 0);
	
		int ops1 = 0;
		int ops2 = 0;

		for (int i = 0; i < targets.size(); i++)
		{
			ops1 = 0;
			ops2 = 0;

			int target = myvec[targets[i]]; 

			cout << "Searching for target " << target << endl << endl;

			binary_search_V(sortvec, target, ops1);
			binary_search_L(sortlst, target, ops2);

			row1.push_back(ops1);
			row2.push_back(ops2);

			cout << "binary_search_V: " << ops1 << " ops" << endl;
			cout << "binary_search_L: " << ops2 << " ops" << endl;
			cout << endl;
		}
		
		statsBSV.push_back(row1);
		statsBSL.push_back(row2);
	}

	cout << endl << endl;
	data_table(statsBSV, "Binary Search of Vector");
	cout << endl << endl;
	data_table(statsBSL, "Binary Search of List");

	return 0; 
}

void data_table(Vector<Vector<int> > data, string title)
{
	cout << title << ":" << endl << endl;

	cout << setw(8) << 1;
	for (int i = 2; i < data[0].size(); i++)
		cout << setw(4) << i;
	cout << endl;
	for (int i = 1; i <= 8 + (data[0].size() - 1) * 4; i++)
		cout << "-";
	cout << endl;

	for (int i = 0; i < data.size(); i++)
	{
		for (int j = 0; j < data[i].size(); j++)
			cout << setw(6) << data[i][j];
		cout << endl;
	}
	cout << endl << endl;
	return;
}