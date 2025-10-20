#include <stdio.h>

int main()
{
    int a;
    printf("%d\n", a);
    a = 8;
    printf("%d\n", a);
    const int b = 7;
    // b = 3; Doesn't work!
    printf("%d\n", b);

    int c = 0;
    while (c % 2 != 1)
    {
        printf("Adj meg egy paratlan szamot: ");
        scanf("%d", &c);
    }
    printf("Ugyes vagy!\n");
    
    // TODO
    return 0;
}