#ifndef BIGUINT_H
#define BIGUINT_H

#include <iostream>
#include <string>

// WANT: a class to represent NONNEGATIVE integers
//       with lots of digits


class biguint
{
public:

    // CONSTANTS and TYPES
    static const std::size_t CAPACITY = 10;

    // CONSTRUCTORS

    // pre:
    // post: creates a new biguint whose initial value is v
    //       (default value is 0)
    biguint(std::size_t v = 0);

    // pre: s contains only digits 0..9 and has at most
    //      CAPACITY digits
    // post: creates a new biguint whose initial value is
    //       the nonnegative integer represented by string s
    biguint(const std::string &s);

    // pre:
    // post: creates a new biguint that is a copy of b
    biguint(const biguint & b);

    // CONSTANT MEMBER FUNCTIONS

    // pre:
    // post: returns the number of digits in this bigunint
    //       size(0) is 1
    std::size_t size() const;

    // pre: i < size()
    // post: returns the digit at position i of this biguint
    //       LS digit is at position 0
    //       MS digit is at position size() - 1


    std::size_t operator[](std::size_t i) const;

    // MODIFICATON MEMBER FUNCTIONS

    // pre:
    // post: adds the value of b to the value of this biguint
    //       mod 10^CAPACITY
    void operator += (const biguint &b);


    // pre:
    // post: callsubstracts the value of b from the value
    //       of this biguint
    //       (and sets to 0 if the result is negative)
    //        this is the MONUS operation
    void operator -= (const biguint &b);

    // pre: d <= 9
    // post: this biguint has been multiplied by d
    //       (mod 10^CAPACITY)

    void operator *= (std::size_t d);

    // pre:
    // post: multiplies b to this biguint (mod 10^CAPACITY)
    void operator *= (const biguint &b);

    // pre: b != 0
    // post: divides this biguint by b (and round down
    //       the result)
    void operator /= (const biguint &b);

    // pre: b != 0
    // post: sets this biguint to the remainder when
    //       this biguint is integer divided by b
    void operator %= (const biguint &b);

    // pre:
    // post: this biguint has been raised to the b^th power
    //       (anything)^0 = 1
    void operator ^= (const biguint &b);

    // pre:
    // post: this biguint has been multipled by 10^i
    //       (mod 10^CAPACITY)
    void operator <<(std::size_t i);

    // pre:
    // post: this biguint has been divided by 10^i
    void operator >> (std::size_t i);

    // pre:
    // post: this biguint has been incremented by 1
    //       and the return value is the NEW value of
    //       this bigint

    biguint operator ++(); // pre-increment version

    // pre:
    // post: this biguint has been incremented by 1
    //       and the return value is the ORIGINAL value
    //       of this biguint
    biguint operator ++(int);  // post-increment version

    // pre:
    // post: this biguint has been decremented by 1
    //       and the return value is the NEW value of
    //       this biguint
    biguint operator --(); // pre-decrement version

    // pre:
    // post: this biguint has been decremented by 1
    //       and the return value is the ORIGINAL value
    //       of this biguint
    biguint operator --(int); // post-decrement version

    // pre:
    // post: this biguint has been divided by 10
    void rshift();

    // pre:
    // post: this biguint has been multiplied by 10 (mod 10^CAPACITY)
    void lshift();

    // pre:
    //post: returns 0 if this biguint = b
    //             -1 if this biguint < b
    //              1 if this biguint > b
    int compare(const biguint & b) const;


private:
    std::size_t data[CAPACITY];

    // invariants
    // the decimal digits of this biguint are stored in
    // data[0], data[1], ..., data[CAPACITY-1]
    //
    // least significant digit (units) is stored in data[0]
    // most signficant digit is stored in data[CAPACITY-1]
    // in general, the digit corresponding to 10^k is stored in
    // data[k]

    // all digits are used, zero-filled if necessary

};

// pre:
// post: returns the square root of b, rounded down
biguint sqrt(const biguint & b);

bool operator ==(const biguint &, const biguint &);
bool operator !=(const biguint &, const biguint &);
bool operator < (const biguint &, const biguint &);
bool operator <= (const biguint &, const biguint &);
bool operator > (const biguint &, const biguint &);
bool operator >= (const biguint &, const biguint &);

biguint operator +(const biguint &, const biguint &);
biguint operator -(const biguint &, const biguint &);
biguint operator *(const biguint &, const biguint &);
biguint operator /(const biguint &, const biguint &);
biguint operator %(const biguint &, const biguint &);
biguint operator ^(const biguint &, const biguint &);

std::istream & operator >> (std::istream &,
                            biguint &);

std::ostream & operator << (std::ostream &,
                            const biguint &);



#endif // BIGUINT_H
