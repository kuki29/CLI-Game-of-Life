#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <chrono>
#include <random>

using namespace std;

const unsigned int FIELD_HEIGHT = 29;
const unsigned int FIELD_WIDTH = 119;

const char ALIVE = 'O';
const char DEAD = ' ';

int field[FIELD_HEIGHT][FIELD_WIDTH + 1] = { 0 };

void printField();
void nextGen();
int neighbors(int i, int j);

int main()
{
	srand((unsigned int) time(NULL));

	int aliveAtStart = rand() % (FIELD_HEIGHT * FIELD_WIDTH) + 1;
	int val;


	if (aliveAtStart < 100)
	{
		aliveAtStart += 25;
	}

	for (int i = 0; i < aliveAtStart; i++)
	{
		val = rand();
		field[val % FIELD_HEIGHT][val % FIELD_WIDTH] = 1;
	}

	char quite = ' ';
	int gen = 0;

	do
	{
		system("cls");
		gen++;
		printField();
		nextGen();

		printf("\nGeneration: %d", gen);

		if (gen % 100 == 0)
		{
			Sleep(1000);
		}
		else if (gen % 50 == 0)
		{
			Sleep(500);
		}
		else
		{
			Sleep(250);
		}
	} while (quite != 'q' || quite != 'Q');

	system("pause");
	return EXIT_SUCCESS;
}

void printField()
{
	for (int i = 0; i < FIELD_HEIGHT; i++)
	{
		for (int j = 0; j < FIELD_WIDTH; j++)
		{
			printf("%c", (field[i][j] == 1 ? ALIVE : DEAD));
		}

		cout << endl;
	}
}

int neighbors(int i, int j) {
	int nb = 0;

	if (field[i - 1][j - 1] == 1) nb++;
	if (field[i - 1][j] == 1) nb++;
	if (field[i - 1][j + 1] == 1) nb++;
	if (field[i][j - 1] == 1) nb++;
	if (field[i][j + 1] == 1) nb++;
	if (field[i + 1][j - 1] == 1) nb++;
	if (field[i + 1][j] == 1) nb++;
	if (field[i + 1][j + 1] == 1) nb++;

	return nb;
}

void nextGen()
{
	for (int i = 0; i < FIELD_HEIGHT; i++)
	{
		for (int j = 0; j < FIELD_WIDTH; j++)
		{
			if (field[i][j] == 0 && neighbors(i, j) == 3)
			{
				field[i][j] = 1;
			}

			if (field[i][j] == 1 && (neighbors(i, j) < 2 || neighbors(i, j) > 3))
			{
				field[i][j] = 0;
			}
		}
	}
}