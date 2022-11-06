// Algorithm 3 Recursive Depth First Search (DFS)

#include <stdio.h>
#include <stdlib.h>
#define SIZE 7

int count = 0;

// a structure to represent an adjacency list node
struct AdjListNode {
    int dest;
    struct AdjListNode *next;
};

// a structure to represent an adjacency list
struct AdjList {
    int size;
    struct AdjListNode *head;
};

// a structure to represent a graph
// size of array will be V (number of vertices in graph)
struct Graph {
    int V;
    int *visited;
    struct AdjList *array;
};

typedef struct stack {
    struct AdjList ll;
} Stack;

int insertNode(struct AdjList *ll, int index, int value);
int removeNode(struct AdjList *ll, int index);
void push(Stack *s, int value);
int pop(Stack *s);
int peek(Stack *s);
int isEmptyStack(Stack *s);

struct AdjListNode *newAdjListNode(int dest);
struct Graph *createGraph(int V);
void addEdge(struct Graph *graph, int src, int dest);
void printGraph(struct Graph *graph);

void DFS(struct Graph *graph, int source, int key);

int main()
{
    // create a graph to test above functions
    int V = 5;
    struct Graph *graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    // print the adjacency list representation of the above graph
    printGraph(graph);

    printf("\n");

    DFS(graph, 0, 4);

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

void push(Stack *s, int value)
{
    insertNode(&(s->ll), 0, value);
}

int pop(Stack *s)
{
    int item = 0;
    item = s->ll.head->dest;
    removeNode(&(s->ll), 0);
    return item;
}

int peek(Stack *s)
{
    return s->ll.head->dest;
}

int isEmptyStack(Stack *s)
{
    if (s->ll.size == 0) return 1;
    return 0;
}

// a utility function to create a new adjacency list node
struct AdjListNode *newAdjListNode(int dest)
{
    struct AdjListNode *newNode = (struct AdjListNode *)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// a utility function to create a graph of V vertices
struct Graph *createGraph(int V)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;

    // create an array of adjacency lists, size of array will be V
    graph->array = (struct AdjList *)malloc(V * sizeof(struct AdjList));

    // create an array of visited status
    graph->visited = (int *)malloc(V * sizeof(int));

    // Initialize each adjacency list as empty by making head as NULL
    int i;
    for (i=0; i<V; i++)
    {
        graph->array[i].head = NULL;
    }
    return graph;
}

// Adds an edge to an undirected graph
void addEdge(struct Graph *graph, int src, int dest)
{
    // add an edge from src to dest
    // a node is added to the adjacency list of src
    // the node is added at the beginning
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

}

// a utility function to print the adjacency list representation of graph
void printGraph(struct Graph *graph)
{
    int v;
    for (v=0; v<graph->V; ++v)
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

void DFS(struct Graph *graph, int src, int dest)
{
    struct AdjListNode *tmp = NULL;

    // mark v as visited
    graph->visited[src] = 1;
    // for each neighbour w of v do
    if (src == dest)
    {
        printf(" Found in 1 search\n");
        return;
    }
    tmp = graph->array[src].head;
    count++;
    while (tmp != NULL)
    {
        if (tmp->dest == dest)
        {
            printf(" Found in %d searches\n", count + 1);
            return;
        }
        // if w is unvisited then
        if (graph->visited[tmp->dest] == 0)
            // recursion
            DFS(graph, tmp->dest, dest);
        tmp = tmp->next;
    }
}