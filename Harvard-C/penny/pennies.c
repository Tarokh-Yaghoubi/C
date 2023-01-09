#include <stdio.h>
#include <math.h>

int main(void)
{
    float amount;
    
    amount = 0;
    scanf("%f", &amount);
    //get_float("Dollar amount : ");

    int pennies = round(amount * 100);

    printf("Pennies : %i\n", pennies);
}