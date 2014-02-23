#include "birthday.h"
#include <iostream>
using namespace std;

Birthday::Birthday(int m, int d, int y)
{
    month=m;//
    day=d; //so we can use the private variables we established for the birthday class
    year=y;//
}

void Birthday::printDate(){
    cout<<month<<"/"<<day<<"/"<<year<<endl;
}
