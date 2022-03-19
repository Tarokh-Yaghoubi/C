#include <cs50.h>
#include <stdio.h>
float discount(float price, float percentage);


int main(void)
{
    float regular = get_float("Enter the regular : ");
    int percentage_off = get_int("Enter the percentage : ");
    float sale = discount(regular,percentage_off);
    printf("sale price %.2f \n", sale);
}

float discount(float price, float percentage)
{
    return price * (100 - percentage) / 100;
}