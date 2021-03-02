#include<iostream>

#define LH + 1
#define EH 0
#define RH - 1

using namespace std;

typedef struct BSTNode
{
    int data;
    int bf; // ƽ�⻯����
    struct BSTNode *lchild, *rchild;
}BSTNode, *BSTree;

void OnOrder(BSTree T, int l, int r, int cen, int fa) // �������һ�½��
{
    if(T)
    {
        
        OnOrder(T->lchild, 1, 0, cen + 1, T->data); 
        if(fa == -1)
            cout << "���ڵ�" << " �õ�Ϊ��" << T->data << " ����Ϊ��" << cen << " bfΪ" << T->bf << endl;
        else
        {
            if(l)
                cout << "�õ�Ϊ��" << T->data << " �ýڵ�Ϊ " << fa << " �������" << " ����Ϊ��" << cen << " bfΪ" << T->bf << endl;
            if(r)
                cout << "�õ�Ϊ��" << T->data << " �ýڵ�Ϊ " << fa << " ���Ҷ���" << " ����Ϊ��" << cen << " bfΪ" << T->bf << endl;
        }
        OnOrder(T->rchild, 0, 1, cen + 1, T->data);
    }
}

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

void R_Rotate(BSTree &p) // ������������
{
    BSTree lc = p->lchild;
    p->lchild = lc->rchild;
    lc->rchild = p;
    p = lc;
}

void L_Rotate(BSTree &p) // ������������
{
    BSTree rc = p->rchild;
    p->rchild = rc->lchild;
    rc->lchild = p;
    p = rc;
}

void LeftBalance(BSTree &T) // �������������ʧ�� �������
{
    BSTree lc = T->lchild;
    switch (lc->bf)
    {
        case LH: // ����ӵ��������� ��ζ��������ӵ��������²�����һ�����
            T->bf = lc->bf = EH;
            R_Rotate(T); // ��������
            break;
        case RH: // ����ӵ��������� ��ζ��������ӵ��������²�����һ�����
        {
            BSTree rd = lc->rchild;
            switch (rd->bf)
            {
                case LH:
                    T->bf = RH;
                    lc->bf = EH;
                    break;
                case RH:
                    T->bf = EH; // ���ｨ�黭ͼ����
                    lc->bf = LH;
                    break;
                case EH:
                    T->bf = EH;
                    lc->bf = EH;
            } 
            rd->bf = EH;
            L_Rotate(T->lchild); // ������������
            R_Rotate(T);
            break;
        }
        case EH: // �����ɾ�����ʱ�Ż���ֵ�������� ��������������ȸ�
            T->bf = LH;
            lc->bf = RH;
            R_Rotate(T); // �������������������������߶� ֱ�ӵ��������������
            break;
    }
}

void RightBalance(BSTree &T) // �������������ʧ�� �������
{
    BSTree rc = T->rchild;
    switch (rc->bf)
    {
        case RH: // �Ҷ��ӵ��������� ��ζ�����Ҷ��ӵ��������²�����һ�����
            T->bf = rc->bf = EH;
            L_Rotate(T); // ��������
            break;
        case LH: // �Ҷ��ӵ��������� ��ζ�����Ҷ��ӵ��������²�����һ�����
        {
            BSTree rd = rc->lchild;
            switch (rd->bf)
            {
                case LH:
                    T->bf = EH;
                    rc->bf = RH;
                    break;
                case RH: // ���ﻹ�ǽ��黭ͼ����
                    T->bf = LH;
                    rc->bf = EH;
                    break;
                case EH:
                    T->bf = EH;
                    rc->bf = EH;
                    break;
            } 
            rd->bf = EH;
            R_Rotate(T->rchild); // ������������
            L_Rotate(T);
            break;
        }
        case EH: // �⻹��ɾ�����ʱ�Ż���ֵ�������� �Ҷ������������ȸ�
            T->bf = RH;
            rc->bf = LH;
            L_Rotate(T); // �������������������������߶� ֱ�ӵ��������������
            break;
    }
}

int InsertAVL(BSTree &T, int key, bool &taller)
{
    if(!T) // �ڿ�ָ���ϲ����µĽ��
    {
        T = (BSTree)malloc(sizeof(BSTNode));
        T->data = key;
        T->lchild = T->rchild = NULL;
        T->bf = EH;
        taller = true; // �½�������������
    }
    else
    { // Ѱ�Ҳ���λ�õ�������� ��ǰ���� data ���� ���� С�� key
        if(EQ(key, T->data))
        {
            taller = false; // ����Ҫ����Ľ�� ����ʧ�� �������� taller �� false  
            return 0;
        }
        if(LT(key, T->data))
        {
            if(!InsertAVL(T->lchild, key, taller))
                return 0; // �������������� return 0
            if(taller) // ��������¼���ε͵�������߶���һ��ݹ��еĽ��ƽ���Ե�Ӱ��
                switch (T->bf)
                {
                    case LH:
                        LeftBalance(T); // �����������͸߻�������������  ��Ҫƽ�⻯
                        taller = false; // ƽ�⻯��˲�ݹ�Ľ����������������
                        break;
                    case EH:
                        T->bf = LH; // �������������ȸ� ������������ ����������
                        taller = true; // ���Դ˲�ݹ�Ľ��������������
                        break;
                    case RH:
                        T->bf = EH; // ������������ ������������ �����ҵȸ�
                        taller = false; // ���Դ˲�ݹ�Ľ����������������
                }
        }
        else
        {
            if(!InsertAVL(T->rchild, key, taller))
                return 0;
            if(taller)
            {
                switch (T->bf)
                {
                    case LH:
                        T->bf = EH; // �����������͸� ������������ �����ҵȸ�
                        taller = false; // ���Դ˲�ݹ�Ľ����������������
                        break;
                    case EH:
                        T->bf = RH; // �������������ȸ� ������������ ����������
                        taller = true; // ���Դ˲�ݹ�Ľ��������������
                        break;
                    case RH:
                        RightBalance(T); // �����������͸߻������������� ��Ҫƽ�⻯
                        taller = false; // ƽ�⻯��˲�ݹ�Ľ����������������
                        break;
                }
            }
        }
        return 1;
    }
}

BSTree root;

bool DeleteAVL(BSTree &T, int key, bool &lower);

void getRoot(BSTree T)
{
    root = T;
}

void Delete(BSTree &p) // ɾ������ �����������
{
    BSTree q;
    if(!p->lchild) // ɾ�����û��������
    {
        q = p;
        p = p->rchild; // ֱ���ý���������ĸ�������˽��
        free(q);
    }
    else if(!p->rchild) // ɾ�����û��������
    {
        q = p;
        p = p->lchild; // ֱ���ý���������ĸ�������˽��
        free(q);
    }
    else // ɾ������������������������
    {
        q = p;
        BSTree t = p; // ɾ��ǰ�����ʱʧ���������� pָ�� ��ָ��Ľ�� �˴�����һ��
        BSTree s = p->lchild;
        while(s->rchild)
        {
            q = s;
            s = s->rchild;
        }
        BSTree tmp = s->lchild; // ɾ��ǰ�����s ��Ҫ���� s�������
        int x = s->data; // �Լ����� s��data
        bool lower = false;
        DeleteAVL(root, x, lower);
        if(q != t)
            q->rchild = tmp;
        else
            q->lchild = tmp;
        t->data = x; // ��ǰ������ data ���� ɾ������data
    }
}

bool DeleteAVL(BSTree &T, int key, bool &lower)
{
    if(!T) 
    {
        lower = false; // �Ҳ���ɾ���Ľ�� lower �� false
        return false; // ɾ��ʧ�� ����false
    }
    else
    { // Ѱ��ɾ������������� ��ǰ���� data ���� ���� С�� key
        if(EQ(key, T->data))
        {
            Delete(T); // �ҵ�ɾ���Ľ�� ����ɾ������
            lower = true; // ɾ��������ڵ���Ӧ�����߶ȱ��
        }
        else if(LT(key, T->data))
        {
            if(!DeleteAVL(T->lchild, key, lower))
                return false; // ���������ɾ���������� return false
            if(lower)
            {
                switch (T->bf)
                {
                    case EH:
                        T->bf = RH; // �������������ȸ� ɾ���������Ͻ�� ��������
                        lower = false; // ���Դ˲�ݹ�Ľ����������������
                        break;
                    case LH:
                        T->bf = EH; // ������������ ɾ���������Ͻ�� ���������ȸ�
                        lower = true; // ���Դ˲�ݹ�Ľ��������������
                        break;
                    case RH:
                        RightBalance(T); // ������������ ɾ���������Ͻ�� ��Ҫƽ�⻯
                        lower = true; // ƽ�⻯��˲�ݹ�Ľ��������������
                        break;
                }
            }
        }
        else
        {
            if(!DeleteAVL(T->rchild, key, lower))
                return false; // ���������ɾ���������� return false
            if(lower)
            {
                switch (T->bf)
                {
                    case EH:
                        T->bf = LH; // �������������ȸ� ɾ���������Ͻ�� ��������
                        lower = false; // ���Դ˲�ݹ�Ľ����������������
                        break;
                    case RH:
                        T->bf = EH; // ������������ ɾ���������Ͻ�� ���������ȸ�
                        lower = true; // ���Դ˲�ݹ�Ľ��������������
                        break;
                    case LH:
                        LeftBalance(T); // ������������ ɾ���������Ͻ�� ��Ҫƽ�⻯
                        lower = true; // ƽ�⻯��˲�ݹ�Ľ��������������
                        break;
                }
            }
        }
        return true;
    }
}

int main()
{
    BSTree T;
    T = NULL;
    int num;
    cout << "���������Ľ������" << endl;
    cin >> num;
    cout << "��������ÿ������ data ֵ���ո�ֿ�" << endl;
    for(int i = 0;i < num;i++)
    {
        int key;
        cin >> key;
        bool taller = false;
        InsertAVL(T, key, taller);
    }
    cout << "������ƽ�������Ϊ��" << endl;
    OnOrder(T, 0, 0, 1, -1);
    cout << "������ɾ���Ľ������" << endl;
    cin >> num; 
    cout << "��������ɾ���Ľ���dataֵ���ո�ֿ�" << endl;
    for(int i = 0;i < num;i++)
    {
        getRoot(T);
        int key;
        cin >> key;
        bool lower = false;
        DeleteAVL(T, key, lower);
    } 
    cout << "ɾ�����ƽ�������Ϊ��" << endl;
    OnOrder(T, 0, 0, 1, -1);
    return 0;
}