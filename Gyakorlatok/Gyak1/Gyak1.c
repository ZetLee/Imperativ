#include <stdio.h>
#define PI 3.14

int main()
{
    printf("Hello World!\n");
    printf("A nevem %s\n", "Zetlee");

    int a = 5;
    int b = 6;
    printf("%d + %d = %d\n", a, b, a + b);
    printf("%d * %d = %d\n", a, b, a * b);
    printf("%d / %d = %d\n", a, b, a / b);

    float c = 6;
    printf("%d / %f = %f\n", a, c, a / c);

    float r;
    printf("Add meg a kor sugarat: \n");
    scanf("%f", &r);
    printf("Kor ketulete: %f\nKor terulete: %f\n", 2 * r * PI, r * PI * PI);

    int days;
    printf("Add meg a napok szamat: \n");
    scanf("%d", &days);
    int year = days / 365;
    int week = (days - year * 365) / 7;
    int day  = (days - year * 365) - week * 7;
    printf("%d ev, %d het, %d nap.\n", year, week, day);
    return 0;
}