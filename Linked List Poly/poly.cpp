#include "poly.h"
#include <string>
#include <sstream>

poly::poly(coeff_type c, std::size_t e)
{
    head = NULL;
    list_head_insert(head, term(c, e));
}

poly::poly(const term & t)
{
    head = NULL;
    list_head_insert(head, t);
}

poly::poly(const poly & p)
{
    node *tail;
    list_copy(p.head, head, tail);
}

poly::~poly()
{
    list_clear(head);
}

void poly::operator=(const poly & p)
{
    // check for self-assignment
    if (this == &p)
        return;

    list_clear(head);
    node *tail;
    list_copy(p.head, head, tail);
}

std::size_t poly::degree() const
{
    if (head == NULL)
        return 0;

    return head->data().e;
}

poly::coeff_type poly::operator [](std::size_t e) const
{
    term target(0, e);

    node *p = list_search(head, target);

    if (p == NULL)
        return coeff_type();
    else
        return p->data().c;

}

std::ostream & operator <<(std::ostream & os, const poly & p)
{
    for (std::size_t e = p.degree(); e > 0; --e)
    {
        poly::coeff_type c = p[e];

        if (c != poly::coeff_type())
            os << c << " x^" << e << " + ";
    }

    os << p[0];  // always output the constant term
    return os;
}

void poly::operator +=(const term & t)
{
    if (t.c == coeff_type())
        return;

    add(head, t);
}

void poly::add(node * & p, const term & t)
{
    if (p == NULL || p->data().e < t.e)
    {
        list_head_insert(p, t);
        return;
    }

    if (p->data().e == t.e)
    {
        if (p->data().c == -t.c)
            list_head_remove(p);
        else
        {
            term n(t.c + p->data().c, t.e);
            p->set_data(n);
        }
        return;
    }

    node *tail = p->link();
    add(tail, t);
    p->set_link(tail);
}

std::istream & operator >>(std::istream & is, poly & p)
{
    std::string s;
    getline(is, s);

    std::stringstream ss(s);

    poly::coeff_type c;
    std::size_t e;

    p = poly();

    while (ss >> c >> e)
        p += term(c, e);

    return is;
}

void poly::operator +=(const poly & p)
{
    for (std::size_t i = 0; i < list_length(p.head); ++i)
    {
        term t = list_locate(p.head, i)->data();
        *this += t;
    }
}

poly operator +(const poly &a, const poly &b)
{
    poly ans(a);
    ans += b;
    return ans;
}
void poly::operator -=(const poly & p)
{
    for (std::size_t i = 0; i < list_length(p.head); ++i)
    {
        term t = list_locate(p.head, i)->data();
        term n = term(-t.c, t.e);
        *this += n;
    }
}

poly operator -(const poly &a, const poly &b)
{
    poly ans(a);
    ans -= b;
    return ans;
}

void poly::operator *=(const term & t)
{
    for (std::size_t i = 0; i < list_length(head); ++i)
    {
        node * p = list_locate(head, i);
        term current = p->data();
        term n(current.c * t.c, current.e + t.e);
        p->set_data(n);
    }
}

poly operator *(const poly & p, const term & t)
{
    poly ans(p);
    ans *= t;
    return ans;
}

void poly::operator *=(const poly & p)
{
    poly ans;
    for (std::size_t i = 0; i < list_length(p.head); ++i)
    {
        node *q = list_locate(p.head, i);
        term t = q->data();
        ans += (*this)*t;


    }
    *this = ans;

}

poly operator *(const poly & p, const poly & q)
{
    poly ans(p);
    ans *= q;
    return ans;
}


void poly::operator /=(const poly & p)
{
    assert(p.head != NULL);
    poly div(*this), quotient;

    while (div.head != NULL && div.degree() >= p.degree())
    {
        term t1 = div.head->data();
        term t2 = p.head->data();
        term t(t1.c/t2.c, t1.e - t2.e);
        quotient += t;
        div -= p*t;
    }
    *this = quotient;
}


poly operator /(const poly & p, const poly & q)
{
    poly ans(p);
    ans /= q;
    return ans;
}

void poly::operator %=(const poly & p)
{
    assert(p.head != NULL);
    poly div(*this);

    while (div.head != NULL && div.degree() >= p.degree())
    {
        term t1 = div.head->data();
        term t2 = p.head->data();
        term t(t1.c/t2.c, t1.e - t2.e);
        div -= p*t;
    }
    *this = div;
}


poly operator %(const poly & p, const poly & q)
{
    poly ans(p);
    ans %= q;
    return ans;
}


poly poly::derivative() const
{
    poly ans;
    for (std::size_t i = 0; i < list_length(head); ++i)
    {
        term t = list_locate(head, i)->data();
        if (t.e == 0)
            continue;
        term n (t.c*t.e, t.e-1);
        ans += n;
    }
    return ans;
}

poly poly::integral() const
{
    poly ans;
    for (std::size_t i = 0; i < list_length(head); ++i)
    {
        term t = list_locate(head, i)->data();
        term n (t.c/(t.e+1), t.e+1);
        ans += n;
    }
    return ans;
}

bool operator ==(const poly &a, const poly & b)
{
    if (a.degree() != b.degree())
        return false;

    for (std::size_t i = 0; i < a.degree(); ++i)
    {
        term t1 = a[i];
        term t2 = b[i];

        if (t1.c != t2.c)
            return false;
    }
    return true;
}

bool operator !=(const poly & a, const poly & b)
{
    return !(a == b);
}
