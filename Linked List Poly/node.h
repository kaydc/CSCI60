#ifndef NODE_H
#define NODE_H


#include "term.h"


// WANT: to represent a unit in a linked list
//       which has a value and the address of the next unit

class node
{
public:

    // CONSTANTS & TYPES
    typedef term value_type;

    // CONSTRUCTOR
    node(const value_type &  = value_type(),
         node * = NULL);

    // pre:
    // post: sets the data field of this node to the given value
    void set_data(const value_type &);

    // pre:
    // post; sets the link field of this node to the given address
    void set_link(node *);

    // pre:
    // post: returns the value stored in data field
    value_type data() const;

    // pre:
    // post: returns the address stored in this node
    node * link();

    const node * link() const;

private:
    value_type data_field;
    node *     link_field;

};

// TOOLKIT FUNCTIONS TO CREATE, MODIFY, MANIPULATE LINKED LISTS

// pre: head_ptr is the address of the first node in a linked list
// post: returns the number of nodes in that list

std::size_t list_length(const node * head_ptr);

// pre: head_ptr points to the first node of a linked list
// post: a new node has been created with data = entry
//       and link = address of the old head node
//       head_ptr has been updated to the address of the new node
void list_head_insert(node * & head_ptr,
                      const node::value_type & entry);

// pre: previous_ptr is the address of a node in a linked list
// post:  a new node whose data field is entry has been created
//        and inserted into the list immediately after the node
//        pointed to by previous_ptr

void list_insert(node * previous_ptr,
                 const node::value_type & entry);

// pre: head_ptr points to the first node in a linked list
// post: returns a pointer to the first node in this list
//       whose data is entry
//       returns NULL if no such node exists
node * list_search(node * head_ptr, const node::value_type & entry);
const node * list_search(const node * head_ptr,
                         const node::value_type & entry);

// pre: head_ptr points to the first node of a linked list
// post: returns a pointer to the node in position pos in this list
//       if pos >= length of this list, then returns NULL

node * list_locate(node * head_ptr, std::size_t pos);
const node * list_locate(const node * head_ptr, std::size_t pos);

// pre: head_ptr is the address of the first node in a linked list
// post: removes the first node of this list
//       head_ptr has been updated to point to the next node

void  list_head_remove(node * & head_ptr);

// pre: head_ptr is the address of the first node of a linked list
// post: returns all nodes in this list back to the heap
void list_clear(node * & head_ptr);

// pre: previous_ptr points to the node preceding the node to be
//      removed
// post: the node following previous_ptr has been removed
void list_remove(node * previous_ptr);

// pre: source_ptr is the address of the first node of a linked list
// post: a copy of this list has been created
//       head_ptr is the address of the first node of the copy
//       tail_ptr is the address of the list node of the copy
void list_copy(node * source_ptr, node * & head_ptr,
               node * & tail_ptr);

// pre: source_ptr is the address of the first node of a linked list
// post: a copy of the list has been created in reverse order
void list_copy_reverse(node * source_ptr, node * & copy_ptr);

#endif // NODE_H
