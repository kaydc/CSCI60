#ifndef TERM_H
#define TERM_H

#include <iostream>

class term
{
public:
    double c;                 // coefficient
    std::size_t e;            // exponent
    term(double ic = 0.0, std::size_t ie = 0);
};

bool operator ==(const term &a, const term &b);
bool operator !=(const term &a, const term &b);


#endif // TERM_H
