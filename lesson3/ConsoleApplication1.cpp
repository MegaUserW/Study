#include <stdio.h>

int main()
{
    int n;
    printf("Enter  a number: ");
    scanf_s("%d", &n);
    bool flag = isNumPrime(n);
    if (flag)
        printf("This number is a prime number");
    else
        printf("This number isn't a prime number");
}

bool isNumPrime(int n)
{
    if (n > 1 || n % 2 == 0)
    {
        for (int i = 3; i < n; i++)
            if (n % i == 0)
                return false;

        return true;
    }
    else
        return false;
}