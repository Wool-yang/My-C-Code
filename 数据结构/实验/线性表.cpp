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

int insert(nodelink head, char k1, char k2)
{
    nodelink p, q;
    p = head->link;
    while (p->a != k1 && p)
        p = p->link;
    if (p)
    {
        q = (nodelink)malloc(sizeof(node));
        q->a = k2;
        q->link = p->link;
        p->link = q;
        return 1;
    }
    else
    {
        printf("There is no %c\n", k1);
        return 0;
    }
}

int mydelete (nodelink head, char k)
{
    nodelink p, q;
    q = head;
    p = head->link;
    while (((p->a) != k) && p)
    {
        q = q->link;
        p = p->link;
    }
    if (p)
    {
        q->link = p->link;
        return 1;
    }
    else
    {
        printf("There is no %c\n", k);
        return 0;
    }
}

void opside(nodelink head)
{
    nodelink p, q;
    p = head->link;
    while (p->link)
    {
        q = p->link;
        p->link = q->link;
        q->link = head->link;
        head->link = q;
    }
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
    char k1, k2, k3;
    nodelink head;
    head = (nodelink)malloc(sizeof(node));
    head->link = NULL;
    readlink(head);
    if (head->link != NULL)
    {
        printf("Build link is :");
        writelink(head);
    }
    if (head->link != NULL)
    {
        printf("Please input a char you want to insert after:");
        k1 = getchar();getchar();
        printf("%c\n", k1);
        printf("Please input a char you want to insert:");
        k2 = getchar();getchar();
        printf("%c\n", k2);
        if (insert(head, k1, k2))
        {
            printf("After %c insert %c,link is:", k1, k2);
            writelink(head);
        }
        printf("Please input a char you want to delete:");
        k3 = getchar();getchar();
        printf("%c\n", k3);
        if (mydelete (head, k3))
        {
            printf("after delete %c,link is:", k3);
            writelink(head);
        }
        if(head->link != NULL)
        {
            char x;
            printf("input a char to the link:");
            x = getchar();getchar();
            insertSQ(head, x);
            writelink(head);
        }
        if (head->link != NULL)
        {
            printf("Opsite result is :");
            opside(head);
            writelink(head);
            free(head);
        }
    }
}