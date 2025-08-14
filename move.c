#define _CRT_SECURE_NO_WARNINGS
#include "move.h"
#include "calc.h"

int move_up(int* board, int size)
{
    int col, row, check = 0;
    for (col = 0; col < size; col++)
    {
        for (row = 1; row < size; row++)
        {
            int value = *(board + (size * row) + col);
            if (value != 0)
            {
                int k = row;
                while (k > 0 && *(board + (size * (k - 1)) + col) == 0)
                {
                    swap(board + (size * k) + col, board + (size * (k - 1)) + col);
                    check = 1;
                    k--;

                }
            }
        }
    }
    return check;
}

int move_down(int* board, int size)
{
    int col, row, check = 0;
    for (col = 0; col < size; col++)
    {
        for (row = size - 2; row >= 0; row--)
        {
            int value = *(board + (size * row) + col);
            if (value != 0)
            {
                int k = row;
                while (k + 1 < size && *(board + (size * (k + 1)) + col) == 0)
                {
                    swap(board + (size * k) + col, board + (size * (k + 1)) + col);
                    check = 1;
                    k++;

                }
            }
        }
    }
    return check;
}

int move_right(int* board, int size)
{
    int col, row, check = 0;
    for (row = 0; row < size; row++)
    {
        for (col = size - 2; col >= 0; col--)
        {
            int value = *(board + (size * row) + col);
            if (value != 0)
            {
                int k = col;
                while (k + 1 < size && *(board + (size * row) + (k + 1)) == 0)
                {
                    swap(board + (size * row) + k, board + (size * row) + (k + 1));
                    check = 1;
                    k++;
                }
            }
        }
    }
    return check;
}

int move_left(int* board, int size)
{
    int col, row, check = 0;
    for (row = 0; row < size; row++)
    {
        for (col = 1; col < size; col++)
        {
            int value = *(board + (size * row) + col);
            if (value != 0)
            {
                int k = col;
                while (k > 0 && *(board + (size * row) + (k - 1)) == 0)
                {
                    swap(board + (size * row) + k, board + (size * row) + (k - 1));
                    k--;
                    check = 1;
                }
            }
        }
    }
    return check;
}





