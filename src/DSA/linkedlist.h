#ifndef DSA_LINKED_LIST_H_
#define DSA_LINKED_LIST_H_

#include "core.h"
#include "utility.h"

typedef struct Node {
  i32 _data;
  struct Node *_next;
} Node;

Node *_linkedlist_node_new(i32 data);

void _linkedlist_node_del(Node *node);

Node *linkedlist_node_next(Node *cur_node);

Result linkedlist_node_value(Node *cur_node);

////////////////////////////////

typedef struct LinkedList {
  Node *_head;
  usize _length;
} LinkedList;

LinkedList *linkedlist_new();

void linkedlist_del(LinkedList *llist);

Node *linkedlist_head(LinkedList *llist);

Node *linkedlist_tail(LinkedList *llist);

usize linkedlist_length(LinkedList *llist);

bool linkedlist_is_empty(LinkedList *llist);

Node *linkedlist_iter_begin(LinkedList *llist);

Node *linkedlist_iter_end(LinkedList *_llist);

Node *linkedlist_append(LinkedList *llist, i32 v);

Node *linkedlist_prepend(LinkedList *llist, i32 v);

void _linkedlist_remove_gen(LinkedList *llist, i32 v, bool remove_all);

void linkedlist_remove(LinkedList *llist, i32 v);

void linkedlist_remove_all(LinkedList *llist, i32 v);

Node *linkedlist_find(LinkedList *llist, i32 v);

bool linkedlist_contains(LinkedList *llist, i32 v);

#endif
