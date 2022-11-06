// Algorithm 1 Breadth First Search (BFS)

#include <stdio.h>
#include <stdlib.h>
#define SIZE 7

// A structure to represent an adjacency list node
struct AdjListNode {
    int dest;
    int status;
    struct AdjListNode *next;
};

// A structure to represent an adjacency list
struct AdjList {
    int size;
    struct AdjListNode *head;
    struct AdjListNode *tail;
};

// A structure to represent a graph
// Size of array will be V (number of vertices in graph)
struct Graph {
    int V;
    struct AdjList *array;
};

typedef struct queue {
    struct AdjList ll;
} Queue;

int insertNode(struct AdjList *ll, int index, int value);
int removeNode(struct AdjList *ll, int index);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
int isEmptyQueue(Queue *q);

struct AdjListNode *newAdjListNode(int dest);
struct Graph *createGraph(int V);
void addEdge(struct Graph *graph, int src, int dest);
void printGraph(struct Graph *graph);

void BFS(struct Graph *graph, int source, int dest);

// Driver program to test above functions
int main()
{
    // create the graph given in above figure
    int V = 5;
    struct Graph *graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // print the adjacency list representation of the above graph
    printGraph(graph);

    printf("\n");

    BFS(graph, 0, 4);

    return 0;
}

int insertNode(struct AdjList *ll, int index, int value)
{
    struct AdjListNode *cur = NULL;

    if (ll->head == NULL || index == 0)
    {
        cur = ll->head;
        ll->head = (struct AdjListNode *)malloc(sizeof(struct AdjListNode));
        ll->head->dest = value;
        ll->head->status = 0;
        ll->head->next = cur;
        (ll->size)++;
        return 0;
    }
    return -1;
}

int removeNode(struct AdjList *ll, int index)
{
    struct AdjListNode *cur = NULL;

    if (ll->head->next == NULL || index == 0)
    {
        cur = ll->head->next;
        free(ll->head);
        ll->head = cur;
        (ll->size)--;
        return 0;
    }
    return -1;
}

void enqueue(Queue *q, int value)
{
    if (q->ll.head == NULL)
    {
        insertNode(&(q->ll), 0, value);
        q->ll.tail = q->ll.head;
    }
    else
    {
        q->ll.tail->next = newAdjListNode(value);
        q->ll.tail = q->ll.tail->next;
        q->ll.size++;
    }
}

int dequeue(Queue *q)
{
    int item = 0;
    item = q->ll.head->dest;
    removeNode(&(q->ll), 0);
    return item;
}

int isEmptyQueue(Queue *q)
{
    if (q->ll.size == 0) return 1;
    return 0;
}

// A utility function to create a new adjacency list node
struct AdjListNode *newAdjListNode(int dest)
{
    struct AdjListNode *newNode = (struct AdjListNode *)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->status = 0;
    newNode->next = NULL;
    return newNode;
}

// A utility function that creates a graph of V vertices
struct Graph *createGraph(int V)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;

    // Create an array of adjacency lists, size of array will be V
    graph->array = (struct AdjList *)malloc(V * sizeof(struct AdjList));

    // Initialize each adjacency list as empty by making head as NULL
    int i;
    for (i=0; i<V; ++i)
    {
        graph->array[i].head = NULL;
        graph->array[i].tail = NULL;
    }
    return graph;
}

// Adds an edge to an undirected graph
void addEdge(struct Graph *graph, int src, int dest)
{
    // Add an edge from src to dest
    // A node is added to the adjacency list of src
    // The node is added at the beginning
    struct AdjListNode *check = NULL;
    struct AdjListNode *newNode = newAdjListNode(dest);

    if (graph->array[src].head == NULL)
    {
        newNode->next = graph->array[src].head;
        graph->array[src].head = newNode;
    }
    else 
    {
        check = graph->array[src].head;
        while (check->next != NULL)
        {
            check = check->next;
        }
        // graph->array[src].head = newNode;
        check->next = newNode;
    }

    // Since graph is undirected, add an edge from dest to src also
    newNode = newAdjListNode(src);
    if (graph->array[dest].head == NULL)
    {
        newNode->next = graph->array[dest].head;
        graph->array[dest].head = newNode;
    }
    else
    {
        check = graph->array[dest].head;    
        while (check->next != NULL)
        {
            check = check->next;
        }
        check->next = newNode;
    }

    // newNode = newAdjListNode(src);
    // newNode->next = graph->array[dest].head;
    // graph->array[dest].head = newNode;
}

// A utility function to print the adjacency list representation of graph
void printGraph(struct Graph *graph)
{
    int v;
    for (v=0; v < graph->V; ++v)
    {
        struct AdjListNode *pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl) 
        {
            printf("-> %d ", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

void BFS(struct Graph *graph, int source, int dest)
{
    int w = 0, count = 0;
    struct AdjListNode *tmp = NULL;

    // Create a Queue, Q
    Queue q;
    q.ll.head = NULL;
    q.ll.tail = NULL;
    q.ll.size = 0;

    tmp = graph->array[source].head;
    while (tmp != NULL)
    {
        // enqueue v into Q
        enqueue(&q, tmp->dest);
        // mark v as visited
        tmp->status = 1;
        tmp = tmp->next;
    }
    // while Q is not empty do
    while (!isEmptyQueue(&q))
    {
        // dequeue a vertex denoted as w
        w = dequeue(&q);
        count++;
        if (w == dest) 
        {
            printf(" Found in %d searches\n", count);
            return;
        }
        tmp = graph->array[w].head;
        // for each unvisited vertex u adjacent to w do
        while (tmp != NULL)
        {
            if (tmp->status == 0)
            {
                // mark u as visited
                tmp->status = 1;
                // enqueue u into Q
                enqueue(&q, tmp->dest);
            }
            tmp = tmp->next; 
        }
        
    }
    printf(" Not found\n");
}