/*

	Tarokh (Jacob) Yaghoubi . Sort an array in C
	Sort the numbers from small to big .
    Bubble Sort .

*/

#include <stdio.h>
#include <string.h>

// printArray will print the array content 

void printArray(int arr[], int size);

int main()
{
    int temp;
    int arr[] = { 5, 6, 4, 8, 9, 2, 3, 10, 12, 13, 15, 16 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printArray(arr, n);
    return 0;

}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\n");
}
