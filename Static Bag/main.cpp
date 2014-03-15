#include <iostream>

#include "bag.h"
using namespace std;

int main()
{
    bag b;
    b.insert(1);
    b.insert(2);
    b.insert(1);
    b.insert(2);
    b.insert(2);

    //cout<<b.size()<<endl;
    //b.erase_one(1);

    bag c;
    c.insert(2);
    c.insert(3);
    c.insert(6);
    cout<<c.size()<<endl;


    return 0;
}

