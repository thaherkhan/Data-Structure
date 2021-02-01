#include<stdio.h>

struct stack
{
    unsigned int capacity;
    int top;
    int *array;
};

struct stack *makeStack(unsigned c)
{
    struct stack *newStack = (struct stack *)malloc(sizeof(struct stack));
    newStack->capacity = c;
    newStack->top = -1;
    newStack->array = (int *)malloc(c * sizeof(int));
    return newStack;
}

int isFull(struct stack *s)
{
    return (s->capacity-1) == s->top;
}

int isEmpty(struct stack *s)
{
    return (s->top == -1);
}

void push(struct stack *s, int item)
{
    //Check overflow
    if( isFull(s) )
    {
        printf("Stack Overflow.\n");
        return;
    }
    s->array[++s->top] = item;
}

int pop(struct stack *s)
{
    //Check underflow
    if( isEmpty(s) )
    {
        printf("Stack Underflow.\n");
        return ;
    }
    return s->array[s->top--];
}

int peel(struct stack *s)
{
    //Check Underflow
    if( isEmpty(s) )
    {
        printf("Array Underflow.\n");
        return;
    }
    return s->array[s->top];
}

int main()
{
    unsigned int capacity;
    printf("Array size = ");
    scanf("%u", &capacity);
    struct stack *newStack = makeStack(capacity);
    int data;
    scanf("%d", &data);
    while(data != 0)
    {
        push(newStack, data);
        if( isFull(newStack) )
        {
            printf("Stack is Full.\n");
            break;
        }
        scanf("%d",&data);
    }
    printf("\n\nPopping...\n");
    while( ! isEmpty(newStack))
    {
        printf("%d\n", pop(newStack));
    }
}
