#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "bus.h"

#define OFFSET -1
#define MAP_SIZE 10

bool is_valid_coord(int num)
{
    return 1 <= num && num <= 10;
}

void create_bus_stop(List_t* stops, char* name, int x, int y)
{
    printf("Creating %s\n", name);
    if (stops->len == MAX_STOPS)
    {
        printf("Array is full!\n");
        return;
    }
    stops->array[stops->len].x = is_valid_coord(x) ? x : 0; // for max point you have to ask for the info again if its invalid
    stops->array[stops->len].y = is_valid_coord(y) ? y : 0; // I will not do that here
    stops->array[stops->len].name = malloc((strlen(name) + 1) * sizeof(char)); // +1 for the '\0'!!!!
    strcpy(stops->array[stops->len].name, name);
    ++stops->len;
    printf("Created %s\n", stops->array[stops->len - 1].name);
}

void delete_bus_stop(List_t* stops)
{
    print_bus_stop(stops);
    printf("Which one do you want to delete?");
    int num;
    scanf("%d", &num);
    if (num < 1 || stops->len < num)
    {
        printf("Invalid number!\n");
        return;
    }
    printf("DEleting %s\n", stops->array[num + OFFSET].name);
    free(stops->array[num + OFFSET].name); // remember the offset!

    for (int i = num + OFFSET; i < stops->len - 1; ++i) // we dont do it for the last one
    {
        stops->array[i] = stops->array[i + 1];
    }
}

void print_bus_stop(List_t* stops)
{
    for (int i = 0; i < stops->len; ++i)
    {
        printf("%d:\t%s:\t%d, %d\n",i + 1, stops->array[i].name, stops->array[i].x, stops->array[i].y);
    }
}

void show_map(List_t* stops)
{
    char map[MAP_SIZE][MAP_SIZE];
    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; j++)
        {
            map[i][j] = '.';    // I will use '.' for easier debugging
        }
    }
    for (int i = 0; i < stops->len; i++)
    {
        map[stops->array[i].x + OFFSET][stops->array[i].y + OFFSET] = 'B';
    }
    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; j++)
        {
            putc(map[i][j], stdout);
        }
        putc('\n', stdout);
    }
}