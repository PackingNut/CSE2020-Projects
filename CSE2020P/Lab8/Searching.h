/**
 * Ryan Calderon
 * 
 * file: searching.h 
 * 
 * File required for lab 8 to work
 * 
*/

#ifndef SEARCHING_H
#define SEARCHING_H
#include "Vector.h"
#include "List.h"


//return index at which target found, if not found
//return -1;

template <typename T>
//linear search of a linear data structure with random access
int linear_search_V(const Vector <T>& vec, const T& target)
{
    for(int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == target)
        {
            return i;
        }
    }
    return -1; // means not found
}

//linear search of a linear data structure with iterators
//without random access: iterators used to access positions
// and extract stored values 
//exists for c++ Vectors and Lists: Container<T>::iterator

/**
 * return iterator under which target is found in Lst;
 * else return end() iterator;
 * 
*/

template <typename T>
typename List<T>::const_iterator linear_search_L(const List<T>& lst, const T& target)
{
    typename List<T>::const_iterator itr;

    for(itr = lst.begin(); itr != lst.end(); ++itr)
    {
        if(*itr == target)
        {
            return itr;
        }
    }
    return lst.end(); //not found
}

template <typename T>
int rec_linear_search_V(int k, const Vector<T> vec, const T& target)
{
    if(vec.empty()|| k >= vec.size())
    {
        return -1;
    }
    else if (vec[k] == target)
    {
        return k;
    } 
    return rec_linear_search_V(k + 1, vec, target);
}

template <typename T>
typename List<T>::const_iterator rec_linear_search_L(
    typename List<T>::const_iterator itr, 
    const List<T>& lst,
    const T& target)
{
    if(lst.empty() || itr != lst.end())
    {
        return lst.end();
    }
    else if(*itr == target)
    {
        return itr;
    }
    return rec_linear_search_V(++itr, lst, target);
}



#endif
