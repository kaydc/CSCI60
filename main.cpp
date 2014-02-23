#include <iostream>
#include "birthday.h"
#include "people.h"

using namespace std;

int main()
{
    Birthday birthObj(1,25,1994);//creating a birthday object with the set date being my birthday

    People kelleyCislo("Kelley The King", birthObj);

    //we assigned the people class two parameters, string and birthday, which is what we gave it
    kelleyCislo.printInfo();
    return 0;
}

