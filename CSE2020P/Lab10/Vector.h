

#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <cstdlib>
#include <iostream>
#include <cassert>

#define SPARE_CAPACITY 2

using namespace std;

template <typename T>

class Vector
{

public:
	// for stack
	typedef T value_type;

	// general constructor defaults size = 0, otherwise sets size and capacity
	explicit Vector(int init_size = 0) : the_size(init_size), the_capacity(init_size + SPARE_CAPACITY)
	{
		data = new T[the_capacity];
	}

	// constructor that inits all numbers to given number
	Vector(int init_size, int init_val) : the_size(init_size), the_capacity(init_size + SPARE_CAPACITY)
	{
		data = new T[the_capacity];
		for (int i = 0; i < the_capacity; i++)
		{
			data[i] = init_val; // for loop goes through and sets all values to init_val
		}
	}

	// copy constructor
	Vector(const Vector &rhs) : the_size(rhs.the_size), the_capacity(rhs.the_capacity), data(nullptr)
	{
		// need new storage for new Vector, and to use for loop to copy over
		data = new T[the_capacity];
		for (int i = 0; i < the_size; i++)
		{
			data[i] = rhs.data[i];
		}
	}

	// assignment constructor
	Vector &operator=(const Vector &rhs)
	{
		Vector copy = rhs;
		std::swap(*this, copy);
		return *this;
	}

	// move constructor
	Vector(Vector &&rhs) : the_size(rhs.the_size), the_capacity(rhs.the_capacity), data(rhs.data)
	{
		rhs.data = nullptr; // defaults
		rhs.the_size = 0;
		rhs.the_capacity = 0;
	}

	Vector& operator = (Vector &&rhs)
	{
		swap(the_size, rhs.the_size);
		swap(the_capacity, rhs.the_capacity);
		swap(data, rhs.data);

		return *this;
	}

	~Vector()
	{
		delete[] data;
	}

	bool empty() const
	{
		return size() == 0;
	}

	int size() const
	{
		return the_size;
	}

	int capacity() const
	{
		return the_capacity;
	}

	T &operator[](int index)
	{
		assert(index >= 0 && index < the_size);
		return data[index];
	}

	const T &operator[](int index) const
	{
		assert(index >= 0 && index < the_size);
		return data[index];
	}

	void resize(int new_size)
	{
		if (new_size > the_capacity)
		{
			reserve(new_size * 2);
		}
		the_size = new_size;
	}

	void reserve(int new_capacity)
	{
		if (new_capacity < the_size)
		{
			return;
		}

		T *new_array = new T[new_capacity];
		for (int i = 0; i < the_size; i++)
		{
			new_array[i] = move(data[i]);
		}

		the_capacity = new_capacity;
		swap(data, new_array);
		delete[] new_array;
	}

	void clear()
	{
		the_size = 0;
	}

	void push_back(const T &x)
	{
		if (the_size == the_capacity) // if out of capacity, reserve more
			reserve(2 * the_capacity + 1);
		data[the_size++] = x;
	}

	void push_back(T&& x)
	{
		if(the_size == the_capacity)
		{
			reserve(2 * the_capacity + 1);

		}
		data[the_size++] = std::move(x);
	}

	void pop_back()
	{
		assert(the_size >= 1);
		--the_size;
	}

	const T &back() const
	{
		assert(the_size >= 1);
		return data[the_size - 1];
	}

	// print statement

	void print_vec()
	{
		for (int i = 0; i < the_size; i++)
		{
			cout << data[i] << " ";
		}
	}

	// iteratorators
	typedef T *iterator;
	typedef const T *const_iterator;

	iterator begin()
	{
		return &data[0];
	}

	const_iterator begin() const
	{
		return &data[0];
	}

	iterator end()
	{
		return &data[size()];
	}

	const_iterator end() const
	{
		return &data[size()];
	}

	// erase using index

	void erase(int index)
	{
		assert(index >= 0 && index < the_size);
		if (index == the_size - 1)
		{
			pop_back();
			return;
		}
		for (int i = index + 1; i < the_size; i++)
		{
			data[i - 1] = data[i];
		}
		pop_back();
		return;
	}

	void erase(iterator itr) // erase at itr
	{
		if (itr == end() - 1)
		{ // if itr at end of vect just popback
			pop_back();
			return;
		}
		iterator copy_itr = nullptr; // ctrl fer for loop
		for (copy_itr; itr < end(); itr++)
		{
			copy_itr = (itr++);
			itr = copy_itr;
		}
		// take's code (works confirmed)
		// for(iteratorator i = itr; i < end(); i++)
		//*i = *(i + 1)
		pop_back();
		return;
	}

	// insert at index

	void insert(int index, int value) // FINISHED
	{
		// insert at end case uno
		if (index == the_size - 1)
		{
			push_back(value);
			return;
		} // should be working
		// end value over to make space for move and insert
		int num_store = the_size - 1;
		push_back(num_store); // copy end value over one space using push_back
							  // up to here should be working
		//  put indexer at the first value to be moved over by while loop which was
		//  the OLD the_size - 2 needs -3 now
		int indxr = the_size - 3;
		while (indxr >= index)
		{
			data[indxr + 1] = data[indxr];
			indxr--;
		}
		data[index] = value;
		return;
	}

	// insert at iteratorator

	void insert(iterator itr, int value)
	{
		if (itr == end())
		{
			push_back(value);
			return;
		}
		assert(itr >= begin() && itr < end());
		push_back(back());
		iterator itr1 = end() - 2;
		iterator itr2 = end() - 1;
		while (itr1 >= itr)
		{
			*itr2 = *itr1;
			itr1--;
			itr2--;
		}
		*itr = value;
		return;
	}

private:
	int the_size;
	int the_capacity;
	T *data;
};

#endif

// time for the class
