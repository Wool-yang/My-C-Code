#include<iostream>

#define LH + 1
#define EH 0
#define RH - 1

using namespace std;

typedef struct BSTNode
{
    int data;
    int bf;
    struct BSTNode *lchild, *rchild;
}BSTNode, *BSTree;

void OnOrder(BSTree T, int l, int r, int cen, int fa)
{
    if(T)
    {
        
        OnOrder(T->lchild, 1, 0, cen + 1, T->data); 
        if(fa == -1)
            cout << "根节点" << " 该点为：" << T->data << " 层数为：" << cen << " bf为" << T->bf << endl;
        else
        {
            if(l)
                cout << "该点为：" << T->data << " 该节点为 " << fa << " 的左儿子" << " 层数为：" << cen << " bf为" << T->bf << endl;
            if(r)
                cout << "该点为：" << T->data << " 该节点为 " << fa << " 的右儿子" << " 层数为：" << cen << " bf为" << T->bf << endl;
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

void R_Rotate(BSTree &p)
{
    cout << p->lchild->data << "要右旋了" << endl;
    BSTree lc = p->lchild;
    p->lchild = lc->rchild;
    lc->rchild = p;
    p = lc;
}

void L_Rotate(BSTree &p)
{
    cout << p->rchild->data << "要左旋了" << endl;
    BSTree rc = p->rchild;
    p->rchild = rc->lchild;
    rc->lchild = p;
    p = rc;
}

void LeftBalance(BSTree &T)
{
    cout << T->data << "要进行左平衡" << endl;
    BSTree lc = T->lchild;
    cout << lc->data << "是他的左子节点" << endl;
    cout << lc->bf << "是lc的bf" << endl;
    switch (lc->bf)
    {
        case LH:
            T->bf = lc->bf = EH;
            R_Rotate(T);
            cout << "单向右旋" << endl;
            break;
        case RH:
        {
            BSTree rd = lc->rchild;
            switch (rd->bf)
            {
                case LH:
                    T->bf = RH;
                    lc->bf = EH;
                    break;
                case RH:
                    T->bf = EH;
                    lc->bf = LH;
                    break;
                case EH:
                    T->bf = EH;
                    lc->bf = EH;
            } 
            rd->bf = EH;
            L_Rotate(T->lchild);
            R_Rotate(T);
            cout << "先左旋后右旋" << endl;
            break;
        }
        case EH:
            cout << "特殊情况" << endl;
            T->bf = LH;
            lc->bf = RH;
            R_Rotate(T);
            break;
    }
}

void RightBalance(BSTree &T)
{
    cout << T->data << "要进行右平衡" << endl;
    BSTree rc = T->rchild;
    cout << rc->data << "是他的右子节点" << endl;
    cout << rc->bf << "是rc的bf" << endl;
    switch (rc->bf)
    {
        case RH:
            T->bf = rc->bf = EH;
            cout << "单向左旋" << endl;
            L_Rotate(T);
            break;
        case LH:
        {
            BSTree rd = rc->lchild;
            switch (rd->bf)
            {
                case LH:
                    T->bf = EH;
                    rc->bf = RH;
                    break;
                case RH:
                    T->bf = LH;
                    rc->bf = EH;
                    break;
                case EH:
                    T->bf = EH;
                    rc->bf = EH;
                    break;
            } 
            rd->bf = EH;
            R_Rotate(T->rchild);
            L_Rotate(T);
            cout << "先右后左" << endl;
            break;
        }
        case EH:
            cout << "特殊情况" << endl;
            T->bf = RH;
            rc->bf = LH;
            L_Rotate(T);
            break;
    }
}

int InsertAVL(BSTree &T, int key, bool &taller)
{
    if(!T)
    {
        T = (BSTree)malloc(sizeof(BSTNode));
        T->data = key;
        T->lchild = T->rchild = NULL;
        T->bf = EH;
        taller = true;
    }
    else
    {
        if(EQ(key, T->data))
        {
            taller = false;
            return 0;
        }
        if(LT(key, T->data))
        {
            if(!InsertAVL(T->lchild, key, taller))
                return 0;
            if(taller)
                switch (T->bf)
                {
                    case LH:
                        LeftBalance(T);
                        taller = false;
                        break;
                    case EH:
                        T->bf = LH;
                        taller = true;
                        break;
                    case RH:
                        T->bf = EH;
                        taller = false;
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
                        T->bf = EH;
                        taller = false;
                        break;
                    case EH:
                        T->bf = RH;
                        taller = true;
                        break;
                    case RH:
                        RightBalance(T);
                        taller = false;
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

void Delete(BSTree &p)
{
    BSTree q;
    if(!p->lchild)
    {
        cout << p->data << "没有左子树" << endl;
        q = p;
        p = p->rchild;
        free(q);
    }
    else if(!p->rchild)
    {
        cout << p->data << "没有右子树" << endl;
        q = p;
        p = p->lchild;
        free(q);
    }
    else
    {
        cout << p->data << "俩子树都有" << endl;
        q = p;
        BSTree t = p;
        BSTree s = p->lchild;
        while(s->rchild)
        {
            q = s;
            s = s->rchild;
        }
        BSTree tmp = s->lchild;
        cout << s->data << "这是替换的结点" << endl;
        int x = s->data;
        bool lower = false;
        DeleteAVL(root, x, lower);
        if(q != t)
            q->rchild = tmp;
        else
            q->lchild = tmp;
        cout << t->data << endl;
        cout << x << endl;
        t->data = x;
    }
}

bool DeleteAVL(BSTree &T, int key, bool &lower)
{
    if(!T) return false;
    else
    {
        if(EQ(key, T->data))
        {
            cout << "删除了" << T->data << endl;
            cout << "这是删除的过程" << key << endl;
            Delete(T);
            OnOrder(root, 0, 0, 1, -1);
            cout << "删除了" << key << endl;
            cout << endl;
            lower = true;
        }
        else if(LT(key, T->data))
        {
            if(!DeleteAVL(T->lchild, key, lower))
                return false;
            if(lower)
            {
                switch (T->bf)
                {
                    case EH:
                        T->bf = RH;
                        lower = false;
                        break;
                    case LH:
                        T->bf = EH;
                        lower = true;
                        break;
                    case RH:
                        cout << "需要右平衡" << T->data << endl;
                        cout << "这是删除的过程" << key << endl;
                        RightBalance(T);
                        OnOrder(root, 0, 0, 1, -1);
                        cout << endl;
                        lower = true;
                        break;
                }
            }
        }
        else
        {
            if(!DeleteAVL(T->rchild, key, lower))
                return false;
            if(lower)
            {
                switch (T->bf)
                {
                    case EH:
                        T->bf = LH;
                        lower = false;
                        break;
                    case RH:
                        T->bf = EH;
                        lower = true;
                        break;
                    case LH:
                        cout << "需要左平衡" << T->data << endl;
                        cout << "这是删除的过程" << key << endl;
                        LeftBalance(T);
                        OnOrder(root, 0, 0, 1, -1);
                        cout << endl;
                        lower = true;
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
    cin >> num;
    for(int i = 0;i < num;i++)
    {
        int key;
        cin >> key;
        bool taller = false;
        InsertAVL(T, key, taller);
    }
    OnOrder(T, 0, 0, 1, -1);
    cin >> num; 
    for(int i = 0;i < num;i++)
    {
        getRoot(T);
        int key;
        cin >> key;
        bool lower = false;
        DeleteAVL(T, key, lower);
    } 
    cout << "最后结果" << endl;
    OnOrder(T, 0, 0, 1, -1);
    return 0;
}