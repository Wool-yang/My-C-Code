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

bool Delete(BiTree &p)
{
    BiTree q;
    if(!p->rc)
    {
        q = p;
        p = p->lc;
        free(q);
    }
    else if(!p->lc)
    {
        q = p;
        p = p->rc;
        free(q);
    }
    else
    {
        q = p;
        BiTree s = p->lc; // ������ɾ�����������
        while(s->rc) // ������������������
        {
            q = s; // q��¼ǰ������ǰһ�����
            s = s->rc; // s��¼ǰ�����
        }
        p->data = s->data; // ��ǰ������ data ���� ɾ������ data
        if(q != p) // q != p ���������ɾ�������������������
            q->rc = s->lc; // ��ǰ�������������ӵ�ǰһ��������������
        else
            q->lc = s->lc; // ɾ������������������� ����Ӿ���ǰ����� �����������ӵ���ɾ��������������
        free(s);
    }
    return true;
}

bool DeleteBST(BiTree &T, int key)
{
    if(!T) return false;
    else
    {
        if(EQ(key, T->data)) return Delete(T);
        else if(LT(key, T->data)) return DeleteBST(T->lc, key);
        else
            return DeleteBST(T->rc, key);
    }
}

void OnOrder(BiTree T, int l, int r, int cen, int fa)
{
    if(T)
    {
        OnOrder(T->lc, 1, 0, cen + 1, T->data); 
        if(fa == -1)
            cout << "���ڵ�" << " �õ�Ϊ��" << T->data << " ����Ϊ��" << cen << endl;
        else
        {
            if(l)
                cout << "�õ�Ϊ��" << T->data << " �ýڵ�Ϊ " << fa << " �������" << " ����Ϊ��" << cen << endl;
            if(r)
                cout << "�õ�Ϊ��" << T->data << " �ýڵ�Ϊ " << fa << " ���Ҷ���" << " ����Ϊ��" << cen << endl;
        }
        OnOrder(T->rc, 0, 1, cen + 1, T->data);
    }
}

BiNode a[100];
int cnt = 0;

void OOOOnOrder(BiTree T)
{
    if(T)
    {
        a[cnt++].data = T->data; 
        OOOOnOrder(T->lc); 
        OOOOnOrder(T->rc);
    }
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
    cout << "������ҵ�data��" << endl;
    cin >> x;
    if(SearchBST(T, x, NULL, p))
        cout << "�Ҽ���";
    else
        cout << "û�Ҽ�";
    cout << endl;
    cout << "����ɾ���ĵ㣺" << endl;
    cin >> x;
    if(DeleteBST(T, x))
        cout << "ɾ����" << x;
    else
        cout << "û��" << x << "��ôɾ������";
    cout << endl;
    cout << endl << "�����������" << endl; 
    OnOrder(T, 0, 0, 1, -1);
    OOOOnOrder(T);
    for(int i = 0;i < 5;i++)
        cout << a[i].data << endl;
    return 0;
}