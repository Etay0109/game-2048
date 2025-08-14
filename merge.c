#define _CRT_SECURE_NO_WARNINGS
#include "merge.h"

int merge_up(int* board, int size, int* score, int* sum) {
	int row, col;
	int check = 0;

	for (col = 0; col < size; col++) {
		for (row = 1; row < size; row++) {
			if (*(board + (size * row) + col) != 0 &&
				*(board + (size * row) + col) == *(board + (size * (row - 1)) + col)) {
					*sum = *(board + (size * row) + col) * 2;
					*(board + (size * (row - 1)) + col) = *sum;
					*(board + (size * row) + col) = 0;
					*score += *sum;
					check = 1;
					break;
				}
			}
	}
	return check;
}


int merge_down(int* board, int size, int* score, int* sum) {
	int row, col;
	int check = 0;

	for (col = 0; col < size; col++) {
		for (row = size - 2; row >= 0; row--) {
			if (*(board + (size * row) + col) != 0 &&
				*(board + (size * row) + col) == *(board + (size * (row + 1)) + col)) {
				*sum = *(board + (size * row) + col) * 2;
					*(board + (size * (row + 1)) + col) = *sum;
					*(board + (size * row) + col) = 0;
					*score += *sum;
					check = 1;
					break;
				}
			}
		}
	return check;
}


int merge_right(int* board, int size, int* score, int* sum) {
	int row, col;
	int check = 0;

	for (row = 0; row < size; row++) {
		for (col = size - 2; col >= 0; col--) {
			if (*(board + (size * row) + col) != 0 &&
				*(board + (size * row) + col) == *(board + (size * row) + col + 1)) {
				*sum = *(board + (size * row) + col) * 2;
				*(board + (size * row) + col + 1) = *sum;
				*(board + (size * row) + col) = 0;
				*score += *sum;
				check = 1;
				break;
			}
			}
		}
		return check;
	}




int merge_left(int* board, int size, int* score, int* sum) {
	int row, col;
	int check = 0;

	for (row = 0; row < size; row++) {
		for (col = 1; col < size; col++) {
			if (*(board + (size * row) + col) != 0 &&
				*(board + (size * row) + col) == *(board + (size * row) + col - 1)) {
					*sum = *(board + (size * row) + col) * 2;
					*(board + (size * row) + col - 1) = *sum;
					*(board + (size * row) + col) = 0;
					*score += *sum;
					check = 1;
					break;
				}
			}
		}
	return check;
	}


