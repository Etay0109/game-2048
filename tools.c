#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "tools.h"
#include "calc.h"
#include <stdlib.h>



void initboard(int* board, int size)
{
    int i;
    int j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            *(board + (i * size) + j) = 0;
        }
    }
}

void printboard(int* board, int size)
{
    int i;
    int j;

    for (i = 0; i < size; i++)
    {
        printf("-------");
    }
    printf("-\n");
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            int value = *(board + (size * i) + j);
            if (value == 0) {
                printf("| %5s", " ");
            }
            else {
                printf("| %5d", value);
            }

        }
        printf("|\n");
        for (j = 0; j < size; j++)
        {
            printf("-------");
        }
        printf("-\n");

    }
}

void insert(int* board, int size)
{
    int count = sumZeroInArr(board, size);
    int i;
    int j;
    int cell_num = rand() % count;
    int index = 0;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            char value = *(board + (size * i) + j);
            if (value == 0) {
                if (index == cell_num) {
                    *(board + (size * i) + j) = myRandom();
                    return;
                }
                index++;
            }
        }
    }
}

int legalMove(int* board, int size)
{
    int row, col;

    if (sumZeroInArr(board, size))
    {
        return 1;
    }
    for (row = 1; row < size; row++)
    {
        for (col = 0; col < size; col++)
        {
            if (*(board + (size * row) + col) != 0 && (*(board + (size * row) + col) == *(board + (size * (row - 1)) + col)
                || *(board + (size * (row - 1)) + col) == 0))
            {
                return 1;
            }
        }
    }
    for (row = 0; row < size; row++)
    {
        for (col = 1; col < size; col++)
        {
            if (*(board + (size * row) + col) != 0 && (*(board + (size * row) + col) == *(board + (size * row) + (col - 1))
                || *(board + (size * row) + (col - 1)) == 0))
            {
                return 1;
            }
        }
    }
    return 0;
}

