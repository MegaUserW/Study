// Lesson16.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
const int SIZE_OF_MESSAGE = 100;
const char ZERO_CHAR = '_';
const int SIZE_OF_ALPHABET = 26;
const char ALPHABET[SIZE_OF_ALPHABET] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

void printMessage(char* message, int size = SIZE_OF_MESSAGE)
{
	printf("\n");
	for (int i = 0; i < size; i++)
		printf("%c", message[i]);
}

int getPosInAlphabet(char ch, bool isCapital)
{
	if (isCapital)
		ch = tolower(ch);

	for (int i = 0; i < SIZE_OF_ALPHABET; i++)
		if (ch == ALPHABET[i])
			return i;

	return -1;
}
void cryptChar(char& ch, int shift)
{
	bool isCapital = !islower(ch);
	int	pos = getPosInAlphabet(ch, isCapital);
	if (pos != -1)
	{
		pos = (pos + shift) % SIZE_OF_ALPHABET;
		ch = (isCapital) ? toupper(ALPHABET[pos]) : ALPHABET[pos];
	}
}
int getCorrectShift(int shift, bool decrypt = false)
{
	shift = shift % SIZE_OF_ALPHABET;
	if (decrypt)
		return shift * (-1) + SIZE_OF_ALPHABET;
	else
		if (shift < 0)
			return shift + SIZE_OF_ALPHABET;

	return shift;
}
void cesar(char* message, int shift, bool decrypt = false)
{

	shift = getCorrectShift(shift, decrypt);
	printf("\n%d", shift);
	int i = 0;
	while (message[i] != NULL)
	{
		cryptChar(message[i], shift);
		i++;
	}
}
void encryptTransposition(char *message, int key)
{
	char table[SIZE_OF_MESSAGE][SIZE_OF_MESSAGE];

	int i = 0;
	int k = 0, pos = 0;

	while (message[i] != NULL || pos != 0)
	{
		if (message[i] != NULL)
			table[k][pos] = message[i];
		else
			table[k][pos] = ZERO_CHAR;


		i++;
		pos++;
		if (pos == key)
		{
			pos = 0;
			k++;
		}
	}
	for (int t = 0; t < k; t++)
	{
		printf("\n");
		for (int j = 0; j < key; j++)
			printf("%c ", table[t][j]);
	}

	printf("\n");
	pos = 0;
	for (int j = key - 1; j >= 0; j--)
	{
		for (int t = 0; t < k; t++)
		{
			if (table[t][j] != NULL)
				message[pos] = table[t][j];
			else
				message[pos] = ZERO_CHAR;

			pos++;

		}
	}
}
int getLen(char* message)
{
	int i = 0;
	while (message[i] != NULL)
		i++;
	return i;
}
void decryptTransposition(char* message, int key)
{
	char table[SIZE_OF_MESSAGE][SIZE_OF_MESSAGE];
	int len = getLen(message) / key;
	int i = 0;
	int k = 0, pos = key - 1;

	while (message[i] != NULL)
	{
		table[k][pos] = message[i];
		k++;
		if (k == len)
		{
			pos--;
			k = 0;
		}
		i++;
	}
	pos = 0;

	for (int t = 0; t < len; t++)
	{
		printf("\n");
		for (int j = 0; j < key; j++)
			printf("%c ", table[t][j]);
	}

	printf("\n");
	for (int t = 0; t < len; t++)
	{
		for (int j = 0; j < key; j++)
		{
			if (table[t][j] != NULL)
			{
				if (table[t][j] == ZERO_CHAR)
					message[pos] = NULL;
				else
					message[pos] = table[t][j];
				pos++;
			}
		}
	}
}

int main()
{
	char message[SIZE_OF_MESSAGE] = "Hello world!";

	printMessage(message);
	encryptTransposition(message, 5);
	printMessage(message);
	decryptTransposition(message, 5);
	printMessage(message);



}
