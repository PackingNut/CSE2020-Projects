/**
 * binary heap program header file implemented from module slides 8.2
 * from class.
 * 
*/


#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <cassert>
#include "Vector.h"

using namespace std;

/**
 * Binary Heap class
 * 
 * Construction: With an optional capacity(that defaults to 100)
 * *****************Public Operations***********
 * void insert(x)       --> Insert x
 * deleteMin(minItem)   --> Remove (optional return) smallest item
 * T findMin()          --> Finds and returns the smallest item
 * bool isEmpty()       --> Checks if the vector is empty, return true if it is empty, false otherwise
 * void makeEmpty()     --> Remove all items 
 * 
*/

template <typename T>
class BinaryHeap
{
    public:
        // constructor: empty heap with a capacity of 100 + 1
        BinaryHeap( int capacity = 100 ): theHeap( capacity + 1), theSize{0}
        {}

        //constructor: initialize with any Vector, vector will be converted to heap
        BinaryHeap(const Vector<T> & items): theHeap( items.size() + 10), theSize{ items.size() }
        {
            /*
            *   copy items to heap memory; 
            *   leave the field unoccupied at index 0
            */

           for(int i = 0; i < items.size(); ++i)
           {
                theHeap[i + 1] = items[i];

           }

           buildHeap();

        }

        bool empty() const{
            return theSize == 0;
        }

        //find smallest item in the heap
        const T & findMin() const{
            assert(!theHeap.empty());
            return theHeap[ 1 ];
        }

        //Insert item x, allowing duplicates;
        void insert(const T & x)
        {
            //resize our heap if need be
            if(theSize == theHeap.size() - 1)
            {
                theHeap.resize(theHeap.size() * 2);
            }
            int hole = theSize + 1; //index of new field 

            theSize++;

            T copy = x;
            //unused position 0 to hold new value until proper place found
            theHeap[0] = copy;

            //moving up parents as long as parent has larger value than x;
            // this is known as percolating up

            for(; x < (theHeap[hole] = theHeap[hole / 2]); hole /= 2)
            {
                theHeap[hole] = theHeap[hole / 2];
            }

            // drop new value into proper place;
            theHeap[hole] = theHeap[0];

        }

        //Remove the minimum item
        void deleteMin()
        {
            assert(!theHeap.empty());
            theHeap[1] = theHeap[theSize];
            theSize--;
            percolateDown(1);

        }

        //Remove the minimum items AND places it in output parameter minItem;

        void deleteMin(T & minItem)
        {
            assert(!theHeap.empty());
            minItem = theHeap[1];
            theHeap[1] = theHeap[theSize];
            theSize--;
            percolateDown(1);
        }

        void makeEmpty()
        {
            theSize = 0;
        }

        void print_heap()
        {

            cout << endl;
            if(empty())
            {
                cout << "Empty Heap";
            }
            else{
                print_heap(1,0);
            }
            cout << endl;
        }

    private:

        int theSize; //# of elements in heap
        Vector<T> theHeap;  //the heap theHeap

        //Establish heap order property from an arbitrary
        void buildHeap()
        {
            for ( int i = theSize / 2; i > 0; --i)
            {
                percolateDown(i);
                
            }
        }

        void print_heap(int index, int offset)
        {
            if(index > theSize)
            {
                return;
            }
            for(int i = 1; i <= offset; i++)
            {
                cout << " ";
            }

            cout << theHeap[index] << endl;
            print_heap(2 * index, offset + 1);
            print_heap(2 * index + 1, offset + 1);
        }

        void percolateDown(int hole)
        {
            int child;
            T temp = theHeap[hole];
            //finds the proper place for  a value at index hole

            for(; hole * 2 <= theSize; hole = child)
            // going down to next level of children(next row of branches)
            {
                child = hole * 2;

                if ( child != theSize && theHeap[child + 1] < theHeap[child])
                //child to be index of smaller-valued child
                {
                    ++child;
                }

                if(theHeap[child] < temp)
                {
                    theHeap[hole] = theHeap[child];
                    // potential new place for value temp moves down to smaller child
                }

                else
                {
                    break;
                    // proper place found here 
                }
                
            }
            theHeap[hole] = temp;
            // or proper place found here
        }

};










#endif