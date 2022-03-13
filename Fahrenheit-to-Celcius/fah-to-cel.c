/* This program converts fahrenheit to celcius 
 * Tarokh Yaghoubi University of California 
 * SUN MAR 13 2022 
 * */

#include <stdio.h>

int main(void)
{
    int fahrenheit, celcius;

    printf("Please enter fahrenheit as an integer :  ");
    scanf("%d", &fahrenheit);
    celcius = (fahrenheit - 32) / 1.8;
    printf("\n %d fahrenheit is %d celcius . \n", fahrenheit, celcius);
    return 0;
}
