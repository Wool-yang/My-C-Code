#include <iostream>
#include <cstring>

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define OK 1
#define OVERFLOW -2
#define ERROR -1

using namespace std;

typedef struct
{
    int *elem;
    int length;
    int listsize;
} SqList;

int compare(int a, int b)
{
    if(a == b)
        return 1;
    else
        return 0;
}

int InitList_Sq(SqList &L)
{
    L.elem = (int *)malloc(LIST_INIT_SIZE * sizeof(int));
    if (!L.elem)
        exit(OVERFLOW);
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}

int List_Insert_Sq(SqList &L, int i, int e)
{
    if (i < 1 || i > L.length + 1)
        return ERROR;
    if (L.length >= L.listsize)
    {
        int* newbase = (int *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof (int));
        if(!newbase) exit(OVERFLOW);
        L.elem = newbase;
        L.listsize += LISTINCREMENT;
    }
    int* q = &(L.elem[i - 1]);
    for(int* p = &(L.elem[L.length - 1]);p >= q;--p)
        *(p + 1) = *p;
    *q = e;
    ++L.length;
    return OK;
}

int ListDelete_Sq(SqList &L, int i, int &e)
{
    if((i < 1) || (i > L.length)) return ERROR;
    int* p = &(L.elem[i - 1]);
    e = *p;
    int* q = L.elem + L.length - 1;
    for(++p;p <= q;++p) *(p - 1) = *p;
    --L.length;
    return OK;
}

int LocateElem_Sq(SqList &L, int e,int(* compare)(int, int))
{
    int i = 1;
    int* p = L.elem;
    while(i <= L.length && !(* compare)(*p++, e)) ++i;
    if(i <= L.length) return i;
    return OK;
}

int main()
{
    SqList sb;
    InitList_Sq(sb);
    for(int i = 1;i <= 20;i++)
        List_Insert_Sq(sb, i, 7);
    cout << sb.length << endl;
    List_Insert_Sq(sb, 15, 9);
    for(int i = 0;i < 21;i++)
        cout << sb.elem[i] << " " << endl;
    cout << sb.elem << " " << &(sb.elem[0]);
    return 0;
}