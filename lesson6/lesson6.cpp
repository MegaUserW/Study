#include <stdio.h>
#include <iostream>

void bubbleSort(int arr[], int size)
{
	int buff;
	for (int k = ((size * size) - 1); k > 0; k --)
		for (int i = 0; i < k; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				buff = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = buff;
			}
		}
}
void task1()
{
	const int S_ARR = 3;
	int arr[S_ARR][S_ARR] = { { 1,9,2 }, {5,7,6}, {4,3,8} };
	
	bubbleSort(*arr, S_ARR);

}


void askValues(double* arr, int size)
{
	printf("Use only int values\n");
	for (int i = 0; i < size; i++)
	{
		printf("Set arr[%d] = ", i + 1);
		scanf_s("%lf", &arr[i]);

	}

}
void invertArray(double* arr, int size)
{
	double buff;
	for (int i = 0; i < size / 2; i++)
	{
		buff = arr[i];
		arr[i] = arr[size - i - 1];
		arr[size - i - 1] = buff;
	}
		
}
void specialCheckArray(double* arr, int size)
{
	for (int i = 0; i < size; i++)
		if (sqrt(fabs(arr[i])) + 5 * pow(arr[i], 3) > 400)
			printf("\nsqrt(fabs(arr[%d])) + 5 * pow(arr[%d], 3) > 400", i + 1, i + 1);

}
void task2()
{
	const int S_ARR = 3;
	double arr[S_ARR];
	askValues(arr, S_ARR);
	invertArray(arr, S_ARR);
	specialCheckArray(arr, S_ARR);
}
int main()
{
	task1();
	task2();
}
