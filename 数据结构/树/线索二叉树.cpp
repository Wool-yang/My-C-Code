#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

#define OK 1
#define OVERFLOW -2
#define ERROR -1

using namespace std;

typedef enum{Link, Thread} PointerTag;

typedef struct BiThrNode
{
    char data;
    struct BiThrNode *lchild, *rchild;   
    PointerTag ltag; 
    PointerTag rtag;
}BiThrNode, *BiThrTree;

BiThrTree pre;

bool visit(char x)
{
    cout << x << " ";
    return true;
}

int CreateBiThrTree(BiThrTree &T)
{
    char ch;
    cin >> ch; 
    if(ch == '#') T = NULL;
    else
    {
        if(!(T = (BiThrNode *)malloc(sizeof(BiThrNode)))) exit(OVERFLOW);
        T->data = ch;
        T->ltag = Link;
        T->rtag = Link;
        CreateBiThrTree(T->lchild);
        CreateBiThrTree(T->rchild);
    }
    return OK;
}

void InThreading(BiThrTree p)
{
    if(p)
    {
        InThreading(p->lchild);
        if(!p->lchild)
        {
            p->ltag = Thread;
            p->lchild = pre;
        }
        if(!pre->rchild)
        {
            pre->rtag = Thread;
            pre->rchild = p;
        }
        pre = p;
        InThreading(p->rchild);
    }
}

// 中序遍历顺序相同 读取数据操作变为线索化过程

int InOrderThreading(BiThrTree &Thrt,BiThrTree T) // 此处新创建一个线索树
{
    if(!(Thrt = (BiThrNode *)malloc(sizeof(BiThrNode)))) exit(OVERFLOW);
    Thrt->ltag = Link;
    Thrt->rtag = Thread;
    Thrt->rchild = Thrt;
    if(!T) Thrt->lchild = Thrt;
    else
    {
        Thrt->lchild = T;
        pre = Thrt;
        InThreading(T);
        pre->rchild = Thrt;
        pre->rtag = Thread;
        Thrt->rchild = pre;
    }
    return OK;
}

int InOrderTraverse_Thr(BiThrTree T,bool (* visit)(char x))
{
    BiThrTree p = T->lchild;
    while(p != T)
    {
        while(p->ltag == Link) 
        {
			p = p->lchild;
		}
		if(!visit(p->data)) return ERROR;
        while(p->rtag == Thread && p->rchild != T)
        {
            p = p->rchild;
            visit(p->data);
        }
        p = p->rchild;
    }
    return OK;
}

int reInOrderTraverse_Thr(BiThrTree T,bool (* visit)(char x))
{
    BiThrTree p = T->rchild;
    while(p != T)
    {
        while(p->rtag == Link) p = p->rchild;
        if(!visit(p->data)) return ERROR;
        while(p->ltag == Thread && p->lchild != T)
        {
            p = p->lchild;
            visit(p->data);
        }
        p = p->lchild;
    }
    return OK;
}

void ooInThreading(BiThrTree p)
{
    if(p == NULL)
        return;
    ooInThreading(p->lchild);
    visit(p->data);
    ooInThreading(p->rchild);
}

int main()
{
    BiThrTree Tre,Thre;
    CreateBiThrTree(Tre);
    ooInThreading(Tre);
    cout << endl;
    InOrderThreading(Thre, Tre);
    InOrderTraverse_Thr(Thre, visit);
    cout << endl;
    reInOrderTraverse_Thr(Thre, visit);
    return 0;
}
