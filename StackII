#include<cstdio>

#define N 10
#pragma warning (disable: 4996)

typedef int Item;
typedef struct stack {
    Item items[N];
    int  nTop;
}	Stack, *StackPtr;

int main()
{
    int  Push(StackPtr pStack, Item nItem);
    int  Pop(StackPtr pStack, Item& nItem);
    void PrintStack(StackPtr pStack);
    int  Error(char *sMsg);

    /** Create Stack **/
    Stack aStack;

    aStack.nTop = -1;
    while (1) {
        Item value;
        printf("-2:Exit -1:Pop, 0~:Push ? ");
        scanf("%d", &value);
        if (value < -1)
            break;
        else if (value == -1) {
            if (Pop(&aStack, value) == 0)
                Error(const_cast<char *>("empty"));
            else
                printf("%d is deleted\n", value);
        }
        else {
            Push(&aStack, value) == 0 ? Error(const_cast<char *>("full")) : printf("%d is inserted\n", value);
        }
        PrintStack(&aStack);
    }
}

int IsEmptyStack(StackPtr pStack)
{
    return pStack->nTop == -1;// 스택이 비었는지에 따라 T/F를 반환한다.
}

int IsFullStack(StackPtr pStack)
{
    return pStack->nTop == N - 1;// 스택이 가득 찼는지에 따라 T/F를 반환한다.
}

int Push(StackPtr pStack, Item nItem)
{
    if(IsFullStack(pStack))
        return false;// 스택에 nItem을 push하는데 승패에 따라 T/F를 반환한다.
    pStack->items[++pStack->nTop] = nItem;// top을 증가하여 삽입
    return true;
}

int Pop(StackPtr pStack, Item& nItem)
{
    if(IsEmptyStack(pStack))// 스택에서 pop하여 nItem에 저장하는데 승패에 따라 T/F를 반환한다
        return false;
    nItem = pStack->items[pStack->nTop--];// 받아내고 top을 감소
    return true;
}

void PrintStack(StackPtr pStack)
{
    printf("|    |\n");
    for (int i = pStack->nTop; i >= 0; i--)
        printf("|%3d |\n", pStack->items[i]);
    printf("+----+\n\n");
}

int Error(char *sMsg)
{
    printf("***** Stack is %s. *****\n", sMsg);
    return false;
}
