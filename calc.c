#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "calc.h"


int myRandom()
{
    float prob_num2 = 0.7f;
    float rand_value = (float)rand() / RAND_MAX;
    if (rand_value < prob_num2) {
        return 2;
    }
    else {
        return 4;
    }
}


int sumZeroInArr(int* board, int size)
{
    int count = 0;
    int i;
    int j;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            char value = *(board + (size * i) + j);
            if (value == 0)
                count++;
        }
    }
    return count;
}
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}



