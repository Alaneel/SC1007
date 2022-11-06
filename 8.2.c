// Algorithm 2 Infix Expression to Postfix Expression

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct node {
    char item;
    struct node *next;
} ListNode;

typedef struct linkedlist {
    int size;
    ListNode *head;
} LinkedList;

typedef struct stack {
    LinkedList ll;
} Stack;

ListNode *findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, char value);
int removeNode(LinkedList *ll, int index);
void push(Stack *s, char value);
char pop(Stack *s);
char peek(Stack *s);

int evaluate(char operand1, char operator, char operand2);
void In2Post(char *infix, char postfix[]);
int ExePost(char *postfix);

int main() {
    int i;
    char *infix = "2 + 1 * 3 - 4 * (2 / 2)", postfix[30];
    In2Post(infix, postfix);
    for (i=0; postfix[i] != '\0'; i++)
        printf("%c", postfix[i]);
    printf("ExePost(): %d\n", ExePost(postfix));
    return 0;
}

ListNode *findNode(LinkedList *ll, int index)
{
    ListNode *tmp = ll->head;

    if (tmp == NULL || index < 0) return NULL;

    while (index > 0)
    {
        tmp = tmp->next;
        if (tmp == NULL) return NULL;
        index--;
    }
    return tmp;
}

int insertNode(LinkedList *ll, int index, char value)
{
    ListNode *pre = NULL, *cur = NULL;

    if (ll->head == NULL || index == 0)
    {
        cur = ll->head;
        ll->head = malloc(sizeof(ListNode));
        ll->head->item = value;
        ll->head->next = cur;
        (ll->size)++;
        return 0;
    }

    if (findNode(ll, index - 1) != NULL)
    {
        pre = findNode(ll, index - 1);
        cur = pre->next;
        pre->next = malloc(sizeof(ListNode));
        pre->next->item = value;
        pre->next->next = cur;
        (ll->size)++;
        return 0;
    }
    return -1;
}

int removeNode(LinkedList *ll, int index)
{
    ListNode *pre = NULL, *cur = NULL;

    if (ll->head->next == NULL || index == 0)
    {
        cur = ll->head->next;
        free(ll->head);
        ll->head = cur;
        (ll->size)--;
        return 0;
    }

    if (findNode(ll, index - 1) != NULL)
    {
        pre = findNode(ll, index - 1);
        cur = pre->next->next;
        free(pre->next);
        pre->next = cur;
        (ll->size)--;
        return 0;
    }
    return -1;
}

void push(Stack *s, char value)
{
    insertNode(&(s->ll), 0, value);
}

char pop(Stack *s)
{
    char item = '\0';
    item = (s->ll).head->item;
    removeNode(&(s->ll), 0);
    return item;
}

char peek(Stack *s)
{
    return s->ll.head->item;
}

int evaluate(char operand1, char operator, char operand2)
{
    int i = 0;
    int opd1 = 1, opd2 = 1;
    char numbers[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    for (i=0; i<9; i++)
    {
        if (operand1 == numbers[i])
            opd1 = i;
        if (operand2 == numbers[i])
            opd2 = i;
    }   

    switch (operator)
    {
        case '+': return opd1 + opd2;
        case '-': return opd1 - opd2;
        case '*': return opd1 * opd2;
        case '/': return opd1 / opd2;
        default: return -1;
    }


}

void In2Post(char *infix, char postfix[])
{
    Stack s;
    s.ll.head = NULL;
    s.ll.size = 0;
    int count = 0;
    char c;

    while (*infix != '\0')
    {
        if (isdigit(*infix))
        {
            postfix[count] = *infix;
            count++;
        }
        else if (*infix == ')')
        {
            while (peek(&s) != '(')
            {
                postfix[count] = pop(&s);
                count++;
            }
            pop(&s);
        }
        else if (*infix == '(')
            push(&s, *infix);
        else
        {
            if (ispunct(*infix))
            {
                while (s.ll.size != 0 && peek(&s) != '(')
                {
                    if ((*infix == '+' || *infix == '-') && (peek(&s) == '*' || peek(&s) == '/' || peek(&s) == '+' || peek(&s) == '-'))
                    {
                        postfix[count] = pop(&s);
                        count++;
                    }
                    else if ((*infix == '*' || *infix == '/') && (peek(&s) == '*' || peek(&s) == '/'))
                    {
                        postfix[count] = pop(&s);
                        count++;
                    }
                    else break;
                }  
                push(&s, *infix);
            }
        }
        infix++;
    }

    while (s.ll.size != 0)
    {
        c = pop(&s);
        postfix[count] = c;
        count++;
    }
    postfix[count] = '\0';
}

int ExePost(char *postfix)
{
    Stack s;
    s.ll.head = NULL;
    s.ll.size = 0;
    char operand1 = '\0', operand2 = '\0', result_ch = '\0';
    char numbers[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int result = 0, i = 0;

    while (*postfix != '\0')
    {
        if (isdigit(*postfix))
            push(&s, *postfix);
        else if (ispunct(*postfix))
        {
            operand1 = pop(&s);
            operand2 = pop(&s);
            result = evaluate(operand2, *postfix, operand1);

            for (i=0; i<9; i++)
                if (result == i) result_ch = numbers[i];

            push(&s, result_ch);
        }
        postfix++;
    }

    return result;
}