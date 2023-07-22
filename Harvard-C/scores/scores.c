
#include <stdio.h>
#include <cs50.h>

const int N = 3;

float average(int length, int[]);

int main(void) 
{
    int scores[N];
    
    for (int i = 0; i <  N; ++i)
        scores[i] = get_int("Score : ");

    printf("The average is : %f\n", average(N, scores));

    return 0;
}

float average(int length, int array[])
{
    int sum = 0;

    for (int i = 0; i < length; ++i)
    {
        sum += array[i];
    }

    return (float) sum / length;

}
