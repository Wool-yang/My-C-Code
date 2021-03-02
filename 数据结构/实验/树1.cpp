#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

struct node
{
    char info;
    struct node *llink, *rlink;
};

typedef struct node NODE;

NODE *creat()
{
    char x;
    NODE *p;
    scanf("%c", &x);
    printf("%c", x);
    if (x != '.')
    {
        p = (NODE *)malloc(sizeof(NODE));
        p->info = x;
        p->llink = creat();
        p->rlink = creat();
    }
    else
        p = NULL;
    return p;
}

void run(NODE *t)
{
    if (t)
    {
        run(t->llink);
        run(t->rlink);
        printf("%c", t->info);
    }
}

int countLeaf(NODE *t, int &cnt)
{
    if (t)
    {
        if(t->llink == NULL && t->rlink == NULL)
            cnt++;
        countLeaf(t->llink, cnt);
        countLeaf(t->rlink, cnt);
        return cnt;
    }
}

main()
{
    NODE *T;
    printf("PLease input a tree:\n");
    T = creat();
    printf("\n");
    if (!T)
        printf("This is a empty binary tree.");
    else
    {
        printf("The result of post travese is:\n ");
        run(T);
        printf("\n");
    }
    int cnt = 0;
    printf("This is the number of leaf in the tree: %d", countLeaf(T, cnt));
    printf("\n");
}