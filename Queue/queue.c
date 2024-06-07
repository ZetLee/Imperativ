#include "queue.h"
#include <string.h>
#include <stdio.h>

void  init(Queue_t* this)
{
    this->size = 0;
}

void insert(Queue_t* this, const char* str)
{
    if (this->size == QUEUE_LEN)
    {
        printf("The queue is full!\n");
        return;
    }
    this->string_arr[this->size] = malloc(strlen(str) + 1);
    strcpy(this->string_arr[this->size], str);
    ++this->size;
}

void pop(Queue_t* this)
{
    if (isEmpty(this))
    {
        printf("The queue is empty!");
    }
    printf("Deleted: %s\n", this->string_arr[0]);
    free(this->string_arr[0]);
    for (size_t i = 0; i < this->size - 1; i++)
    {
        this->string_arr[i] = this->string_arr[i + 1];
    }
    --this->size;
}

void clear(Queue_t* this)
{
    while (!isEmpty(this))
    {
        pop(this);
    }
}

bool isEmpty(Queue_t* this)
{
    return this->size == 0;
}

char* first(Queue_t* this)
{
    if (isEmpty(this))
    {
        return NULL;
    }
    return this->string_arr[0];
}