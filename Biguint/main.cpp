#include <iostream>
#include "biguint.h"

using namespace std;

int main()
{
    biguint a(305574), b(98);

    biguint c(7), d(3);

    cout << (c^d) << endl;
    cout << c++ << endl;
    cout << c << endl;
    cout << ++d << endl;
    return 0;
}
