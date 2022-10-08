#include <stdio.h>

#include "DSA/linkedlist.h"

void print_linkedlist(LinkedList *llist) {
  Node *iter = linkedlist_iter_begin(llist);
  printf("[");
  while (iter) {
    i32 val = result_unwrap(linkedlist_node_value(iter));
    printf("%d", val);
    iter = linkedlist_node_next(iter);
    if (!iter) {
      break;
    }
    printf(", ");
  }
  printf("]");
  printf("\n");
}

int main() {
  LinkedList *llist = linkedlist_new();

  linkedlist_append(llist, 1);
  linkedlist_append(llist, 1);
  linkedlist_append(llist, 2);
  linkedlist_append(llist, 3);
  linkedlist_append(llist, 3);
  linkedlist_append(llist, 4);
  linkedlist_append(llist, 4);

  print_linkedlist(llist);

  linkedlist_remove_all(llist, 1);
  linkedlist_remove_all(llist, 2);
  linkedlist_remove_all(llist, 3);
  linkedlist_remove_all(llist, 4);

  print_linkedlist(llist);

  linkedlist_del(llist);
  return 0;
}
