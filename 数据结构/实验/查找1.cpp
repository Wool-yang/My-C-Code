#include<iostream>

using namespace std;

typedef struct BiNode
{
    int data;
    struct BiNode* lc;
    struct BiNode* rc; 
}BiNode, *BiTree;

bool EQ(int key1, int key2)
{
    if(key1 == key2)
        return true;
    else 
        return false;
}

bool LT(int key1, int key2)
{
    if(key1 < key2)
        return true;
    else
        return false;
}

bool SearchBST(BiTree T, int key, BiTree f, BiTree &p)
{
    if(!T)
    {
        p = f;
        return false; 
    }
    else if(EQ(key, T->data))
    {
        p = T;
        return true;
    }
    else if(LT(key, T->data))
    {
        return SearchBST(T->lc, key, T, p);
    }
    else
        return SearchBST(T->rc, key, T, p);
}

bool InsertBST(BiTree &T, int key)
{
    BiTree p;
    if(!SearchBST(T, key, NULL, p))
    {
        BiTree s = (BiTree)malloc(sizeof(BiNode));
        s->data = key;
        s->lc = NULL;
        s->rc = NULL;
        if(!p) T = s;
        else if(LT(key, p->data))
            p->lc = s;
        else
            p->rc = s;
        return true;
    }
    else
        return false;
}

int main()
{
    BiTree T;
    T = NULL;
    int n;
    cout << "������Ҫ����Ľ������" << endl;
    cin >> n;
    cout << "��������ÿ������data, �ո�ֿ�" << endl;
    for(int i = 0;i < n;i++)
    {
        int x;
        cin >> x;
        InsertBST(T, x);
    }
    BiTree p = NULL;
    int x;
    cout << "������ҵ�key��" << endl;
    cin >> x;
    if(SearchBST(T, x, NULL, p))
        cout << "�Ҽ���";
    else
        cout << "û�Ҽ�";
    return 0;
}