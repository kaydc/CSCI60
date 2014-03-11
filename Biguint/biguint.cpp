#include "biguint.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <cassert>

using std::size_t;

biguint::biguint(size_t v)
{
    for (size_t i = 0; i < CAPACITY; ++i)
        data[i] = 0;

    size_t pos(0);
    while (v != 0)
    {
        data[pos] = v % 10;
        v /= 10;
        ++pos;
    }
}

size_t biguint::operator[] (size_t pos) const
{
    if (pos >= CAPACITY)
        return 0;
    return data[pos];
}

std::ostream & operator << (std::ostream & os,
                            const biguint & b)
{
    for (int i = b.size() - 1; i >= 0; --i)
        os << b[i];

    return os;
}

biguint::biguint(const biguint & b)
{
    std::copy(b.data, b.data+CAPACITY, data);
}

biguint::biguint(const std::string & s)
{
    size_t l = s.size();

    for (size_t i = 0; i < CAPACITY; ++i)
        data[i] = 0;

    for (size_t i = 0; i < l; ++i)
        if (!isdigit(s[i]))
            return;

    for (size_t i = 0; i < l; ++i)
        data[i] = s[l-1-i] - '0';

}

std::istream & operator >> (std::istream & is,
                            biguint & b)
{
    std::string s;
    is >> s;
    b = biguint(s);
    return is;
}

size_t biguint::size() const
{
    int i;
    for (i = CAPACITY-1; i >= 0 && data[i] == 0; --i)
        ;

    if (i < 0)   // this biguint is 0
        return 1;
    else
        return i + 1;

}

void biguint::lshift()
{
    for (int i = CAPACITY - 2; i >= 0; --i)
        data[i+1] = data[i];

    data[0] = 0;
}

void biguint::operator <<(size_t n)
{
    if (n >= CAPACITY)
    {
        *this = biguint();
        return;
    }
    for (int i = CAPACITY - 1 - n; i >= 0; --i)
        data[i+n] = data[i];

    for (size_t i = 0; i < n; ++i)
        data[i] = 0;


}

void biguint::rshift()
{
    for (size_t i = 0; i < CAPACITY - 1; ++i)
        data[i] = data[i+1];
    data[CAPACITY-1] = 0;
}

void biguint::operator >>(size_t n)
{
    for (size_t i = 0; i < CAPACITY - n; ++i)
        data[i] = data[i+n];
    for (size_t i = 0; i < n; ++i)
        data[CAPACITY-1-i] = 0;
}

int biguint::compare(const biguint & b) const
{

    for (int i = CAPACITY - 1; i >= 0; --i)
    {
        if (data[i] > b.data[i])
            return 1;
        if (data[i] < b.data[i])
            return -1;
    }

    return 0;
}

void biguint::operator -=(const biguint & b)
{
    if (compare(b) == -1)
    {
        *this = biguint();
        return;
    }

    std::size_t borrow(0);

    for (std::size_t i = 0; i < CAPACITY; ++i)
    {
        if (data[i] >= b.data[i] + borrow)
        {
            data[i] -= (b.data[i] + borrow);
            borrow = 0;
        }
        else
        {
            data[i] = data[i] + 10 - b.data[i] - borrow;
            borrow = 1;
        }
    }

}

void biguint::operator *=(std::size_t d)
{
    assert (d <= 9);
    std::size_t carry(0), product;

    for (std::size_t i = 0; i < CAPACITY; ++i)
    {
        product = data[i] * d + carry;
        data[i] = product % 10;
        carry = product / 10;
    }

}


void biguint::operator += (const biguint & b)
{
    size_t carry(0), sum;
    for (size_t i = 0; i < CAPACITY; ++i)
    {
        sum = data[i] + b.data[i] + carry;
        data[i] = sum % 10;
        carry = sum / 10;
    }
}

void biguint::operator *= (const biguint & b)
{
    biguint ans;
    for (int i = CAPACITY - 1; i >= 0; --i)
    {
        biguint temp(*this);
        temp *= b.data[i];
        ans << 1;
        ans += temp;
    }
    *this  = ans;
}



void biguint::operator /= (const biguint & b)
{
    //  non-zero divisor
    assert(b != 0);

    biguint lo(0), hi(*this), mid;

    while (lo <= hi)
    {

        mid = lo + hi;
        mid *= 5;
        mid.rshift();

        switch(compare(mid*b))
        {
        case 0:

            *this = mid;
            return;

        case 1:
            lo = mid + 1;
            break;

        case -1:
            hi = mid - 1;
            break;
        }
    }
    *this = hi;
}

void biguint::operator %=(const biguint & b)
{
    assert(b != 0);
    *this -= ((*this) / b) * b;

}

void biguint::operator ^=(const biguint & b)
{
    biguint ans(1);
    for (biguint i = 1; i <= b; ++i)
        ans *= (*this);

    *this = ans;
}

biguint biguint::operator ++()
{
    (*this) += 1;
    return *this;
}

biguint biguint::operator ++(int)
{
    biguint orig = *this;
    *this += 1;
    return orig;
}

biguint biguint::operator --()
{
    (*this) -= 1;
    return *this;
}

biguint biguint::operator --(int)
{
    biguint orig = *this;
    *this -= 1;
    return orig;
}

bool operator <= (const biguint &a, const biguint & b)
{
    return (a.compare(b) <= 0);
}

bool operator >= (const biguint &a, const biguint & b)
{
    return (a.compare(b) >= 0);
}

bool operator < (const biguint &a, const biguint & b)
{
    return (a.compare(b) < 0);
}

bool operator > (const biguint &a, const biguint & b)
{
    return (a.compare(b) > 0);
}

bool operator == (const biguint &a, const biguint & b)
{
    return (a.compare(b) == 0);
}

bool operator != (const biguint &a, const biguint & b)
{
    return (a.compare(b) != 0);
}


biguint operator +(const biguint & a, const biguint & b)
{
    biguint ans(a);
    ans += b;
    return ans;
}

biguint operator -(const biguint & a, const biguint & b)
{
    biguint ans(a);
    ans -= b;
    return ans;
}

biguint operator *(const biguint & a, const biguint & b)
{
    biguint ans(a);
    ans *= b;
    return ans;
}

biguint operator /(const biguint & a, const biguint & b)
{
    biguint ans(a);
    ans /= b;
    return ans;
}

biguint operator %(const biguint & a, const biguint & b)
{
    biguint ans(a);
    ans %= b;
    return ans;
}
biguint operator ^(const biguint & a, const biguint & b)
{
    biguint ans(a);
    ans ^= b;
    return ans;
}
