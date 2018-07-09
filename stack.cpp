#include <cstdio>

#define N 10
#pragma warning (disable: 4996)

typedef int Item;

int main()
{
    int  Push(Item aStack[], int& nTop, Item nItem);
	int  Pop(const Item aStack[], int& nTop, Item& nItem);
	void PrintStack(Item aStack[], int nTop);
	int  Error(char *sMsg);

	/** Create Stack **/
	Item aStack[N];
	int nTop;

	nTop = -1;
	while (true) {
		Item value;
		printf("-2:Exit -1:Pop, *:Push ? ");
		scanf("%d", &value); // NOLINT
        if (value >= -1)
            value == -1 ? Pop(aStack, nTop, value) == 0 ? Error(const_cast<char *>("empty")) : printf("%d is deleted\n",
                                                                                                      value)
                        : Push(aStack, nTop, value) == 0 ? Error(const_cast<char *>("full")) : printf("%d is inserted\n", value);
        else break;
		PrintStack(aStack, nTop);
	}
}

int IsEmptyStack(int nTop)
{
    return nTop == -1;
}

int IsFullStack(int nTop)
{
    return nTop == N - 1;
}

int Push(Item aStack[], int& nTop, Item nItem)
{
    if (IsFullStack(nTop) != 0) return false;
    else {// 스택에 nItem을 push하는데 승패에 따라 T/F를 반환한다.
        aStack[++nTop] = nItem;// top을 증가하여 삽입
        return true;
    }
}

int Pop(const Item aStack[], int& nTop, Item& nItem)
{
    if (IsEmptyStack(nTop) != 0) return false;
    else {// 스택에서 pop하여 nItem에 저장하는데 승패에 따라 T/F를 반환한다.
        nItem = aStack[nTop--];// 받아내고 top을 감소
        return true;
    }
}

void PrintStack(Item aStack[], int nTop)
{
	printf("|    |\n");
	for (int i = nTop; i >= 0; i--)
		printf("|%3d |\n", aStack[i]);
	printf("+----+\n\n");
}

int Error(char *sMsg)
{
	printf("***** Stack is %s. *****\n", sMsg);
	return false;
}
