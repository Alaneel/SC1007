// CX1007 Data Structures

#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"

////////////////////////////////////////////////////////////////////////////////

int main(){
    
    LinkedList l;
    Stack s;
    Queue q;

    l.head = 0;
    l.size = 0;
    
    s.ll.head = NULL;
    s.ll.tail = NULL;
    s.ll.size = 0;

    q.ll.head = NULL;
    q.ll.tail = NULL;
    q.ll.size = 0;
    
    insertNode(&l, 0, 2);
    insertNode(&l, 0, 1);
    insertNode(&l, 2, 3);
    insertNode(&l, 3, 5);
    insertNode(&l, 3, 4);

    printf("Printing list: ");
    printList(&l);
    printf("\n");

//    removeNode(&l, 4);
    removeNode(&l, 3);
    removeNode(&l, 2);
    removeNode(&l, 1);
//    removeNode(&l, 0);

    insertNode(&l, 2, 9);
    removeNode(&l, 1);
    
    printf("Printing list: ");
    printList(&l);
    printf("\n");

    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);
    push(&s, 5);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);

    printf("Printing list: ");
    printList(&l);
    printf("\n");

    printf("Printing stack: ");
    while (!isEmptyStack(&s))
        printf("%d ", pop(&s));
    printf("\n");
    
    printf("Printing queue: ");
    while (!isEmptyQueue(&q))
        printf("%d ", dequeue(&q));

    return 0;
}
