#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bus.h"

// TODO file and routing

int main()
{
    List_t list;
    list.len = 0;
    create_bus_stop(&list, "Moricz", 1, 2);
    create_bus_stop(&list, "Corvin", 4, 3);
    create_bus_stop(&list, "Blaha", 5, 5);
    create_bus_stop(&list, "Nyugati", 4, 7);
    create_bus_stop(&list, "Hibas", 4, 11);
    create_bus_stop(&list, "Torlendo", 4, 7);
    create_bus_stop(&list, "Szell Kalman", 2, 9);
    delete_bus_stop(&list);
    print_bus_stop(&list);
    show_map(&list);

    for (int i = 0; i < list.len; i++)
    {
        free(list.array[i].name);
    }
    
}