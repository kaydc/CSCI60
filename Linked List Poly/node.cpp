#include "node.h"
#include <cassert>

node::node(const value_type & initial_data,
           node * initial_link)

{
    data_field = initial_data;
    link_field = initial_link;
}

void node::set_data(const value_type & v)
{
    data_field = v;
}

void node::set_link(node * p)
{
    link_field = p;
}

node::value_type node::data() const
{
    return data_field;
}

node * node::link()
{
    return link_field;
}

const node * node::link() const
{
    return link_field;
}

std::size_t list_length(const node * head_ptr)
{
    std::size_t ans(0);

    for (const node * p = head_ptr; p != NULL; p = p->link())
        ++ans;

    return ans;
}

void list_head_insert(node * & head_ptr,
                      const node::value_type & entry)
{

    head_ptr = new node(entry, head_ptr);
}

void list_insert(node * previous_ptr,
                 const node::value_type & entry)
{
    assert(previous_ptr != NULL);

    node * n = new node(entry, previous_ptr->link());
    previous_ptr->set_link(n);
}

node * list_search(node * head_ptr,
                   const node::value_type & entry)
{
    for (node * p = head_ptr; p != NULL; p = p->link())
    {
        if (p->data() == entry)
            return p;
    }
    return NULL;
}

const node * list_search(const node * head_ptr,
                   const node::value_type & entry)
{
    for (const node * p = head_ptr; p != NULL; p = p->link())
    {
        if (p->data() == entry)
            return p;
    }
    return NULL;
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


void list_head_remove(node *&head_ptr)
{
    if (head_ptr == NULL)
        return;

    node *temp = head_ptr;
    head_ptr = head_ptr->link();
    delete temp;
}

void list_clear(node *&head_ptr)
{
    while (head_ptr != NULL)
        list_head_remove(head_ptr);
}



void list_remove(node *previous_ptr)
{
    if (previous_ptr == NULL)
        return;

    node * temp = previous_ptr->link();
    previous_ptr->set_link(temp->link());
    delete temp;
}

void list_copy(node * source_ptr, node * & head_ptr,
               node * & tail_ptr)
{
    head_ptr = tail_ptr = NULL;
    if (source_ptr == NULL)
        return;

    list_head_insert(head_ptr, source_ptr->data());
    tail_ptr = head_ptr;

    for (source_ptr = source_ptr->link();
         source_ptr != NULL;
         source_ptr = source_ptr->link())
    {
        list_insert(tail_ptr, source_ptr->data());
        tail_ptr = tail_ptr->link();
    }
}

void list_copy_reverse(node *source_ptr, node *&copy_ptr)
{
    copy_ptr = NULL;
    for (node * p = source_ptr; p != NULL; p = p->link())
        list_head_insert(copy_ptr, p->data());
}
