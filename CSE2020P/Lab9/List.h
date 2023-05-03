
/**
 * Name: Ryan Calderon
 * 007535509
 * 
 * File: List.h
 * 
 * This is the iintialization of the List Class data structure
 * in this file the list class and its innner classes are defined 
 * 
*/

#ifndef LIST_H
#define LIST_H

#include<algorithm>
#include <utility>

using namespace std;

template <typename T>

class List
{
    private:
        //the basic doubly linked list node.
        //Nested inside of list can be public 
        //because the Node is itself private
        struct Node //struct can have constructor like classes
        {
            T data;
            Node *prev;
            Node *next;

            Node(const T & d = T{ }, Node * p = nullptr, Node * n = nullptr)
                : data{ d }, prev{ p }, next{ n } { }


        };

    public:

        typedef T value_type;

        //Defined within class List ... an
        //iterator class which defines
        //iterators suited to referencing 
        //list items that are const (= not mutable)

        class const_iterator
        {
            public:
                //public constructor for const_iteratr.
                const_iterator() : current{ nullptr }
                    { }
                const T & operator* ( ) const
                    { return retrieve( ); }
                
                const_iterator & operator++ ( )
                {
                    current = current -> next;
                    return *this;
                    //*this is an object pointer

                }
                const_iterator operator++ (int)
                {
                    const_iterator old = *this;
                    ++(*this);
                    return old;
                }
                //iterator member functions set pointer current to
                //Nodes of list class and moves the pointer along
                //node's prev. and current pointers
                const_iterator & operator--()
                {
                    current = current -> prev;
                    return *this;
                }

                const_iterator operator-- (int)
                {
                    const_iterator old = *this;
                    --(*this);
                    return old;
                }



                bool operator == (const const_iterator & rhs) const
                    { return current == rhs.current; }

                bool operator != ( const const_iterator & rhs) const
                    { return !( *this == rhs); }

                protected:
                    Node *current;

                    T & retrieve ( ) const
                        { return current -> data; }

                    const_iterator( Node *p ): current{ p }
                        {}
                    
                    friend class List<T>;
        };

        //this is the class "class iterator" it is a sub class

        class iterator: public const_iterator 
        //derived class from iterator class
        {
            public:

                iterator ( )
                    { }
                
                T & operator* ()
                    {return const_iterator::retrieve();}

                const T & operator* () const
                    { return const_iterator::operator*();}
                
                iterator & operator++ ()
                {
                    this->current = this->current->next;
                    return *this;
                }

                iterator operator++ (int)
                {
                    iterator old = *this;
                    ++( *this );
                    return old;
                }

                iterator & operator-- ()
                {
                    this->current = this->current->prev;
                    return *this;
                }

                iterator operator-- (int)
                {
                    iterator old = *this;
                    --(*this);
                    return old;
                }

            //data memeber is adopted from class const_iterator
            protected: 
                iterator( Node *p ) : const_iterator{p}
                    {}
                
                friend class List<T>;
                //our code is more likely to use this class^
        };

    //Actual implementation of the List class
    public: 
        List()
            {init();}
        
        ~List()
        {
            clear();
            delete head;
            delete tail;

        }

        List(const List & rhs)
        {
            init();
            /*KV's cut out*/
            for(auto & x : rhs)
            {
                push_back(x);
            }
            
           //more generic definition
           /*const_iterator itr = rhs.begin();

           for(; itr != rhs.end(); ++itr)
           {
            push_back(*itr);
           }
           */
        }

        //regular assignment operator has only one & sign
        List & operator = (const List & rhs)
        {
            List copy = rhs;
            swap(*this, copy);
            return *this;
        }

        //move constructor definition; has two && signs
        List(List&& rhs)
            : theSize{rhs.theSize}, head{rhs.head}, tail{rhs.tail}
        {
            rhs.theSize = 0;
            rhs.head = nullptr;
            rhs.tail = nullptr;

        }

        //keep  for compiler
        //move assignment operator; has two && signs
        List& operator = (List&& rhs)
        {
            swap(theSize, rhs.theSize);
            swap(head, rhs.head);
            swap(tail, rhs.tail);

            return *this;
        }

        //clear the list by removing all values 

        void clear()
        {
            while(!empty())
            {
                pop_front();
            }
        }

        iterator insert(iterator itr, const T & x)
        {
            Node *p = itr.current;
            ++theSize;
            return{ p->prev = p->prev->next = new Node{x, p->prev, p}};
        }

        iterator erase(iterator itr)
        {
            Node *p = itr.current;
            iterator retVal(p->next);
            p->prev->next = p->next;
            p->next->prev = p->prev;
            delete p;
            --theSize; //decrement to error

            return retVal;
        }

        //return iterator representing beginning of list 
        //mutator version is first, then accessor version 
        iterator begin()
        {
            return iterator(head -> next); //mutator
        }

        const_iterator begin() const
        {
            return const_iterator(head->next);//accessor
        }
        /*Front of List: notice how
        iterator(head->next) sets
        pointer current of
        iterator to the Node next
        to head; the first Node
        with value */

        //return iterator that represents the end of the list
        //mutator is first then the accessor 
        
        iterator end()
        {
            return iterator(tail);
        }

        const_iterator end() const
        {
            return const_iterator(tail);
        }

        /*Back of List: notice how iterator(tail) sets pointer current 
        of iterator to the very last Node, which does NOT contain any 
        value.*/

        //Return how many elements currently in list 
        int size() const 
        {
            return theSize;
        }

        //check if the list is empty, true if it is, false otherwise

        bool empty() const
        {
            return size() == 0;
        }

        /*Notice how a class allows member functions to 
        call other member functions of same class*/

        //front, back, push_front, push_back, pop_front an pop_back
        // are the basic double ended queue operations .

        T & front()
        {
            return *begin();
        }

        const T & front() const 
        {
            return *begin(); //return the front value 
        }

        T & back ()
        {
            return *--end();
        }

        const T & back() const
        {
            return *--end(); //add element to back of list 
        }

        void push_front(const T & x)
        {
            insert(begin(),x); //add a value to the front of list with insertion
        }

        void push_back(const T & x)
        {
            insert(end(), x); 
        }

        void pop_front()
        {
            erase(begin()); //erase the front element with erase()
        }

        void pop_back()
        {
            erase(--end()); // erase the back value of a list with erase()
        }

        

       
        /*Two more obvious and easy member functions: 
        the front and back values sorted in the List 
        Adding a value to the front and to the back of a 
        List is accomplished by INSERTION*/

    private:

        int theSize;
        Node *head;
        Node *tail;
        //Bidirectional Linkage 

        void init()
        {
            theSize = 0;
            head = new Node;
            tail = new Node;
            head-> next = tail; //linkage
            tail->prev = head; //linkage
        }
        /*Also under private section (so that only the class itself will 
        use it): a “helper function” that bundles up those lines 
        of code that initialize a List object to an EMPTY LIST*/
    
};

#endif