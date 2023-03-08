
/**
 * 
 * Ryan Calderon
 * 007535509
 * 
 * File: Postfix.h
 * Header file for the post fix calculator 
 * 
*/

#ifndef POSTFIX_H_
#define POSTFIX_H_

#include <iostream>
#include <string>
#include <sstream>
#include <cassert>
#include <cctype>
#include "Stack.hpp"
#include "Vector.hpp"

using namespace std;

int eval_postfix(string);
bool is_operator(string);
int string_to_integer(string);
int apply_op(string, int, int);

#endif