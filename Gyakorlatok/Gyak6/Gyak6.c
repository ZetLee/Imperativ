#include <stdio.h>
#define LENGHT 10

// %p will cause warnings!

void pointers()
{
    
    int a = 5;
    printf("a:\tAddress: %p\n\tValue:   %d\n-----------------\n",
        &a, a);
    int* p = &a;
    printf("p:\tAddress: %p\n\tValue:   %p\n-----------------\n",
        &p, p);
    printf("\n-----------------\n");

    *p = 7;
    printf("a:\tAddress: %p\n\tValue:   %d\n-----------------\n",
        &a, a);
    printf("p:\tAddress: %p\n\tValue:   %p\n-----------------\n",
        &p, p);
    printf("\n-----------------\n");
    
    int b = 1;
    int** pp = &p;
    printf("a:\tAddress: %p\n\tValue:   %d\n-----------------\n",
        &a, a);
    printf("p:\tAddress: %p\n\tValue:   %p\n-----------------\n",
        &p, p);
    printf("b:\tAddress: %p\n\tValue:   %d\n-----------------\n",
        &b, b);
    printf("pp:\tAddress: %p\n\tValue:   %p\n-----------------\n",
        &pp, pp);
    printf("\n-----------------\n");
    
    *pp = &b;
    *p = 9;
    printf("a:\tAddress: %p\n\tValue:   %d\n-----------------\n",
        &a, a);
    printf("p:\tAddress: %p\n\tValue:   %p\n-----------------\n",
        &p, p);
    printf("b:\tAddress: %p\n\tValue:   %d\n-----------------\n",
        &b, b);
    printf("pp:\tAddress: %p\n\tValue:   %p\n-----------------\n",
        &pp, pp);
}

void fill_array(int* array, int size)
{
    for (int i = 0; i < size; ++i)
    {
        array[i] = i;
    }
}

void print_array(int* array, int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int sum_array1(int* array, int size)
{
    int sum = 0;
    for (int i = 0; i < size; ++i)
    {
        sum += *(array + i); // array[i]
    }
    return sum;
}


int sum_array2(int* first, int* last)
{
    int sum = 0;
    while (first != last)
    {
        sum += *(first++);
    }
    return sum;
}

float average_array(int* first, int* last)
{
    return sum_array2(first, last) / (float)(last - first);
}

int main()
{
    pointers();

    int array[LENGHT];
    fill_array(array, LENGHT);
    print_array(array, LENGHT);
    printf("sum1: %d\nsum2: %d\n",
        sum_array1(array, LENGHT),
        sum_array2(array, array + LENGHT));
    printf("Avg: %f", average_array(array, array + LENGHT));

    return 0;
}