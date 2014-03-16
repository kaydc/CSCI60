#include "term.h"

term::term(double ic, std::size_t ie)
{
    c = ic;
    e = ie;
}

bool operator ==(const term &a, const term &b)
{
    // only compares the exponent field
    return (a.e == b.e);
}

bool operator !=(const term &a, const term &b)
{
    return !(a == b);
}
