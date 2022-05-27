
#include <iostream>
const int SIZE = 10;

typedef struct {
    int val;
    int pri;
}myType;

myType *someArray[SIZE];
int begin, end, count;
void initArray()
{
    for (int i = 0; i < SIZE; i++)
        someArray[i] = NULL;

    begin = 0;
    end = 0;
    count = 0;
}
void printQueue()
{
    printf("{ ");
    for (int i = 0; i < SIZE; i++)
    {
        if (someArray[i] == NULL)
            printf("[_,_]");
        else
            printf("[%d,%d]", someArray[i]->pri, someArray[i]->val);
    }
    printf(" }\n");
}
int insItem(int pri, int val)
{
    myType* insVal = (myType*) malloc(sizeof(myType));
    insVal->pri = pri;
    insVal->val = val;

    if (count == 0)
    {
        count++;
        someArray[end++] = insVal; 
        return 1;
    }
    else
    {
        if (count == SIZE)
            return -1;
        else
        {
            int i = 0;
            myType* buff;
            for (i = begin; i < end; i++)
                if (someArray[i % SIZE]->pri < pri)
                    break;
            printf("%d\n", i);
            int insPos = i % SIZE;
            
            i++;
            int pos;
            while (i <= end)
            {
                pos = i % SIZE;
                buff = someArray[pos];
                someArray[pos] = someArray[insPos];
                someArray[insPos] = buff;
                i++;
            }
            count++;
            end++;
            someArray[insPos] = insVal;
            return 1;
        }
    }
}
myType* rmItem()
{
    if (count == 0)
        return NULL;
    else
    {
        int pos = begin++ % SIZE;
        myType* buff = someArray[pos];
        someArray[pos] = NULL;
        count--;
        return buff;
    }
}
const int SIZE_S = 1000;
int stack[SIZE_S];

int curPosOfStack = -1;

int pushStack(int val)
{
    if (curPosOfStack < SIZE_S)
    {
        stack[++curPosOfStack] = val;
        return 1;
    }
    else
        return -1;
}

int pop()
{
    if (curPosOfStack != -1)
        return stack[curPosOfStack--];
    else
        return -1;
}
void toBin(int val, int sysInt)
{
    int flag = -2;
    int res = 0;

    while (val != 0)
    {
        pushStack(val % sysInt);
        val = val / sysInt;
    }
    do 
    {
        res = pop();
        if (res != -1)
            printf("%d", res);
    } while (res != -1);
}
int main()
{
    initArray();
    insItem(11, 11);
    printQueue();
    insItem(10, 22);
    printQueue();
    insItem(2, 33);
    printQueue();
    insItem(6, 44);
    insItem(2, 55);
    printQueue();
    insItem(4, 66);
    printQueue();
    insItem(5, 77);
    printQueue();
    insItem(9, 23);
    printQueue();
    insItem(11, 21);
    printQueue();
    insItem(9, 23);
    printQueue();
    insItem(9, 23);
    printQueue();
    rmItem();
    printQueue();
    insItem(3, 23);
    printQueue();
    toBin(21, 2);


}
