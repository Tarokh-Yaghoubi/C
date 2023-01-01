#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 10



 /*
 
 {
    Program number 17 
    Read ten numbers and list them from big to small
    ATTENTION : numbers are not useful after operation
 }

 */



int main()
{
	int i, max, min;
    int arr_size;
    arr_size = 10;
	int container[arr_size];
	int usernumber;
    int pos;
    int pos_max = 0, o = 0;

	i = max = min = 0;
	
	printf("Waiting for numbers to rain ... \n");
	for (i = 0; i < sizeof(container) / sizeof(container[0]); i++)
	{
		scanf("%d", &usernumber);
		container[i] = usernumber;
		if (max < container[i])
			max = container[i];
	}
   // printf("%d ", max);
    printf("\n-----------------------------------------------------------------------------\n");


	while (arr_size > 0)
	{
        max = 0;
        for (i = 0; i < arr_size; i++)
        {
            if (max < container[i])
            {
                max = container[i];
              //  printf(" %d ", max);

            }

        }
        for (int o = 0; o < arr_size; o++)
        {
            if (container[o] == max)
            {
               // printf("\nTHIS IS O : %d\n", o);
                pos_max = o;
            }

        }
        pos = pos_max;
        printf(" new arr : %d ", container[pos]);

        if (pos < 0 || pos > arr_size)
        {
            printf("Invalid position! Please enter position between 1 to %d", arr_size);
        }
        else
        {
            /* Copy next element value to current element */
            for (i = pos; i < arr_size; i++)
            {
                container[i] = container[i + 1];
            }

            /* Decrement array size by 1 */
            arr_size--;

        }
	}
  
    printf("\narr size is : %d\n", arr_size);
       
	return 0;
}