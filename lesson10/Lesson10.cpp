
#include <iostream>
const char WRONGVAL = '@';
typedef struct lstNode
{
    char val;
    struct lstNode* next;
}lstNode;

typedef struct
{
    lstNode* begin;
    int size;
}lstStack;

void startLstStack(lstStack *lst)
{
    lst->begin = NULL;
    lst->size = 0;
}

int pushStack(lstStack* lst, char val)
{
    lstNode* buff = (lstNode*)malloc(sizeof(lstNode));
    if (buff == NULL || val == WRONGVAL)
        return -1;

    buff->val = val;
    buff->next = lst->begin;

    lst->begin = buff;
    lst->size++;
    return 1;
}
char popStack(lstStack *lst)
{
    if (lst->size == 0)
        return WRONGVAL;

    lstNode* buff = lst->begin;
    char res = lst->begin->val;
    lst->begin = lst->begin->next;

    free(buff);

    lst->size--;

    return res;
}
void printLstElement(lstNode *elem)
{
    if (elem == NULL)
    {
        printf("[]");
        return;
    }

    printf("%c", elem->val);
}
void printLst(lstStack* lst)
{
    lstNode* curNode = lst->begin;
    if (curNode != NULL)
        do
        {
            printLstElement(curNode);
            curNode = curNode->next;

        } while (curNode != NULL);
    else
        printLstElement(curNode);
}
int checkVal(char buff)
{
    if (buff == ')') return 1;
    if (buff == ']') return 2;
    if (buff == '}') return 3;
    if (buff == '(') return -1;
    if (buff == '[') return -2;
    if (buff == '{') return -3;
    return 0;

}

bool checkBracketLine(lstStack* lst)
{
    if (lst->size == 0)
        return true;

    lstStack* buff = (lstStack*)malloc(sizeof(lstStack));
    startLstStack(buff);

    lstNode* curNode = lst->begin;

    int someVal;
    do
    {
        someVal = checkVal(curNode->val);
        if (someVal != 0)
        {
            if (someVal > 0)
                pushStack(buff, curNode->val);
            else
            {
                if (buff->size == 0)
                    return false;
                else
                    if (checkVal(buff->begin->val) + someVal == 0)
                        popStack(buff);

            }


        }
        curNode = curNode->next;

    } while (curNode->next != NULL);

    if (buff->size != 0)
        return false;
    else
        true;
}
void copyLstStack(lstStack* lst, lstStack* lstCopy)
{
    lstStack* buffer = (lstStack*)malloc(sizeof(lstStack));
    startLstStack(buffer);
    lstNode* curNode = lst->begin;

    for (int i = 1; i<= lst -> size; i++)
    {
        pushStack(buffer, curNode->val);
        curNode = curNode->next;
    } 
    printLst(buffer);
    startLstStack(lstCopy);

    while (buffer->size != 0)
        pushStack(lstCopy, popStack(buffer));

}
bool checkIsSortedList(lstStack* lst)
{
    if (lst->size == 0)
        return true;

    lstNode* curNode = lst->begin;
    char val;
    for (int i = 2; i <= lst->size; i++)
    {
        val = curNode->val;
        curNode = curNode->next;
        if (val <= curNode->val)
            return false;
    }
    return true;
}
int main()
{
    lstStack *lst = (lstStack*)malloc(sizeof(lstStack));

    startLstStack(lst);
    pushStack(lst, '1');
  //  printLst(lst);
    pushStack(lst, '2');
  //  printLst(lst);
    pushStack(lst, '3');
   // printLst(lst);
    pushStack(lst, '4');
    //printLst(lst);
    if (checkBracketLine(lst))
        printf("+");
    else
        printf("-");

    lstStack* lstCopy = (lstStack*)malloc(sizeof(lstStack));
    copyLstStack(lst, lstCopy);
    printf("\n");
    printLst(lst);
    printf("\n");
    printLst(lstCopy);

    if (checkIsSortedList(lst))
        printf("+");
    else
        printf("-");
}
