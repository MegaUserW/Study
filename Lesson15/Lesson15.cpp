// Lesson15.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

const int MAX_LENGTH = 100;
const int NUM_OF_DIFF_COINS = 5;
const int COINS[] = { 50, 10, 5, 2, 1 };

int simpleHashFunction(char* str, int len)
{
	int res = 0;
	int i = 0;
	while (str[i] != NULL)
	{
		res = res + (int)str[i];
		i++;
	}
	return res;
}
void getArrOfCoins(int sum, int *res)
{
	int i = 0, currCoin = COINS[i];

	while (sum != 0)
	{
		while (sum < currCoin)
		{
			currCoin = COINS[++i];
		}
		res[i] = res[i] + 1;
		sum = sum - currCoin;
		printf("\n%d", res[i]);

	} 

}
void printResult(int* arr)
{

	for (int i = 0; i < NUM_OF_DIFF_COINS; i++)
		if (arr[i] != NULL)
			printf("\nNeed %d coins of %d", arr[i], COINS[i]);
}
void initArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		arr[i] = 0;
}
int main()
{
	char str[MAX_LENGTH] = "Hello world1!";

	printf("%d", simpleHashFunction(str, MAX_LENGTH));

	int val = 98;
	int arrayOfCoins[NUM_OF_DIFF_COINS];
	initArray(arrayOfCoins, NUM_OF_DIFF_COINS);
	getArrOfCoins(val, arrayOfCoins);
	printResult(arrayOfCoins);
}
