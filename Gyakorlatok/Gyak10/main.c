#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char* str = get_str("in.txt");
    reverse(str);
    fputs(str, stdout);
    free(str);
    int size = 0;
    char** p = poem("in.txt", &size);
    for (int i = 0; i < size; i++)
    {
        printf("%s", p[i]);
        free(p[i]);
    }
    free(p);
    return 0;
}