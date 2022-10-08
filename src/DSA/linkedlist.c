#include "linkedlist.h"

#include <stdlib.h>

Node *_linkedlist_node_new(i32 data) {
  Node *node = _TMalloc(Node);

  node->_data = data;
  node->_next = nil;

  return node;
}

void _linkedlist_node_del(Node *node) { free(node); }

Node *linkedlist_node_next(Node *cur_node) {
  if (!cur_node) {
    return nil;
  }

  return cur_node->_next;
}

Result linkedlist_node_value(Node *cur_node) {
  if (!cur_node) {
    return result_new_not_ok(-1);
  }

  return result_new_ok(cur_node->_data);
}

////////////////////////////////

LinkedList *linkedlist_new() {
  LinkedList *llist = _TMalloc(LinkedList);

  llist->_head = nil;
  llist->_length = 0;

  return llist;
}

void linkedlist_del(LinkedList *llist) {
  if (!llist) {
    return;
  }

  Node *node = llist->_head;
  while (node) {
    Node *next_node = node->_next;
    _linkedlist_node_del(node);
    node = next_node;
  }

  free(llist);
}

Node *linkedlist_head(LinkedList *llist) {
  if (!llist) {
    return nil;
  }

  return llist->_head;
}

Node *linkedlist_tail(LinkedList *llist) {
  if (!llist) {
    return nil;
  }

  Node *tail = nil;

  Node *ptr = llist->_head;
  while (ptr) {
    tail = ptr;
    ptr = ptr->_next;
  }

  return tail;
}

usize linkedlist_length(LinkedList *llist) { return llist->_length; }

bool linkedlist_is_empty(LinkedList *llist) { return !llist->_head; }

Node *linkedlist_iter_begin(LinkedList *llist) {
  return linkedlist_head(llist);
}

Node *linkedlist_iter_end(LinkedList *_llist) {
  _Unused(_llist);
  return nil;
}

Node *linkedlist_append(LinkedList *llist, i32 v) {
  if (!llist) {
    return nil;
  }

  Node *node = _linkedlist_node_new(v);

  if (linkedlist_is_empty(llist)) {
    llist->_head = node;
  } else {
    Node *tail = linkedlist_tail(llist);
    tail->_next = node;
  }

  llist->_length += 1;

  return node;
}

Node *linkedlist_prepend(LinkedList *llist, i32 v) {
  if (!llist) {
    return nil;
  }

  Node *node = _linkedlist_node_new(v);

  if (linkedlist_is_empty(llist)) {
    llist->_head = node;
  } else {
    node->_next = linkedlist_head(llist);
    llist->_head = node;
  }

  llist->_length += 1;

  return node;
}

void _linkedlist_remove_gen(LinkedList *llist, i32 v, bool remove_all) {
  Node *c_node = linkedlist_iter_begin(llist);

  Node *p_node = nil, *n_node = nil;
  while (c_node) {
    n_node = linkedlist_node_next(c_node);

    i32 val = result_unwrap(linkedlist_node_value(c_node));
    if (val == v) {
      if (p_node) {
        p_node->_next = n_node;
      } else {
        llist->_head = n_node;
      }
      _linkedlist_node_del(c_node);
      if (!remove_all) {
        break;
      }
    } else {
      p_node = c_node;
    }
    c_node = n_node;
  }
}

void linkedlist_remove(LinkedList *llist, i32 v) {
  _linkedlist_remove_gen(llist, v, false);
}

void linkedlist_remove_all(LinkedList *llist, i32 v) {
  _linkedlist_remove_gen(llist, v, true);
}

Node *linkedlist_find(LinkedList *llist, i32 v) {
  Node *node = linkedlist_iter_begin(llist);

  while (node) {
    i32 node_val = result_unwrap(linkedlist_node_value(node));
    if (node_val == v) {
      break;
    }
    node = linkedlist_node_next(node);
  }

  return node;
}

bool linkedlist_contains(LinkedList *llist, i32 v) {
  return linkedlist_find(llist, v);
}
