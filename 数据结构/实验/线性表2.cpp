#include<iostream>
#include<cstdio>

#define NULL 0
#define ERROR -1
#define OK 1

using namespace std;

typedef struct node
{
    int x1;
    int x2;
    struct node *link;
} node, *nodelink;

void DANreadlink(nodelink head, int &length)
{
    nodelink p, q;
    int x1;
    p = head;
    printf("Input coefficients, separated by a space, end with 0:");
    scanf("%d", &x1);
    while (x1 != 0)
    {
        length++;
        q = (nodelink)malloc(sizeof(node));
        q->x1 = x1;
        q->x2 = length;
        p->link = q;
        p = q;
        scanf(" %d", &x1);
    }
    p->link = NULL;
}

void DANwritelink(nodelink head)
{
    nodelink q;
    if (head->link == NULL)
        printf(" This link is empty¡£\n");
    for (q = head->link; q; q = q->link)
    {
        printf("%d*X%d", q->x1, q->x2);
        if(q->link)
            printf(" + ");
    }
    printf("\n");
}

void BuildHC(nodelink head1, nodelink head2, nodelink head3)
{
    nodelink q, p, n, n1;
    n = head3;
    for (q = head1->link, p = head2->link; q && p; q = q->link, p = p->link)
    {
        int x = q->x1 + p->x1;
        if(x != 0)
        {
            n1 = (nodelink)malloc(sizeof(node));
            n1->x1 = x;
            n1->x2 = q->x2;
            n->link = n1;
            n = n1;
        }
    }
    if(q != NULL)
    {
        for (; q; q = q->link)
        {
            n1 = (nodelink)malloc(sizeof(node));
            n1->x1 = q->x1;
            n1->x2 = q->x2;
            n->link = n1;
            n = n1;
        }
    }
    if(p != NULL)
    {
        for (; p; p = p->link)
        {
            n1 = (nodelink)malloc(sizeof(node));
            n1->x1 = p->x1;
            n1->x2 = p->x2;
            n->link = n1;
            n = n1;
        }
    }
    n->link = NULL;
}

main()
{
    nodelink head1, head2, head3;
    head1 = (nodelink)malloc(sizeof(node));
    head2 = (nodelink)malloc(sizeof(node));
    head3 = (nodelink)malloc(sizeof(node));
    head2->link = NULL;
    head1->link = NULL;
    head3->link = NULL;
    int length1 = 0, length2 = 0;
    printf("Now build ha:\n");
    DANreadlink(head1, length1);
    printf("link ha is :");
    DANwritelink(head1);
    printf("Now build hb:\n");
    DANreadlink(head2, length2);
    printf("link hb is :");
    DANwritelink(head2);
    BuildHC(head1, head2, head3);
    printf("link hc is :");
    DANwritelink(head3);
}