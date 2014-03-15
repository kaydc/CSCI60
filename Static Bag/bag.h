#ifndef BAG_H
#define BAG_H
#include <iostream>

//a bag is a collection of items of the same type
//(called value_type) that has at most CAPACITY elements


class bag
{
public:
    //CONSTANTs and TYPES
    static const std::size_t CAPACITY=100;//static just saves space for the program
    typedef int value_type; //we made type_def to be int but we can change it to anything we want

    //constructor

    //pre:
    //post:creates an empty bag
    bag();

    //constant function

    //pre:
    //post:returns the number of elements in this bag
    std::size_t size () const;

    //pre:
    //post: takes a value and returns the number of copies there are, returns 0 if entry is not in this bag.
    std::size_t count(const value_type & entry) const;

    //modification functions

    //pre:size() < CAPACITY
    //post:a new copy of entry is added to this bag
    void insert (const value_type & entry);

    //pre:size()+b.size() <=CAPACITY
    //post:each element of b is added to this bag
    void operator += (const bag & b);

    //pre:
    //post: if target is not this bag then it returns false
    // else we move one copy of target and return true
    bool erase_one(const value_type & target);

    //pre:
    //post:erase all copies of target in this bag and returns number of elements erased
    //if target is not in this bag then we return 0
   std:: size_t erase(const value_type & target);

private:
   value_type data[CAPACITY];
   std::size_t used;

   //invariants :
   //1) used is the number of elements in this bag
   //2) data[0], data[1],..., data[used-1] store the elements in this bag (in no particular order)
   //we dont care whats in the ramainder of the array
};


//NON MEMBER FUNCTIONS

//pre:b1.size() +b2.size() <= CAPACITY
//post:returns a third bag whose elements are those of b1 and b2
bag operator + (const bag & b1, const bag &b2);

#endif // BAG_H
