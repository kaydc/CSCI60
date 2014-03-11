
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include<list>


using namespace std;

int main()
{

    ifstream ins("input.txt");
    if (ins.fail())
    {
        cout<<"error"<<endl;
        exit(1);
    }


    list<int>l;

   string word;
    map<string, list<int>>k;





  int position = 0;
  while (ins >> word)
        k[word].push_back(position++);//every word gets its own position in the string
                                      //portion of the map and its position is also recorded
                                      //into the list


               for(map<string, list<int>>::iterator i=k.begin();//first iterator scans through each element of the map

                   i!=k.end();++i)
            {

                  cout<<(*i).first<< ": ";
                  for (list<int>::iterator f= (i->second).begin(); f!= (i->second).end(); ++f)
                      cout<<*f<<" ";
                    //iterator *f finds the indexes recorded within the list and prints their positions out
                  cout << endl;
            }







return 0;


}

