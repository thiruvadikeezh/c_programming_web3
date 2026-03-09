#include <stdio.h>
#include <stdbool.h>

#define SIZE 5

typedef struct {
    int buffer[SIZE];
    int head;
    int tail;
} cbuff;

void buffer_init(cbuff *cb)
{
    cb->head = 0;
    cb->tail = 0;
}

bool buffer_empty(cbuff *cb)
{
    return cb->head == cb->tail;
}

bool buffer_full(cbuff *cb)
{
    return ((cb->head + 1) % SIZE) == cb->tail;
}

void buffer_push(cbuff *cb, int data)
{
    if(buffer_full(cb))
    {
        printf("Buffer Full\n");
        return;
    }

    cb->buffer[cb->head] = data;
    cb->head = (cb->head + 1) % SIZE;
}

int buffer_pop(cbuff *cb)
{
    if(buffer_empty(cb))
    {
        printf("Buffer Empty\n");
        return -1;
    }

    int data = cb->buffer[cb->tail];
    cb->tail = (cb->tail + 1) % SIZE;

    return data;
}

int main()
{
    cbuff cb;

    buffer_init(&cb);

    buffer_push(&cb,10);
    buffer_push(&cb,20);
    buffer_push(&cb,30);

    printf("%d\n", buffer_pop(&cb));
    printf("%d\n", buffer_pop(&cb));

    buffer_push(&cb,40);
    buffer_push(&cb,50);

    while(!buffer_empty(&cb))
    {
        printf("%d\n", buffer_pop(&cb));
    }

    return 0;
}
