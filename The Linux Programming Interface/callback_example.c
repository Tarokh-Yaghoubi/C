
/* 

    Author : Tarokh 
    Description : How callback works 

*/

#include <stdio.h>

// The callback function 

void sortingDoneCallback() {
    printf("Sorting is Done \n");
}

void sortNumbers(int numbers[], int size, void(*callback)())
{
    // pretend that sorting has happened here
    // for this example we will just print the numbers.

    printf("Sorted numbers : \n");
    for (int i = 0; i < size; ++i) {
        printf("%d ", numbers[i]);
    }

    printf("\n");

    // call the callback function to let the caller know that sorting is done .
    callback();
}

int main(void) {
    int numbers[] = {3, 4, 5, 687, 9, 1, 2, 4, 56, 6, 3};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    sortNumbers(numbers, size, sortingDoneCallback);

    return 0;
}
