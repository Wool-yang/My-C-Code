#include<iostream>
#include<cstdio>
#include<cstdlib>
 
#define NULL 0
#define ERROR -1
#define OK 1

using namespace std;

typedef struct node
{
    int num;
    struct node *link, *last;
} node, *nodelink;

void readlink(nodelink head, int n, int &length)
{
    nodelink p, q;
    p = head;
    for(int i = 0;i < n;i++)
    {
        q = (nodelink)malloc(sizeof(node));
        q->num = length;
        if(i != 0)
        	q->last = p;
        else
        	q->last = NULL;
		p->link = q;
        p = q;
        if(i != n - 1)
            length++;
    }
    p->link = NULL;
}

void Josephus(nodelink head1, nodelink head2, int length, int m)
{
    nodelink tou = head1->link;
    nodelink q = head2;
    nodelink p = head1->link;
    int num = 1;
    while(length)
    {
        nodelink xx;
        if(num == m)
        {
            q->link = p;
            q = p;
            length--;
            num = 1;
            if(p->link != NULL)
            {
                if(p->last == NULL)
                {
                    tou = p->link;
                    p->link->last = NULL;
				}
				else
				{ 
					p->last->link = p->link;
					p->link->last = p->last;
				}
				p = p->link;
            }
            else
            {
                if(p->last == NULL)
                    break;
                else
                {
                    p->last->link = NULL;
                    p = tou;
                }
            }
        }
        else
        {
            num++;
            if(p->link != NULL)
                p = p->link;
            else
                p = tou;
        }
    }
    q->link = NULL;
}

void writelink(nodelink head)
{
    nodelink q;
    if (head == NULL)
        printf(" This link is empty¡£\n");
    for (q = head->link; q; q = q->link)
        printf("%d ", q->num);
    printf("\n");
}

main()
{
    nodelink head1, head2;
    head1 = (nodelink)malloc(sizeof(node));
    head1->last = NULL;
    head2 = (nodelink)malloc(sizeof(node));
    head2->last = NULL;
    int m, n;
    printf("Input the size of m and n: ");
    scanf("%d%d", &n, &m);
    int length = 1;
    readlink(head1, n, length);
    //writelink(head1);`
    Josephus(head1, head2, length, m);
    printf("The sequence table of n persons obtained by listing sequence:\n");
    writelink(head2);
}
