#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stdlib.h>

#define QUEUE_LEN 100

typedef struct Queue
{
    char* string_arr[QUEUE_LEN];
    size_t size;
} Queue_t;

void  init   (Queue_t*);
void  insert (Queue_t*, const char*);
void  pop    (Queue_t*);
void  clear  (Queue_t*);
bool  isEmpty(Queue_t*);
char* first  (Queue_t*);

#endif