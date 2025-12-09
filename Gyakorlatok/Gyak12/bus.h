#ifndef BUS_H
#define BUS_H

#define MAX_STOPS 100 // It didnt specify if I can do this

typedef struct Stop 
{
    char* name;
    int x;
    int y;
} Stop_t;

typedef struct
{
    Stop_t array[MAX_STOPS];
    int len;                //current amount
} List_t;

void create_bus_stop(List_t* stops, char* name, int x, int y);
void delete_bus_stop(List_t* stops);
void print_bus_stop(List_t* stops);
void show_map(List_t* stops);

#endif