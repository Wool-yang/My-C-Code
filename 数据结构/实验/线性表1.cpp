#include<iostream>
#include<cstdio>

#define NULL 0
#define ERROR -1
#define OK 1

using namespace std;

typedef struct node
{
    char a;
    struct node *link;
} node, *nodelink;

void readlink(nodelink head)
{
    nodelink p, q;
    char c;
    p = head;
    printf("Input a linktable(a string):");
    scanf("%c", &c);
    if (c == '\n')
        printf("This string is empty¡£");
    while (c != '\n')
    {
        q = (nodelink)malloc(sizeof(node));
        q->a = c;
        p->link = q;
        p = q;
        scanf("%c", &c);
    }
    p->link = NULL;
}

void writelink(nodelink head)
{
    nodelink q;
    if (head->link == NULL)
        printf(" This link is empty¡£\n");
    for (q = head->link; q; q = q->link)
        printf("%c", q->a);
    printf("\n");
}


int insertSQ(nodelink head, char x)
{
    nodelink p, q;
    q = (nodelink)malloc(sizeof(node));
    q->a = x;
    p = head;
    while(p != NULL)
    {      
        if( (p->link == NULL && p->a < x) || p->link->a > x)
        {
            q->link = p->link;
            p->link = q;
            break;
        }
        p = p->link;
    }
    if(p == NULL)
        return ERROR;
    else
        return OK;
}

main()
{
    nodelink head;
    head = (nodelink)malloc(sizeof(node));
    head->link = NULL;
    readlink(head);
    if (head->link != NULL)
    {
        printf("Build link is :");
        writelink(head);
    }
    if(head->link != NULL)
    {
        char x;
        printf("input a char to the link:");
        x = getchar();getchar();
        insertSQ(head, x);
        printf("the new link is:\n");
        writelink(head);
    }
}