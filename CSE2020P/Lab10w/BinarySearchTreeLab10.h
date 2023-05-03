// PARTIAL implementation of BinarySearchTree
// insert and printing only
// version for Lab10 ..

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <cassert>
#include "Vector.h"
using namespace std;       


template <typename T>
class BinarySearchTree
{
private:
    struct BinaryNode
    {
        T element;
        BinaryNode* left;
        BinaryNode* right;

        BinaryNode(const T& theElement, BinaryNode* lt, BinaryNode* rt)
            : element(theElement), left(lt), right(rt)
        {}

        BinaryNode(const T&& theElement, BinaryNode* lt, BinaryNode* rt)
            : element( std::move(theElement) ), left(lt), right(rt)
        {}
    };
    // BinaryNode *root;


 public:
	 
	BinarySearchTree( ) : root(0) {}

    ~BinarySearchTree( )
    {
        makeEmpty( );
    }

    bool isEmpty( ) const
    {
        return root == 0;
    }

    void insert(const T& x)
    {
        // calls private insert ... 
        insert(x, root);     // ==> LAB 10: add private fct from Module 6.2
    }

    // LAB 10: print all elements (values) in line

    void printElements() const
    {
        if( isEmpty( ) )
            cout << "Empty tree" << endl;
        else
            printElements( root);  // => LAB 10: define private fct below
    }

    // LAB 10: returns number of elements in BST 

    int size() const
    {
        return size(root);  // LAB 10: define private fct below
    }

	void printInternal() const
	{
		if (isEmpty())
			cout << "Empty tree" << endl;
		else
			printInternal(root, 0);
	}

    // for destructor to call...
    void makeEmpty( )
    {
        makeEmpty( root );
    }

private:

    BinaryNode *root;


    //the private member fcts that do all the work...
   
    void insert( const T & x, BinaryNode * & t)
    {
	   // LAB 10: COMPLETE 
       if(t == nullptr)
       {
        t = new BinaryNode{x, nullptr, nullptr};
       }
       else if(x < t-> element)
       {
        insert(x, t -> left);
       }
       else if(x > t -> element)
       {
        insert (x, t -> right);
       }
       else 
       {
        ;
       }
    }
 
    void makeEmpty( BinaryNode * & t )
    {
        if( t != 0 )
        {
            makeEmpty( t->left );
            makeEmpty( t->right );
            delete t;
        }
        t = 0;
    }

	void printInternal(BinaryNode *t, int offset) const
	{
		for (int i = 1; i <= offset; i++)
			cout << "..";
		if (t == 0)
		{
			cout << "#" << endl; //prints this out when a lhs value doesn't exist
			return;
		}
		cout << t->element << endl;
		printInternal(t->left, offset + 1);
		printInternal(t->right, offset + 1);
		return;
	}

    // LAB 10: COMPLETE; to print in-line all elements in BST rooted in t;

    void printElements(BinaryNode* t) const
    {
        if (t != 0) //if root is not zero then print elements
        {
            // print the elements of the left subtree
            printElements(t->left);

            // print the element under pointer t
            cout << t -> element << " "; 

            // print the elements of the right subtree
            printElements(t->right);
        }
    }


    // LAB 10: COMPLETE; returns the number of elements  stored in BST 
    //rooted in t; 

    int size(BinaryNode* t) const
    {
        //return -1; // temp place holder for the actual code
        //changing the placeholder for lab 10
        if(t == 0)
        {
            return 0;
        }
        else if(t -> left == nullptr && t -> right == nullptr)
        {
            return 1;
        }//happens if the function is called upon

        else if(t -> left == nullptr && t -> right != nullptr)
        {
            return size(t -> right) + 1;
            //catch right hand values
        }

        else if(t -> left != nullptr && t -> right == nullptr)
        {
            return size(t->left) + 1;
            //catch left hand values
        }

        else 
        {
            return size(t -> left) + size(t -> right) + 1;
            //whatever values are missed by the above else statments will get caught here
        }
    }

};





#endif