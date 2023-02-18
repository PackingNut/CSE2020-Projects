//File Hello.cpp("source file")


#include<iostream>
#include "Hello.h"

using namespace std;

void hello_world()
{
  cout << endl << endl;
  hello();
  world();
  cout << "\n\n";

  return;
  
}

void hello()
{
  cout << "Hello";
  return;
  
}

void world()
{
  cout << "World";
  return;
  
}