#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include "game.h"
#include "tools.h"
#include "move.h"
#include "merge.h"



void playGame(int* board, int size, int scoreToWin) {

	char choice;
	int fContinue = 1;
	initboard(board, size);
	printboard(board, size);
	int score = 0;
	int sum = 0;
	int best_score = score;
	int game_started = 0;

	do {
		if (!legalMove(board, size)) {
			printf("Game over your score is %d\n", score);
			initboard(board, size);
			game_started = 0;
		}

		printf("Please choose one of the following options: \n");
		printf("N/n - New Game \n");
		printf("R/r - Move Right \n");
		printf("L/l - Move Left \n");
		printf("U/u - Move Up \n");
		printf("D/d - Move Down \n");
		printf("E/e - Exit \n");
		choice = getchar();
		while (getchar() != '\n');


		choice = toupper(choice);
		if (choice == 'N') {
			game_started = 1;
			score = 0;
			sum = 0;
			initboard(board, size);
			printf("----------- STARTING A GAME ------------\n");
			printf("           Score for a win %d           \n", scoreToWin);
			printf("-----------------------------------------\n");
			printf("Score %d best %d\n", score, best_score);
			insert(board, size);
			insert(board, size);
			printboard(board, size);
		}
		else if (choice == 'E') 
		{
			fContinue = 0;
			printf("Ending previous game - your score %d best score %d \n", score, best_score);
			printf("Bye Bye\n");
		}

		else if (game_started)
		{
			if (choice == 'R') {
				int moved = move_right(board, size);
				int merged = merge_right(board, size, &score, &sum);
				move_right(board, size);
				if (moved || merged) {
					if (score > best_score) {
						best_score = score;
					}
					insert(board, size);
					printf("Score %d best %d\n", score, best_score);
					printboard(board, size);
				}
				else
				{
					printf("Nothing to move in this direction, choose another option\n");
				}
			}
			if (choice == 'L') {
				int moved = move_left(board, size);
				int merged = merge_left(board, size, &score, &sum);
				move_left(board, size);
				if (moved || merged) {
					if (score > best_score) {
						best_score = score;
					}
					insert(board, size);
					printf("Score %d best %d\n", score, best_score);
					printboard(board, size);
				}
				else {
					printf("Nothing to move in this direction, choose another option\n");
				}
			}
	
			if (choice == 'U') {
				int moved = move_up(board, size);
				int merged = merge_up(board, size, &score, &sum);
				move_up(board, size);
				if (moved || merged) {
					if (score > best_score) {
						best_score = score;
					}
					insert(board, size);
					printf("Score %d best %d\n", score, best_score);
					printboard(board, size);
				}
				else
				{
					printf("Nothing to move in this direction, choose another option\n");
				}
			}
			if (choice == 'D') {
				int moved = move_down(board, size);
				int merged = merge_down(board, size, &score, &sum);
				move_down(board, size);
				if (moved || merged) {
					if (score > best_score) {
						best_score = score;
					}
					insert(board, size);
					printf("Score %d best %d\n", score, best_score);
					printboard(board, size);
				}
				else
				{
					printf("Nothing to move in this direction, choose another option\n");
				}
			}
			
			if (sum == scoreToWin)
			{
				printf("You Won %d! - Ending game \n", scoreToWin);
				initboard(board, size);
				score = 0;
				sum = 0;
				game_started = 0;
			}
		}
		else {
			printf("need to start game first \n");
		}
	}
	while (fContinue == 1);
}