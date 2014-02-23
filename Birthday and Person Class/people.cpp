#include "people.h"
#include "birthday.h"
#include <iostream>
using namespace std;

People::People(string x, Birthday bo)
    :name(x), dateofBirth(bo)
{
}
//the : gave us access to the birthday class

void People::printInfo(){
    cout<<name<<"was born on";
    dateofBirth.printDate();//printDate() is a Birthday member function but since we gave this class access to
                            //Birthday using : we can use it
}
