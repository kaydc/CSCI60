#include "bag.h"
#include <cassert>
#include <algorithm>

bag::bag()
{
    used = 0; //creating a new bag so it has 0 elements in it currently
}

std::size_t bag::size() const
{
    return used;
}

std::size_t bag ::count (const value_type & entry) const
{
    std:: size_t ans;
    for (std::size_t i=0; i<used; ++i)
    {
        if (data[i] ==entry)
            ++ans;


    }
    return ans;
}

void bag::insert (const value_type & entry)
{
    assert(used<CAPACITY);
    data[used] = entry;
    ++used;
 }

void bag::operator += (const bag & b)//copy the elements of b to another bag
{
  assert(used+b.used<=CAPACITY);
  std::copy(b.data, b.data+b.used, data+used); //magical function that copies all of the contents from one bag to another
  used +=b.used;
}

bool bag::erase_one(const value_type & target)
{
 for (std::size_t i=0; i<used; i++)
     if(data[i]==target)
     {
         data[i]=data[used-1];//replaces target with the number in the next index
         --used;
         return true;
     }
 return false;
}

std::size_t bag::erase(const value_type & target)
{
    std::size_t ans (0);
    for(std::size_t i=0; i<used;)
    {
        if (data[i]==target)
        {
            data[i]=data[used-1];
            --used;
            ++ans;
        }
        else ++i;
    }
    return ans;
}

bag operator + (const bag & b1, const bag & b2)
{
   assert(b1.size()+b2.size()<=bag::CAPACITY); //bag::CAPACITY because this is a non member function

   bag ans;
   ans +=b1;//this copies the contents of b1 to answer
   ans +=b2;
   return ans;
}
