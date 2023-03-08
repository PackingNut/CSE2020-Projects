
/*
 * Ryan Calderon
 * 007535509
 * 
 * Stack data structure adopted from the class lecture notes 
 * 
 * Approach Taken: Data structures Stack<T> and Queue<T> are implemented as 
 * adaptors of the vector or linked list data structures
*/

//Stack is implemented as an Adapter of another ADT



#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <cassert>
#include <algorithm>
#include "Vector.hpp"
#include "List.hpp"

using namespace std;

template <typename C>
//The data structure to hold the stack values is parameterized with placeholder
//C; Structure can be any structure C as long as C supports the functions below
/*
 * .size()
 * .empty()
 * .push_back()
 * .pop_back()
 * .back()
 * 
 * Must use these efficiently 
*/

class Stack
{
    public:

        //In order to refer to the type of data stored, we need a typedef for value_type
        typedef typename C::value_type value_type;

        Stack(){}

        int size() const
        {
            return thestack.size();
        }

        bool empty() const
        {
            return thestack.empty();
        }

        void push(const value_type& x)
        {
            thestack.push_back(x);
        }

        void pop()
        {
            thestack.pop_back();
        }

        value_type top()
        {
            return thestack.back();
        }
        
    private:
        C thestack;

};

#endif


