#ifndef NODE_H
#define NODE_H


#include <iostream>

// WANT: a structure with two fields: data and address
//                                    of next block


class node
{
public:

    // CONSTANTS & TYPES

    typedef int value_type;

    // CONSTRUCTOR
    node(const value_type & = value_type(), //Why value_type ()?
         node * = NULL);

    // pre:
    // post: sets the data field to given value
    void set_data(const value_type &);

    // pre:
    // post: sets the link field to given address
    void set_link(node *);

    // pre:
    // post: returns the data stored in this node
    value_type data() const;

    // pre:
    // post: returns the address stored in this node
    node * link();

    // this version of link returns a const pointer
    // which cannot be used to modify what it is pointing to
    const node * link() const;

private:
    value_type data_field;
    node * link_field;
};

// TOOLKIT FUNCTIONS TO MANIPULATE LINKED LISTS

// pre: head_ptr points to the first node of a list
// post: returns the number of nodes in this list
std::size_t list_length(const node * head_ptr);

// pre: head_ptr is the address of the first node in a list
// post: a new node has been inserted at the front of
//       the list; head_ptr has been updated to the
//       address of the new node
void list_head_insert(node * & head_ptr,
                      const node::value_type & entry);


// pre: previous_ptr is the address of a node in a linked list
//      can't be NULL
// post: a new node whose data field is entry has been inserted
//       immediately after the given node in this list
void list_insert(node * previous_pr,
                 const node::value_type & entry);

// pre: head_ptr is the address of the head node in a linked list
// post: returns the address of the first node in this list
//       whose data field is entry
//       returns NULL if no such node exists
node * list_search(node * head_ptr,
                   const node::value_type & entry);
const node * list_search(const node * head_ptr,
                         const node::value_type & entry);

// pre: head_ptr is the address of the first node in a linked list
// post: returns the address of the node at position pos
//       in this list
//       if pos doesn't exist, then returns NULL
node * list_locate(node * head_ptr, std::size_t pos);
const node * list_locate(const node * head_ptr ,
                         std::size_t pos);

// pre: head_ptr is the address of the first node in a linked list
// post: the node has been removed; head_ptr has been
//       updated to the address of its successor
void list_head_remove(node * & head_ptr);

// pre: previous_ptr is the address of a node in a linked list
// post: the node following the given node has been removed
//       from the linked list
void list_remove(node * previous_ptr);

// pre: head_ptr is the address of the first node in a linked list
// post: the entire list has been removed
//       head_ptr has been updated to NULL
void list_clear(node * & head_ptr);

// pre: source_ptr is the address of the first node in a linked list
// post: a copy of the linked list has been created
//       head_ptr is the address of the first node of the copy
//       tail_ptr is the address of the last node of the copy
void list_copy(node * source_ptr,
               node * & head_ptr,
               node * & tail_ptr);

#endif // NODE_H
