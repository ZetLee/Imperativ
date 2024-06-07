#include "queue.h"
#include <stdio.h>

#define STR_LEN 16

void read_from_file(Queue_t* Q, char* filename)
{
    FILE* file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Couldn't open the file");
    }

    char buffer[STR_LEN];
    while (fgets(buffer, STR_LEN, file) != NULL)
    {
        insert(Q, buffer);
    }
}



int main()
{
    Queue_t Q;
    init(&Q);
    read_from_file(&Q, "input.txt");
    clear(&Q);
    return 0;
}