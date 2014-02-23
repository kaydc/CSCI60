#ifndef BIRTHDAY_H
#define BIRTHDAY_H

class Birthday
{
public:
    Birthday(int m, int d, int y);//constructor
    void printDate();//will print the date of the parameters we pass in
private:
    int month;
    int day;
    int year;
};

#endif // BIRTHDAY_H
