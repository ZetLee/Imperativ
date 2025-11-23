#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LEN 100

char* get_str(char* filename)
{
    FILE* file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Could't open file");
        return 0;
    }
    char buff[LEN];
    fgets(buff, LEN, file);
    char* str = malloc(strlen(buff) * sizeof(char));
    strcpy(str, buff);
    return str;
}

void reverse(char* str)
{
    int len = strlen(str) - 2;
    char tmp;
    for (int i = 0; i < (len / 2) + 1; i++)
    {
        tmp = str[i];
        str[i] = str[len - i];
        str[len - i] = tmp;
    }
}

char** poem(char* filename, int* size)
{
    FILE* file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Could't open file");
        return 0;
    }
    char buff[LEN];
    fgets(buff, LEN, file);
    *size = atoi(buff);
    char** ret = malloc(*size * sizeof(char*));
    for (int i = 0; i < *size; i++)
    {
        fgets(buff, LEN, file);
        ret[i] = malloc(strlen(buff) * sizeof(char));
        strcpy(ret[i], buff);
    }
    return ret;
}