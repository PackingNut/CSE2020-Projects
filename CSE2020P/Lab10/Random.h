
#ifndef RANDOM_H_
#define RANDOM_H_

#include <cstdlib>
#include "Vector.h"
#include <ctime>
#include "List.h"

using namespace std;

void rand_seed();
int rand_int(int, int);
void random_vector(int, int, int, Vector<int>&, int);
void random_vector_norep(int, int, int, Vector<int>&, int);
void random_list(int, int, int, List<int>&, int);

#endif
