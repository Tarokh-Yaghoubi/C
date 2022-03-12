/* The distance of a marathon 
 * in kilometers
 * Tarokh Yaghoubi - University of California 
 * C for Everybody online course 
 * SAT MAR 12 2022 
 * */

#include <stdio.h>

int main(void)
{
    
    int miles = 26, yards = 385;
    double kilometers;
    
    kilometers = 1.609 * (miles + yards / 1760.0);
    printf("\nMarathon is %lf kilometers . \n\n", kilometers);
    return 0;

}
