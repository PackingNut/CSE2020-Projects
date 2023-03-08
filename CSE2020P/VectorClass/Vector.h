/**
 * Vector Class header file
 * 
 * Ryan Calderon
 * 
*/


#ifndef VECTOR_H
#define VECTOR_H

#include<iostream>
#include <cassert> 
//Allows assert statements
#include <vector>
//To allow use of Vectors
#include <iomanip> 
//For formatting the output
#include <cstdlib> 
//needed for the use of swap.
#include<string>

//#define SPARE_CAPACITY 2 
//This define statement will do the exact same thing that the static const does
using namespace std;

template <typename T>

class Vector
{
    public: 

        static const int SPARE_CAPACITY = 2;

        Vector(int initSize = 0)
            : theSize(initSize),
              theCapacity(initSize + SPARE_CAPACITY)
        { data = new T[theCapacity]; } //object pointer
        // Create a pointer object using data pointer

        Vector(int initSize, int initVal) //is used when initial Size and value is given
            : theSize(initSize), //defines theSize
            //defines the values in this way, it is the "legit" way to do it
              theCapacity(initSize + SPARE_CAPACITY) //defines theCapacity
        {
            data = new T[theCapacity]; //object pointer
            //Adds values into the object pointer that we created
            for (int i = 0; i < theCapacity; i++)
            {
                data[i] = initVal;
            }

        }
        
        //copy constructor
        Vector(const Vector& rhs)
            : theSize(rhs.theSize)
            , theCapacity(rhs.theCapacity)
            , data ( nullptr )
        {
            data = new T[theCapacity]; //Object pointer
            for(int k = 0; k < theSize; ++k)
            //defines k value and adds one to it before it is used instead of after, ++ is used before the variable
            {
                data[k] = rhs.data[k];
            }
        }

        // copy assignment operator 
        Vector& operator = (const Vector& rhs)
        //const preserves the integrity of passed object
        {
            Vector copy = rhs; //equal copy to the rhs of the Vector
            std::swap(*this, copy); //swap the values of copy and the this pointer
            return *this; // return this pointer, points to self. it is an object itself

        }

        //move constructor
        Vector(Vector&& rhs)
            : theSize(rhs.theSize)
            , theCapacity(rhs.theCapacity) //This is our move contructor
            , data( rhs.data )
        {
            //set right hand side values to new values 
            rhs.data = nullptr; //a pointer that can't contain anything
            rhs.theSize = 0; //rhs size
            rhs.theCapacity = 0; //rhs capacity
        }

        //Move assignment operator
        Vector& operator = (Vector&& rhs)
        //This is out Move assign operator
        {
            std::swap(theSize, rhs.theSize); //change theSize value to the rhs value
            std::swap(theCapacity, rhs.theCapacity); //change theCapacity value to the rhs value
            std::swap(data, rhs.data); //change data value to the null pointer

            return *this; //return pointer
        }

        ~Vector()
        {
            delete[] data; //Class desctructor in order to save memory
            //needed in any class with pointer data
        }

        //const member functions are ACCESSOR functions

        bool empty() const
        {
            return size() == 0; 
        }
        //Accessor function to check whether or not the Vector is empty 

        int size() const
        {
            return theSize;
        }
        //Accessor function to return the number of elements in the current Vector 

        int capacity() const
        {
            return theCapacity;
        }
        //Accessor function to return the size of the current Vector

        T& operator[](int index)
        {
            assert (index >= 0 && index < theSize);
            return data[index];
            //data is an array using the size to be created
        }

        const T& operator[](int index) const
        {
            assert(index >= 0 && index < theSize);
            return data[index];
            //return the values index number in data array
        }
        
        void resize(int newSize)
        {
            if (newSize > theCapacity) 
            //checks if there is too many values trying to enter the Vector
            {
                reserve(newSize * 2); 
                //store the new size of the Vector?
            }
            theSize = newSize; //change the size! 

        }

        void reserve(int newCapacity)
        {
            if (newCapacity < theSize)
            {
                return;
            }

            T* newArray = new T[newCapacity];
            for (int k = 0; k < theSize; ++k)
            {
                newArray[k] = std::move(data[k]);
            }

            theCapacity = newCapacity;
            std::swap(data, newArray);
            delete[] newArray;
        }

        void push_back(const T& x)
        {
            if (theSize == theCapacity)
            {
                reserve(2 * theCapacity + 1);
            }
            data[theSize++] = x;
        }

        void pop_back()
        {
            assert(theSize >= 1);
            --theSize;
        }

        const T& back() const
        {
            assert(theSize >= 1);
            return data[theSize - 1];
        }

        void clear()
        {
            theSize = 0;
        }

        typedef T* iterator;

        typedef const T* const_iterator;

        iterator begin()
        {
            return &data[0];
        }

        const_iterator begin() const
        {
            return &data[0];
        }

        // Iterators new concept

        iterator end()
        {
            return &data[size()];
        }

        const_iterator end() const
        {
            return &data[size()];
        }
        
    private:
        int theSize; //How many things are in the Vector
        int theCapacity; //How large the Vector currently is 
        T* data; // pointer to private data member "data"
};
 
#endif