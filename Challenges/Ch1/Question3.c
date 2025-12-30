// Doubly Linked List of heap-allocated strings
// Functions to insert, find, delete items

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char *data;
  struct Node *prev;
  struct Node *next;
} Node;

typedef struct List {
  Node *tail;
  Node *head;
} List;

// O(n)
// Checks if a given Node exists in the given List
// Used to avoid cycles in a List
Node *FindNode(List *list, Node *node) {

  Node *curr = list->tail;

  while (1) {
    if (curr == node) {
      printf("Node exists in List.\n");
      return node;
    }
    curr = curr->next;

    if (curr == NULL) {
      break;
    }
  }

  printf("Node does not exist in List.\n");
  return NULL;
}

// Insert a New Node into an empty List
// First check if List is empty AKA Tail and Head must be NULL
// Then set Head and Tail of List to the New Node
void insertBeginning(List *list, Node *newNode) {
  if (list->head != NULL && list->tail != NULL) {
    printf("List not empty. Failed to insert '%s' at beginning of List.\n",
           newNode->data);

    return;
  }

  list->head = newNode;
  list->tail = newNode;

  // Reset New Node's Prev and Next
  newNode->prev = NULL;
  newNode->next = NULL;

  printf("Successfully inserted '%s' at beginning of List.\n", newNode->data);
}

// Insert New Node at the Head of a non-empty List
// First check if List is non-empty AKA Tail or Head or non-NULL
// Then set pointers
void insertEnd(List *list, Node *newNode) {
  if (FindNode(list, newNode)) {
    printf("Failed to insert '%s' at end of List.\n", newNode->data);
    return;
  }

  if (list->head == NULL && list->tail == NULL) {
    printf("List is empty. Failed to insert '%s' at end of List.\n",
           newNode->data);

    return;
  }

  // Set current Head's Next pointer to the New Node
  list->head->next = newNode;
  // Set New Node's Prev pointer to current Head
  newNode->prev = list->head;

  // Set Head to New Node
  list->head = newNode;
  // Set New Node's Next to NULL
  newNode->next = NULL;

  printf("Successfully inserted '%s' at end of List.\n", newNode->data);
}

// Insert New Node at the Head of a non-empty List
// First check if List is non-empty AKA Tail or Head or non-NULL
// Then set pointers
void insertStart(List *list, Node *newNode) {
  if (FindNode(list, newNode)) {
    printf("Failed to insert '%s' at start of List.\n", newNode->data);
    return;
  }

  if (list->head == NULL && list->tail == NULL) {
    printf("List is empty. Failed to insert '%s' at start of List.\n",
           newNode->data);

    return;
  }

  // Set current Tail's Prev pointer to the New Node
  list->tail->prev = newNode;
  // Set New Node's next pointer to current Tail
  newNode->next = list->tail;

  // Set Head to New Node
  list->tail = newNode;
  // Set New Node's Prev to NULL
  newNode->prev = NULL;

  printf("Successfully inserted '%s' at start of List.\n", newNode->data);
}

// Insert New Node after given Node
// First check if given Node exists in given List
// Second check if New Node exists in given List
// Set given Node's and New Node's pointers and possibly Head pointer
void insertAfter(List *list, Node *node, Node *newNode) {
  if (!FindNode(list, node)) {
    printf("Failed to insert '%s' after '%s'. '%s' does not exist in List.\n",
           newNode->data, node->data, node->data);
    return;
  }

  if (FindNode(list, newNode)) {
    printf("Failed to insert '%s' after '%s'.\n", newNode->data, node->data);
    return;
  }

  // Set New Node's Next to Node's next
  newNode->next = node->next;
  // Set New Node's Prev to Node
  newNode->prev = node;

  // Set Node's Next to New Node
  node->next = newNode;

  // If Node and Head are the same set Head to New Node
  if (node == list->head) {
    list->head = newNode;
  }
}

// Insert New Node before given Node
// First check if given Node exists in given List
// Second check if New Node exists in given List
// Set given Node's and New Node's pointers and possibly Head pointer
void insertBefore(List *list, Node *node, Node *newNode) {
  if (!FindNode(list, node)) {
    printf("Failed to insert '%s' before '%s'. '%s' does not exist in List.\n",
           newNode->data, node->data, node->data);
    return;
  }

  if (FindNode(list, newNode)) {
    printf("Failed to insert '%s' before '%s'.\n", newNode->data, node->data);
    return;
  }

  // Set New Node's Prev to Node's prev
  newNode->prev = node->prev;
  // Set New Node's Next to Node
  newNode->next = node;

  // Set Node's Prev to New Node
  node->prev = newNode;

  // If Node and Tail are the same set Tail to New Node
  if (node == list->tail) {
    list->tail = newNode;
  }
}

// Delete given Node from given List
// Check if given node exists
// Set and remove Pointers and FREE MEMORY
void deleteNode(List *list, Node *node) {
  if (!FindNode(list, node)) {
    printf("Failed to delete Node: %s.", node->data);
    return;
  }

  // Set Node's Prev's Next to Node's Next
  if (node->prev != NULL) {
    node->prev->next = node->next;
  }

  // Set Node's Next's Prev to Node's Prev
  if (node->next != NULL) {
    node->next->prev = node->prev;
  }

  // If Node and Tail/Head are the same set Tail/Head to Next/Prev
  if (node == list->tail) {
    list->tail = node->next;
  }
  if (node == list->head) {
    list->head = node->prev;
  }

  // Free Memory
  free(node->data);
}

void printList(List *list) {

  Node curr = *list->tail;
  printf("[");

  while (1) {
    printf("'%s', ", curr.data);
    curr = *curr.next;

    if (curr.next == NULL) {
      printf("'%s'", curr.data);
      break;
    }
  }

  printf("]\n");
}

int main() {
  List list = {NULL, NULL};

  Node node1 = {(char *)malloc(sizeof(char) * 6), NULL, NULL};
  strcpy(node1.data, "Hello");

  Node node2 = {(char *)malloc(sizeof(char) * 6), NULL, NULL};
  strcpy(node2.data, "World");

  Node node3 = {(char *)malloc(sizeof(char) * 6), NULL, NULL};
  strcpy(node3.data, "!!!!!");

  Node node4 = {(char *)malloc(sizeof(char) * 6), NULL, NULL};
  strcpy(node4.data, "?????");

  Node node5 = {(char *)malloc(sizeof(char) * 6), NULL, NULL};
  strcpy(node5.data, ".....");

  insertBeginning(&list, &node2); // Pass

  insertStart(&list, &node1); // Pass

  insertEnd(&list, &node3); // Pass

  insertStart(&list, &node1); // Fail

  insertEnd(&list, &node3); // Fail

  insertAfter(&list, &node3, &node4); // Pass

  insertBefore(&list, &node1, &node5); // Pass

  printList(&list);

  deleteNode(&list, &node5); // Pass

  printList(&list);

  return 0;
}
