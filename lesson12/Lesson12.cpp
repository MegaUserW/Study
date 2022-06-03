// Lesson12.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>

typedef struct tree
{
	int key;
	struct tree* lNode;
	struct tree* rNode;
} treeNode;

treeNode* treeIns(treeNode* t, int val, bool flag)
{
	treeNode* newNode;
	newNode = (treeNode*) malloc(sizeof(treeNode));
	newNode->key = val;
	newNode->lNode = NULL;
	newNode->rNode = NULL;
	treeNode* currentTree = t;
	treeNode* parentTree = t;
	if (flag == false)
	{
		t = newNode;
	}
	else
		while (currentTree->key != val)
		{
			parentTree = currentTree;
			if (currentTree -> key > val)
			{
				currentTree = currentTree->lNode;
				if (currentTree == NULL)
				{
					parentTree->lNode = newNode;
					return t;
				}
			}
			else
			{
				currentTree = currentTree->rNode;
				if (currentTree == NULL)
				{
					parentTree->rNode = newNode;
					return t;
				}
			}
		}

	return t;
}
void printTree(treeNode* t)
{
	if (t)
	{
		printf("%d", t->key);
		if (t->lNode || t->rNode)
		{
			printf("(");
			if (t->lNode)
				printTree(t->lNode);
			else
				printf("NULL");
			printf(",");
			if (t->rNode)
				printTree(t->rNode);
			else
				printf("NULL");
			printf(")");
		}
	}
}
const int NUM_OF_LEAFS = 1000;
int rightCount = 0, leftCount = 0;
int roundTree(treeNode* t, int someVal = -1, int val = 0)
{

	int val1, val2;
	if (t)
	{


		if (someVal == -1)
		{
			leftCount = roundTree(t->lNode, 0);
			rightCount = roundTree(t->rNode, 1);
		}
		else
		{
			val1 = roundTree(t->lNode, someVal) + 1;
			val2 = roundTree(t->rNode, someVal) + 1;
			if (val1 > val2)
				return val1;
			else
				return val2;
		}
	}
	return 1;
}
void myDelay(int mS)
{
	clock_t start_time = clock();
	while (clock() < start_time + mS);
}
treeNode* createTree()
{
	srand(time(0));
	treeNode* t = (treeNode*)malloc(sizeof(treeNode));
	int val = rand() % 1000;
	t = treeIns(t, val, false);
	for (int i = 1; i <= NUM_OF_LEAFS; i++)
	{
		myDelay(100);
		val = val = rand() % 20;
		treeIns(t, val, true);
	}
	return t;
}
int checkBalance(treeNode* t)
{
	rightCount = 0;
	leftCount = 0;
	roundTree(t);
	if (abs(rightCount - leftCount) < 2)
		return 1;
	else
		return 0;
}
treeNode* searchSomeVal(treeNode* t, int searchVal)
{
	treeNode* res = (treeNode*)malloc(sizeof(treeNode));
	if (t)
	{
		if (t->key == searchVal)
			return t;

		res = searchSomeVal(t->lNode, searchVal);
		if (res == NULL)
			res = searchSomeVal(t->rNode, searchVal);

	}
	return res;
}
const int TREE_NUM = 50;
int getStatistic()
{
	int good = 0;
	for (int i = 1; i <= TREE_NUM; i++)
	{
		treeNode* tree = createTree();
		//printf("\n");
		//printTree(tree);
		if (checkBalance(tree))
		{
			good++;
			//printf("+");
		}
	}

	return  100 * good / TREE_NUM;
}

int main()
{
	printf("%d%", getStatistic());
}
