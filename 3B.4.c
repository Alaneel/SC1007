// ChatGPT generated doubly linkedlist
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
} Node;

typedef struct List {
  Node* head;
  Node* tail;
  int size;
} List;

// Initializes an empty list.
void init(List* list) {
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
}

// Returns the number of elements in the list.
int size(List* list) {
  return list->size;
}

// Returns 1 if the list is empty, 0 otherwise.
int is_empty(List* list) {
  return list->size == 0;
}

// Adds an element to the front of the list.
void push_front(List* list, int data) {
  Node* node = malloc(sizeof(Node));
  node->data = data;
  node->prev = NULL;
  node->next = list->head;
  if (list->head != NULL) {
    list->head->prev = node;
  }
  list->head = node;
  if (list->tail == NULL) {
    list->tail = node;
  }
  list->size++;
}

// Adds an element to the back of the list.
void push_back(List* list, int data) {
  Node* node = malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  node->prev = list->tail;
  if (list->tail != NULL) {
    list->tail->next = node;
  }
  list->tail = node;
  if (list->head == NULL) {
    list->head = node;
  }
  list->size++;
}

// Removes the element at the front of the list and returns its value.
int pop_front(List* list) {
  if (list->head == NULL) {
    exit(1); // error: list is empty
  }
  Node* node = list->head;
  int data = node->data;
  list->head = node->next;
  if (list->head != NULL) {
    list->head->prev = NULL;
  }
  list->size--;
  free(node);
  return data;
}

// Removes the element at the back of the list and returns its value.
int pop_back(List* list) {
  if (list->tail == NULL) {
    exit(1); // error: list is empty
  }
  Node* node = list->tail;
  int data = node->data;
  list->tail = node->prev;
  if (list->tail != NULL) {
    list->tail->next = NULL;
  }
  list->size--;
  free(node);
  return data;
}

// Returns the value of the element at the front of the list.
int front(List* list) {
  if (list->head == NULL) {
    exit(1); // error: list is empty
  }
  return list->head->data;
}

// Returns the value of the element at the back of the list.
int back(List* list) {
  if (list->tail == NULL) {
    exit(1); // error: list is empty
  }
  return list->tail->data;
}

// Removes all elements from the list.
void clear(List* list) {
  Node* node = list->head;
  while (node != NULL) {
    Node* next = node->next;
    free(node);
    node = next;
  }
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
}

// Removes the element at the specified index in the list.
void erase(List* list, int index) {
  if (index < 0 || index >= list->size) {
    exit(1); // error: index out of range
  }
  if (index == 0) {
    pop_front(list);
    return;
  }
  if (index == list->size - 1) {
    pop_back(list);
    return;
  }
  Node* node = list->head;
  for (int i = 0; i < index; i++) {
    node = node->next;
  }
  node->prev->next = node->next;
  node->next->prev = node->prev;
  free(node);
  list->size--;
}

// Returns the element at the specified index in the list.
int get(List* list, int index) {
  if (index < 0 || index >= list->size) {
    exit(1); // error: index out of range
  }
  Node* node = list->head;
  for (int i = 0; i < index; i++) {
    node = node->next;
  }
  return node->data;
}

// Sets the value of the element at the specified index in the list.
void set(List* list, int index, int data) {
  if (index < 0 || index >= list->size) {
    exit(1); // error: index out of range
  }
  Node* node = list->head;
  for (int i = 0; i < index; i++) {
    node = node->next;
  }
  node->data = data;
}

// Inserts an element with the specified value at the specified index in the list.
void insert(List* list, int index, int data) {
  if (index < 0 || index > list->size) {
    exit(1); // error: index out of range
  }
  if (index == 0) {
    push_front(list, data);
    return;
  }
  if (index == list->size) {
    push_back(list, data);
    return;
  }
  Node* node = malloc(sizeof(Node));
  node->data = data;
  Node* curr = list->head;
  for (int i = 0; i < index; i++) {
    curr = curr->next;
  }
 node->prev = curr->prev;
  node->next = curr;
  curr->prev->next = node;
  curr->prev = node;
  list->size++;
}

// Reverses the order of the elements in the list.
void reverse(List* list) {
  Node* node = list->head;
  while (node != NULL) {
    Node* temp = node->next;
    node->next = node->prev;
    node->prev = temp;
    node = temp;
  }
  node = list->head;
  list->head = list->tail;
  list->tail = node;
}

int main() {
  // Create a new list and verify that it is empty
  List list;
  init(&list);
  if (!is_empty(&list)) {
    printf("Error: newly-initialized list is not empty\n");
    exit(1);
  }

  // Verify that the size of the list is 0
  if (size(&list) != 0) {
    printf("Error: size of newly-initialized list is not 0\n");
    exit(1);
  }

  // Add an element to the front of the list
  push_front(&list, 10);

  // Verify that the element was added and the list is not empty
  if (is_empty(&list)) {
    printf("Error: list is empty after adding an element\n");
    exit(1);
  }
  if (front(&list) != 10) {
    printf("Error: incorrect value returned by front()\n");
    exit(1);
  }
  if (back(&list) != 10) {
    printf("Error: incorrect value returned by back()\n");
    exit(1);
  }

  // Verify that the size of the list is 1
  if (size(&list) != 1) {
    printf("Error: size of list is not 1 after adding an element\n");
    exit(1);
  }

  // Add an element to the back of the list
  push_back(&list, 20);

  // Verify that the element was added and the list is not empty
  if (is_empty(&list)) {
    printf("Error: list is empty after adding an element\n");
    exit(1);
  }
  if (front(&list) != 10) {
    printf("Error: incorrect value returned by front()\n");
    exit(1);
  }
  if (back(&list) != 20) {
    printf("Error: incorrect value returned by back()\n");
    exit(1);
  }

  // Verify that the size of the list is 2
  if (size(&list) != 2) {
    printf("Error: size of list is not 2 after adding an element\n");
    exit(1);
  }

  // Insert an element at index 1
  insert(&list, 1, 15);

  // Verify that the element was inserted and the list is not empty
  if (is_empty(&list)) {
    printf("Error: list is empty after inserting an element\n");
    exit(1);
  }
  if (front(&list) != 10) {
    printf("Error: incorrect value returned by front()\n");
    exit(1);
  }
  if (back(&list) != 20) {
    printf("Error: incorrect value returned by back()\n");
    exit(1);
  }
  if (get(&list, 1) != 15) {
    printf("Error: incorrect value returned by get()\n");
    exit(1);
  }

  // Verify that the size of the list is 3
  if (size(&list) != 3) {
    printf("Error: size of list is not 3 after inserting an element\n");
    exit(1);
  }

  // Remove the element at the front of the list
  int val = pop_front(&list);

  // Verify that the correct element was removed and the list is not empty
  if (is_empty(&list)) {
    printf("Error: list is empty after removing an element\n");
    exit(1);
  }
  if (val != 10) {
    printf("Error: incorrect value returned by pop_front()\n");
    exit(1);
  }
  if (front(&list) != 15) {
    printf("Error: incorrect value returned by front()\n");
    exit(1);
  }
  if (back(&list) != 20) {
    printf("Error: incorrect value returned by back()\n");
    exit(1);
  }

  // Verify that the size of the list is 2
  if (size(&list) != 2) {
    printf("Error: size of list is not 2 after removing an element\n");
    exit(1);
  }

  // Remove the element at the back of the list
  val = pop_back(&list);

  // Verify that the correct element was removed and the list is not empty
  if (is_empty(&list)) {
    printf("Error: list is empty after removing an element\n");
    exit(1);
  }
  if (val != 20) {
    printf("Error: incorrect value returned by pop_back()\n");
    exit(1);
  }
  if (front(&list) != 15) {
    printf("Error: incorrect value returned by front()\n");
    exit(1);
  }
  if (back(&list) != 15) {
    printf("Error: incorrect value returned by back()\n");
    exit(1);
  }

  // Verify that the size of the list is 1
  if (size(&list) != 1) {
    printf("Error: size of list is not 1 after removing an element\n");
    exit(1);
  }

  // Clear the list
  clear(&list);

  // Verify that the list is empty
  if (!is_empty(&list)) {
    printf("Error: list is not empty after clearing\n");
    exit(1);
  }

  // Verify that the size of the list is 0
  if (size(&list) != 0) {
    printf("Error: size of list is not 0 after clearing\n");
    exit(1);
  }

  printf("All tests passed\n");

  return 0;
  }
