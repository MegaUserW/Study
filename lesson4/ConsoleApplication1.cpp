// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string.h>
#include <stdlib.h>

void decToBin(int dec)
{
	if (dec < 0)
		return; 

	if (dec > 1)
	{
		decToBin(dec / 2);
		printf("%d", dec % 2);
	}
	else
		printf("%d", dec % 2);

	return;
}
int exp1(int degree, int num)
{
	if (degree == 0)
		return 1;
	else
		return num * exp1(degree - 1, num);

}
int exp2(int degree, int num)
{
	if (degree == 0)
		return 1;
	else
		if (degree % 2 == 0)
			return exp2(degree / 2, num * num);
		else
			return num * exp2(degree - 1, num);


}

#define SIZEX 3
#define SIZEY 3
int board[SIZEX][SIZEX];
int routes(int x, int y)
{
	printf("\n%d, %d, %d, %d", x, y, board[0][0], board[x][y]);
	if (board[x][y] == 0 && board[0][0] == 0 && x >= 0 && y >= 0)
	{
		if (x == 0 && y == 0)
		{
			printf(" xxxx");
			return 0;
		}
		else
		{
			if ((x == 0 && y == 1) || (x == 1 && y == 0) || (x == 1 && y == 1))
			{
				if (board[x][y] == 0)
				{
					printf(" bbb %d", board[x][y]);
					return 1;
				}
				else
				{
					printf(" ---bbb %d", board[x][y]);
					return 0;
				}
			}
		//	else
		//	if (x == 1 && y == 1)
		//	{
		//		printf(" ccc %d", board[x][y]);
		//		return   1;
			//}
				printf(" ddd %d", board[x][y]);
				return routes(x - 1, y - 1) + routes(x, y - 1) + routes(x - 1, y);
		}


	}
	else
	{
		printf(" zzzz");
		return 0;
	}
}

void initBoard()
{
	printf("\n");
	for (int i = 0; i <= SIZEY; i++)
	{
		for (int j = 0; j <= SIZEX; j++)
		{
			if ((i == 0 && j == 0) || 
				(i == SIZEY && j == SIZEX))
				board[j][i] = 0;
			else
				board[j][i] = rand() % 2;
			printf("%d ", board[j][i]);
		}
		printf("\n");
	}
}

int main()
{
	int val = 101;
	//decToBin(val);

	int degree = 11, num = 3;
	//printf("\n%d", exp1(degree, num));
	//printf("\n%d", exp2(degree, num));
	initBoard();
	int value = routes(SIZEX, SIZEY);
	printf("\n%d", value);

}
