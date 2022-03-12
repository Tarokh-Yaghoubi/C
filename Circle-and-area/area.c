/*
 * This is a simple program for
 * computing the area of a circle
 *
 * */


#include <stdio.h>
#define PI 3.14159

int main()
{
    double area = 0.0, radius = 0.0;
    printf("Enter radius : \n");
    scanf("%lf", &radius);
    area = PI * radius * radius;
    printf("The area of %lf is : %lf \n", radius, area);
    return 0;
}

