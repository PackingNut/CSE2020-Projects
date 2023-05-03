// BST_Set.h        NEW VERSION
// by KV, Spring 2023, for CSE 2020;
// with additions to to copy constructor to properly handle parent pointers
// essentially class BinarySearchTree with iterators

#ifndef BSTSET_H
#define BSTSET_H

#include <algorithm>
#include <cassert>
using namespace std;

template <typename T>
class Set
{
private:
    class BinaryNode
    {
    public:
        T element;          // holds data in a node
        BinaryNode *left;   // this is a link that holds left hand value
        BinaryNode *right;  // this is a link that holds right hand value
        BinaryNode *parent; // added to support iterators

        BinaryNode(const T &theElement, BinaryNode *lt, BinaryNode *rt)
            : element(theElement), left(lt), right(rt), parent(nullptr) {}
        // if parent is not given then the value will be nullptr

        BinaryNode(const T &theElement, BinaryNode *lt, BinaryNode *rt,
                   BinaryNode *par)
            : element(theElement), left(lt), right(rt), parent(par) {}
        // if all values are given thne they are initialized like this
    };

public:
    class const_iterator
    {
    public:
        const_iterator() : current{nullptr}
        {
        }

        const_iterator(BinaryNode *x) : current(x)
        {
        }

        const_iterator(const const_iterator &rhs)
        //this copies whatever the current pointer is looking at
            : current(rhs.current)
        {
        }

        //assignment operator
        const_iterator &operator=(const const_iterator &rhs)
        {
            current = rhs.current;
            return *this;
        }

        T operator*() const //accessor to grab element inside node
        {
            return current->element;
        }

        //prefix increment
        const_iterator& operator++()
        {
            go_to_next();
            return *this;
        }

        //apostfix increment 
        const_iterator operator++(int)
        {
            const_iterator old = *this;
            ++(*this);
            return old;
        }

        bool operator==(const const_iterator &rhs) const
        {
            return current == rhs.current;
        }

        bool operator!=(const const_iterator &rhs) const
        {
            return !(*this == rhs);
        }

    protected:
        BinaryNode *current; 
        //out iterator pointer

        void go_to_next()
        {
            if (current == nullptr)
                return;

            T currval = current->element;
            if (current->right == nullptr)
            {
                // current node has no right subtree
                // go to closest larger valued ancester
                current = current->parent;
                while (current != nullptr && current->element < currval)
                    current = current->parent;
                return;
            }
            // current node has right subtree
            // go leftmost in that subtree
            current = current->right;
            while (current->left != nullptr)
                current = current->left;
            return;
        }

        friend class Set<T>;
    }; // end class const_iterator

public:
    Set() : root(nullptr) {}

    Set(const Set &rhs) : root(nullptr)
    {
        if (rhs.root != nullptr)
        {
            root = new BinaryNode(rhs.root->element, nullptr, nullptr, nullptr);
            root->left = clone(rhs.root->left, root);
            root->right = clone(rhs.root->right, root);
            //don't have to worry about parent because of the clone function 
        }
    }

    ~Set()
    {
        makeEmpty();
    }

    //copy assignment operatopr
    Set &operator=(const Set &rhs)
    {
        root = nullptr;
        if (rhs.root != nullptr)
        {
            root = new BinaryNode(rhs.root->element, nullptr, nullptr, nullptr);
            root->left = clone(rhs.root->left, root);
            root->right = clone(rhs.root->right, root);
        }
        //constructs a new one and returns this

        return *this;
    }

    //leftmost node
    const T &findMin() const
    {
        assert(!isEmpty());
        return findMin(root)->element;
    }

    //right most node
    const T &findMax() const
    {
        assert(!isEmpty());
        return findMax(root)->element;
    }

    bool contains(const T &x) const
    {
        return contains( x, root );
    }

    bool isEmpty() const
    {
        return root == nullptr;
    }

    void printSet() const
    {
        if (isEmpty())
            cout << "Empty Set" << endl;
        else
            printSet(root);
    }

    void printInternal() const
    {
        if (isEmpty())
            cout << "Empty tree" << endl;
        else
            printInternal(root, 0);
    }

    void makeEmpty()
    {
        makeEmpty(root);
    }

    void insert(const T &x)
    {
        insert(x, root, root);
    }

    void remove(const T &x)
    {
        remove(x, root);
    }

    // BST iterators

    const_iterator begin() const
    {
        BinaryNode *beg = leftmost(root);
        const_iterator itr(beg);
        return itr;
    }

    //past the last value, its always nullptr
    const_iterator end() const
    {
        const_iterator itr(nullptr);
        return itr;
    }

    //return the size of the set
    int cardinality() const
    {
        return cardinality(root);
    }

    // LAB 11 work
    // union, intersect, and difference member facts;

    Set<T> set_union(const Set &rhs)
    {
        Set<T> set3;

        // COMPLETE
        //gathering of all elements
        set3 = *this;

        const_iterator itr = rhs.begin();
        while(itr != end())
        {
            set3.insert(*itr); //call on insert member func
            itr++;
        }

        return set3;
    }

    Set<T> set_intersection(const Set &rhs)
    {
        Set<T> set3;

        // COMPLETE

        const_iterator itr = rhs.begin();
        while(itr != end())
        {
            if(this -> contains(*itr))
            {
                set3.insert(*itr);
            } //call on insert member func
            itr++;
        }

        return set3;
    }

    Set<T> set_difference(const Set &rhs)
    {
        Set<T> set3;

        // COMPLETE
        set3 = *this;
        const_iterator itr = rhs.begin();
        while(itr != end())
        {
            if(this -> contains(*itr))
            {
                set3.remove(*itr);
            }
            itr++;
        }

        return set3;
    }

private:

    BinaryNode *root; // this is our only data member

    //make use of the binary search tree
    void insert(const T &x, BinaryNode *& t, BinaryNode *& par)
    {
        if (t == nullptr)
        {
            t = new BinaryNode(x, nullptr, nullptr, par);
        }
        //creates a spot for a value then insert to correct spot
        else if (x < t->element)
            insert(x, t->left, t);

        else if (t->element < x)
            insert(x, t->right, t);

        else
            ; // Duplicate; do nothing
    }

    void remove(const T &x, BinaryNode *&t)
    {
        if (t == nullptr)
            return; // Item not found; do nothing

        if (x < t->element)
            remove(x, t->left);

        else if (t->element < x)
            remove(x, t->right);

        //if left and/or right are not nullptr the least of the two will become T
        else if (t->left != nullptr && t->right != nullptr) // Two children
        {
            t -> element = findMin(t -> right) -> element;
            remove(t->element, t->right);
        }

        else
        {
            BinaryNode *oldNode = t;
            // t = ( t->left != nullptr ) ? t->left : t->right;
            if (t->left != nullptr)
            {
                t->left->parent = t->parent;
                t = t->left;
            }
            else
            {
                if (t->right != nullptr)
                    t->right->parent = t->parent;
                t = t->right;
            }
            delete oldNode;
        }
    }

    BinaryNode *findMin(BinaryNode *t) const
    {
        if (t == nullptr)
            return nullptr;
        if (t->left == nullptr)
            return t;
        return findMin(t->left);
    }

    BinaryNode *findMax(BinaryNode *t) const
    {
        if (t != nullptr)
            while (t->right != nullptr)
                t = t->right;
        return t;
    }

    bool contains(const T &x, BinaryNode *t) const
    {
        if (t == nullptr)
            return false;
        else if (x < t->element)
            return contains(x, t->left);
        else if (t->element < x)
            return contains(x, t->right);
        else
            return true; // Match
    }

    void makeEmpty(BinaryNode *&t)
    {
        if (t != nullptr)
        {
            makeEmpty(t->left); //calls on member func
            makeEmpty(t->right); // calls on member func 
            delete t;
        }
        t = nullptr;
    }

    void printSet(BinaryNode *t) const
    {
        if (t != nullptr)
        {
            printSet(t->left);
            cout << t->element << " "; // endl;
            printSet(t->right);
        }
    }

    //keeps track of tips
    void printInternal(BinaryNode *t, int offset) const
    {
        for (int i = 1; i <= offset; i++)
            cout << "..";
        if (t == nullptr)
        {
            cout << "#" << endl;
            return;
        }
        cout << t->element << endl;
        printInternal(t -> left, offset + 1);
        printInternal(t -> right, offset + 1);
        return;
    }

    // new clone function that works:
    BinaryNode *clone(BinaryNode *toclone, BinaryNode* parent)
    {
        //check if clone is empty
        if (toclone == nullptr)
            return nullptr;

        //if it is not empty this node will be created
        BinaryNode *cl = new BinaryNode(toclone -> element, nullptr, nullptr, parent);
        cl -> left = clone(toclone -> left, cl);
        cl -> right = clone(toclone -> right, cl);
        return cl;
    }

    // added for const_iterator implementation;

    BinaryNode* leftmost(BinaryNode* t) const
    {
        if (t != nullptr)
            while (t -> left != nullptr)
                t = t -> left;
        return t;
    }

    int cardinality(BinaryNode *t) const
    {
        if (t == nullptr)
            return 0;
        if (t -> left == nullptr and t -> right == nullptr)
            return 1;
        return 1 + cardinality(t -> left) + cardinality(t -> right);
    }
};

#endif
