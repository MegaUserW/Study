// Lesson7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>

void swapValues(int &val1, int &val2)
{
	int buff = val1;
	val1 = val2;
	val2 = buff;
}
bool someCheck(int val1, int val2, int val3)
{
	if ((val1 >= val2 && val1 <= val3) || (val1 <= val2 && val1 >= val3))
		return true;
	else
		return false;
}
int getDefVal(int val1, int val2, int val3)
{
	if (someCheck(val1, val2, val3))
		return val1;
	if (someCheck(val2, val1, val3))
		return val2;
	if (someCheck(val3, val2, val1))
		return val3;
}
void quickSort(int* arr, int start, int end, int minLen)
{
	int pos1 = start;
	int pos2 = end - 1;
	int defVal = arr[(start + end) / 2];
	
	do
	{
		while (arr[pos1] < defVal)
			pos1++;
		while (arr[pos2] > defVal)
			pos2--;
		if (pos1 <= pos2)
		{
			swapValues(arr[pos1], arr[pos2]);
			pos1++;
			pos2--;
		}
	}
	while(pos1 <= pos2);
	if (pos1 < end)
		quickSort(arr, pos1, end, minLen);
	if (pos2 > start)
		quickSort(arr, start, pos2, minLen);
}

void printArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
void initArray(int* arr, int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
		arr[i] = rand() % 100 + 1;
}

void task1()
{
	const int S_ARR = 100;
	int arr[S_ARR];
	initArray(arr, S_ARR);
	int startPos = 0;
	int minLen = 10;
	printArray(arr, S_ARR);
	quickSort(arr, startPos, S_ARR, minLen);
	printArray(arr, S_ARR);
  }
int getNextDefVal(int* arr, int size, int pos)
{
	while (arr[pos] % 2 != 0 && pos < size)
		pos++;
	if (pos == size)
		return -1;
	else
		return pos;
}
void insSort(int* arr, int size)
{	
	int defValPos, defVal;
	int pos;
	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i + 1] % 2 != 0)
			continue;

		defValPos = i + 1;
		defVal = arr[defValPos];
		for (int j = i + 1; j > 0; j--)
		{
			if (arr[j - 1] % 2 != 0)
				continue;
			if (defVal < arr[j - 1])
			{
				pos = getNextDefVal(arr, size, j);
				if (pos == -1)
					continue;

				arr[pos] = arr[j - 1];
				defValPos = j - 1;
			}
		}
		arr[defValPos] = defVal;
	}
}

void task2()
{
	const int S_ARR = 15;
	int arr[S_ARR];
	initArray(arr, S_ARR);
	printArray(arr, S_ARR);
	insSort(arr, S_ARR);
	printArray(arr, S_ARR);

}
int main()
{
	//task1();
	task2();
}
