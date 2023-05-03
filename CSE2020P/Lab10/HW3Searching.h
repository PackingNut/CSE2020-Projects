/**
 * 
 * Name: Ryan Calderon
 * File: HW3Searching.h
 * 
 * this file defines the binary search function for Vector class
 * 
*/


#ifndef HW3SEARCHING_H
#define HW3SEARCHING_H
#include "Vector.h"
#include "List.h"

template <typename T>
int binary_search_V(const Vector<T>& vec, const T& target, int& ops)
{
    ops = 0;
    int low = 0;
    int high = vec.size() - 1;
    while(low <= high)
    {
        ops++;
        int mid = (low + high) / 2;
        if(vec[mid] < target)
        {
            low = mid + 1;
        }
        else if( vec[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return - 1;

}

template <typename T>
typename List<T>::const_iterator binary_search_L(const List<T>& lst, const T& target, int& ops)
{
    ops = 0;
    int low = 0;
    int high = lst.size() - 1;
    int mid;

    typename List<T>::const_iterator itr;

    while(low <= high)
    {
        ops++;
        mid = (low + high) / 2;
        itr = lst.begin();
        for (int i = 0; i < mid; i++)
        {
            itr++;
            ops++;
        }
        if(*itr == target) //will capture matching case 
        {
            return itr;
        }
        if(*itr > target) //*itr points to mid point(where our binary search starts)
        {
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return lst.end();
    
}

#endif