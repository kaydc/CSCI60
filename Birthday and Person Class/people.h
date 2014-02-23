#ifndef PEOPLE_H
#define PEOPLE_H

#include <string>
#include "birthday.h"
using namespace std;

class People
{
public:
    People(string x, Birthday bo);//our people constructor will take in two parameters, name and class Birthday object
    void printInfo();
private:
    string name;
    Birthday dateofBirth;
};

#endif // PEOPLE_H
