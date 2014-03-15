#include "node.h"
#include <cassert>

node::node(const value_type & initial_data,
           node * initial_link)
{
    data_field = initial_data;
    link_field = initial_link;
}

void node::set_data (const value_type & v)
{
    data_field = v;
}

void node::set_link(node * p)
{
    link_field = p;
}

node::value_type node::data() const //why value_type node?
{
    return data_field;
}

node * node::link()
{
    return link_field;
}                               //whats the main difference between these two

const node * node::link() const
{
    return link_field;
}

// pre: head_ptr points to the first node of a list
// post: returns the number of nodes in this list
std::size_t list_length(const node *head_ptr)  //why are we putting size_t in front of fcn?
{
    std::size_t ans(0);
    for (const node *p = head_ptr; p != NULL; p = p->link())
        ++ans;
    return ans;

}

// pre: head_ptr is the address of the first node in a list
// post: a new node has been inserted at the front of
//       the list; head_ptr has been updated to the
//       address of the new node
void list_head_insert(node * & head_ptr,
                      const node::value_type &entry)
{
    head_ptr = new node(entry, head_ptr); //shouldnt this be other way around?
}

// pre: previous_ptr is the address of a node in a linked list
//      can't be NULL
// post: a new node whose data field is entry has been inserted
//       immediately after the given node in this list
void list_insert(node *previous_ptr, const node::value_type &entry)
{
    assert(previous_ptr != NULL);

    node * n = new node(entry, previous_ptr->link());
    previous_ptr->set_link(n);
}

// pre: head_ptr is the address of the head node in a linked list
// post: returns the address of the first node in this list
//       whose data field is entry
//       returns NULL if no such node exists
node * list_search(node *head_ptr, const node::value_type &entry)
{
    node *p;
    for (p = head_ptr; p != NULL && p->data() != entry; //walk through this basic for loop
         p = p->link())
        ;
    return p;
}


const node * list_search(const node *head_ptr, const node::value_type &entry) //why is fcn a pointer?
{
    const node *p;
    for (p = head_ptr; p != NULL && p->data() != entry;
         p = p->link())
        ;
    return p;
}


node * list_locate(node *head_ptr, std::size_t pos)
{
    node *p;
    std::size_t i(0);

    for (p = head_ptr; p != NULL && i++ < pos; p = p->link())
        ;
    return p;
}

const node * list_locate(const node *head_ptr, std::size_t pos)
{
    const node *p;
    std::size_t i(0);

    for (p = head_ptr; p != NULL && i++ < pos; p = p->link())
        ;
    return p;
}

// pre: head_ptr is the address of the first node in a linked list
// post: the node has been removed; head_ptr has been
//       updated to the address of its successor
void list_head_remove(node * & head_ptr)
{
    if (head_ptr == NULL)
        return;
    node *temp = head_ptr;
    head_ptr = head_ptr->link();
    delete temp;
}

// pre: previous_ptr is the address of a node in a linked list
// post: the node following the given node has been removed
//       from the linked list
void list_remove(node *previous_ptr)
{
    if (previous_ptr == NULL)
        return;


    node *temp = previous_ptr->link();
    previous_ptr->set_link(temp->link());
    delete temp;


}

void list_clear(node *&head_ptr)
{
    while (head_ptr != NULL)
        list_head_remove(head_ptr);
}

void  list_copy(node *source_ptr, node *&head_ptr, node *&tail_ptr)
{
    head_ptr = tail_ptr = NULL;
    if (source_ptr == NULL)
        return;

    list_head_insert(head_ptr, source_ptr->data());
    tail_ptr = head_ptr;

    for (source_ptr = source_ptr->link(); source_ptr != NULL;
         source_ptr = source_ptr->link())
    {
        list_insert(tail_ptr, source_ptr->data());
        tail_ptr = tail_ptr->link();
    }
}

