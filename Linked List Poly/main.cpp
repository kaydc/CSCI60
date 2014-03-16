#include <iostream>
#include "poly.h"
using namespace std;


int main()
{


    poly p, q;

    cout << "Enter 2 poly: ";
    cin >> p >> q;

    cout << "p = " << p << endl;
    cout << "q = " << q << endl;

    cout << p + q<< endl;
    cout << p - q<< endl;
    cout << p * q<< endl;
    cout << p / q<< endl;
    cout << p % q<< endl;

    cout << p.derivative() << endl;
    cout << p.integral() << endl;

    cout << (p == q) << endl;
    cout << (p != q) << endl;
    return 0;
}
