// ChatGPT generated doubly linkedlist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    List my_list;
    init(&my_list);

    while (1) {
        printf("Enter a command (push_front, push_back, pop_front, pop_back, front, back, size, clear, erase, quit): ");
        char command[20];
        scanf("%s", command);

        if (strcmp(command, "push_front") == 0) {
            int value;
            printf("Enter an integer value: ");
            scanf("%d", &value);
            push_front(&my_list, value);
        } else if (strcmp(command, "push_back") == 0) {
            int value;
            printf("Enter an integer value: ");
            scanf("%d", &value);
            push_back(&my_list, value);
        } else if (strcmp(command, "pop_front") == 0) {
            if (is_empty(&my_list)) {
                printf("Error: list is empty\n");
            } else {
                printf("Popped value: %d\n", pop_front(&my_list));
            }
        } else if (strcmp(command, "pop_back") == 0) {
            if (is_empty(&my_list)) {
                printf("Error: list is empty\n");
            } else {
                printf("Popped value: %d\n", pop_back(&my_list));
            }
        } else if (strcmp(command, "front") == 0) {
            if (is_empty(&my_list)) {
                printf("Error: list is empty\n");
            } else {
                printf("Front value: %d\n", front(&my_list));
            }
        } else if (strcmp(command, "back") == 0) {
            if (is_empty(&my_list)) {
                printf("Error: list is empty\n");
            } else {
                printf("Back value: %d\n", back(&my_list));
            }
        } else if (strcmp(command, "size") == 0) {
            printf("Size of the list: %d\n", size(&my_list));
        } else if (strcmp(command, "clear") == 0) {
            clear(&my_list);
        } else if (strcmp(command, "erase") == 0) {
            int index;
            printf("Enter the index of the element to be erased: ");
            scanf("%d", &index);
            erase(&my_list, index);
        } else if (strcmp(command, "quit") == 0) {
            clear(&my_list);
            break;
        } else {
            printf("Error: Invalid command\n");
        }
    }
    return 0;
}

