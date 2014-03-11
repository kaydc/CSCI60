#include <iostream>
#include "node.h"

using namespace std;

int main()
{

    node *n1 = new node(1, NULL);
    node *n2 = new node(2, n1);
    node *n3 = new node(3, n2);
    list_insert(n2, 6);
    for (std::size_t i = 0; i < list_length(n3); ++i)
        cout << list_locate(n3, i)->data() << endl;

    node *head_ptr, *tail_ptr;

    list_copy(n3, head_ptr, tail_ptr);

    for (std::size_t i = 0; i < list_length(head_ptr); ++i)
        cout << list_locate(head_ptr, i)->data() << endl;

    return 0;
}
