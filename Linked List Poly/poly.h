#ifndef POLY_H
#define POLY_H

// WANT to represent polynomials with coefficients of type
// coefficient_type with arbitrary degree

#include <cassert>
#include "node.h"

class poly
{
public:

    // CONSTANTS & TYPES
    typedef double coeff_type;


    // CONSTRUCTORS & DESTRUCTOR

    // pre:
    // post: creates a poly with initial value c x^e
    //       default values of c and e are 0
    poly(coeff_type c = coeff_type (), std::size_t e = 0);

    // pre:
    // post: creates a poly with initial term t
    poly(const term &t);

    // pre:
    // post: creates a new poly with same value as p
    poly(const poly &p);

    ~poly();

    // CONST MEMBERS

    // pre:
    // post: returns the highest power among nonzero terms of this poly
    //       degree of the zero poly is 0

    std::size_t degree() const;

    // pre:
    // post: returns the coefficent of the term x^i of this poly
    coeff_type operator[](std::size_t i) const;

    // pre:
    // post: returns the value of this poly at x = v
    coeff_type operator()(const coeff_type & v) const;

    // pre:
    // post: returns the derivative of this poly
    poly derivative() const;

    // pre:
    // post: returns the indefinite integral of this poly with c = 0
    poly integral() const;

    // MODIFICATION MEMBERS


    // pre:
    // post: the value of this poly is now the value of p
    void operator =(const poly &p);

    // pre:
    // post: term t has been added to this poly
    void operator +=(const term & t);

    // pre:
    // post: p has been added to this poly
    void operator +=(const poly &p);

    // pre:
    // post: p has been subtracted from this poly
    void operator -=(const poly & p);

    // pre:
    // post: t has been multiplied to this poly
    void operator *=(const term & t);

    // pre:
    // post: p has been multiplied to this poly
    void operator *=(const poly & p);

    // pre: p != zero poly
    // post: this poly has been divided by p
    void operator /=(const poly & p);

    // pre: p != zero poly
    // post: this poly is now the remainder of this poly divided by
    //       p

    void operator %= (const poly & p);

    // pre:
    // post: the term c x^e has been multiplied to this poly
    void multiply(coeff_type c, std::size_t e);

private:
    node * head;

    // pre: p is address of some node in this poly
    //      t is a term
    // post: adds recursively t to the list starting with p

    void add(node * & p, const term & t);


    // invariants:
    // head is the address of a first node of a linked list
    // each term of ths poly stored in a node of this list
    // the terms are stored in decreasing exponent
    // (in particular, the first node's exponent is the degree
    // of this poly)

    // no two terms have the same exponent
    // no term has zero coefficient

};

bool operator == (const poly &, const poly &);
bool operator != (const poly &, const poly &);

std::istream & operator >> (std::istream &, poly &);
std::ostream & operator << (std::ostream &, const poly &);

poly operator +(const poly &, const poly &);
poly operator -(const poly &, const poly &);
poly operator *(const poly &, const poly &);
poly operator /(const poly &, const poly &);
poly operator %(const poly &, const poly &);


#endif // POLY_H
