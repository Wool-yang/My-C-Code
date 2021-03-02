#include<iostream>

using namespace std;

#define VALENGTH 20
#define EXTEND 5
#define ERROR -1
#define OK 1

typedef struct
{
    int *elem;
    int length;
    int size;
}Va;

int compare(int a, int b)
{
    if(a <= b)
        return 1;
    else
        return 0;
}

int init_va(Va &L)
{
    L.elem = (int *)malloc(sizeof(int) * VALENGTH);
    if(!L.elem) return ERROR;
    L.size = VALENGTH;
    return OK;
}

int iniiiit_va(Va &L, int i, int e)
{
    if (i < 1 || i > L.length + 1)
        return ERROR;
    if(L.length >= L.size)
    {
        int* newspace = (int *)realloc(L.elem, sizeof(int) * EXTEND);
        if(!newspace) return ERROR;
        L.elem = newspace;
        L.size += EXTEND;
    }
    int* p = L.elem + i - 1;
    for(int* q = L.elem + L.length - 1;q >= p;q--)
        *(q + 1) = *q;
    *p = e;
    ++L.length;
    return OK;
}

int insert_va(Va &L, int e)
{
    if(L.length >= L.size)
    {
        int* newspace = (int *)realloc(L.elem, sizeof(int) * EXTEND);
        if(!newspace) return ERROR;
        L.elem = newspace;
        L.size += EXTEND;
    }
    int* p;
    for(p = L.elem;p <= L.elem + L.length - 1;p++)
        if(!compare(*p, e))
            break;
    for(int* q = L.elem + L.length - 1;q >= p - 1;--q)
    {
        *(q + 1) = *q;
        cout << q - p + 1 <<endl;
    }
    *(p - 1) = e;
    ++L.length;
    return OK;
}

int main()
{
    Va va;
    init_va(va);
    for(int i = 1;i <= 20;i++)    
        iniiiit_va(va, i, i);
    insert_va(va, 7);
    for(int i = 0;i < 21;i++)
        cout << va.elem[i] << " ";
    return 0;
}