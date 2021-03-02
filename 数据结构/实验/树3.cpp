#include <cstdio>
#include <cstdlib>
#include <cstring>
#include<iostream>
using namespace std;

struct node
{
    char info;
    struct node *llink, *rlink;
    struct node *parent;
    int tag;
};

typedef struct node NODE;

NODE *creat(NODE * parent)
{
    char x;
    NODE *p;
    scanf("%c", &x);
    printf("%c", x);
    if (x != '.')
    {
        p = (NODE *)malloc(sizeof(NODE));
        p->parent = parent;
        p->tag = 0;
        p->info = x;
        p->llink = creat(p);
        p->rlink = creat(p);
    }
    else
        p = NULL;
    return p;
}

void Preorder(NODE *T)
{
    NODE* p;
    p = T;
    while(p != NULL)
    {
        if(p->tag == 0)
        {
            printf("%c ", p->info);
            p->tag = 1;
            if(p->llink != NULL)
            {
                p = p->llink;
            }
        }
        else if(p->tag == 1)
        {
            p->tag = 2;
            if(p->rlink != NULL)
            {
                p = p->rlink;
            }
        }
        else if(p->tag == 2)
        {
            p->tag = 0;
            p = p->parent;
        }
    }
}

void LocateK(NODE *T, int &cnt, int k)
{
    NODE* p;
    p = T;
    while(p != NULL)
    {
        if(p->tag == 0)
        {
            cnt++;
            if(cnt == k)
                printf("%c", p->info);
            p->tag = 1;
            if(p->llink != NULL)
            {
                p = p->llink;
            }
        }
        else if(p->tag == 1)
        {
            p->tag = 2;
            if(p->rlink != NULL)
            {
                p = p->rlink;
            }
        }
        else if(p->tag == 2)
        {
            p->tag = 0;
            p = p->parent;
        }
    }
}

int countLeaf(NODE* T, int &cnt)
{
    NODE* p;
    p = T;
    while(p != NULL)
    {
        if(p->tag == 0)
        {

            if(p->llink == NULL && p->rlink == NULL)
                cnt++;
            p->tag = 1;
            if(p->llink != NULL)
            {
                p = p->llink;
            }
        }
        else if(p->tag == 1)
        {
            p->tag = 2;
            if(p->rlink != NULL)
            {
                p = p->rlink;
            }
        }
        else if(p->tag == 2)
        {
            p->tag = 0;
            p = p->parent;
        }
    }
    return cnt;
}

main()
{
    NODE *T;
    printf("PLease input a tree:\n");
    T = creat(NULL);
    printf("\n");
    if (!T)
        printf("This is a empty binary tree.");
    Preorder(T);
    printf("\n");
    int cnt1 = 0, k;
    printf("PLease input k:\n");
    scanf("%d", &k);
    printf("Point k in the tree: ");
    LocateK(T, cnt1, k);
    if(cnt1 < k)
        printf("does not exist!");
    printf("\n");
    int cnt2 = 0;
    printf("This is the number of leaf in the tree: %d", countLeaf(T, cnt2));
}