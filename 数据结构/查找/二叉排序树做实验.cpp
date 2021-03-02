#include<iostream>
#include<fstream>

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
        BiTree s = p->lc;
        while(s->rc)
        {
            q = s;
            s = s->rc;
        }
        p->data = s->data;
        if(q != p)
            q->rc = s->lc;
        else
            q->lc = s->lc;
        delete s;
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

/* void OnOrder(BiTree T, int l, int r, int cen, int fa)
{
    if(T)
    {
        if(fa == -1)
            cout << "根节点" << " 该点为：" << T->data << " 层数为：" << cen << endl;
        else
        {
            if(l)
                cout << "该点为：" << T->data << " 该节点为 " << fa << " 的左儿子" << " 层数为：" << cen << endl;
            if(r)
                cout << "该点为：" << T->data << " 该节点为 " << fa << " 的右儿子" << " 层数为：" << cen << endl;
        }
        OnOrder(T->lc, 1, 0, cen + 1, T->data); 
        OnOrder(T->rc, 0, 1, cen + 1, T->data);
    }
}
 */
int yu = 0;
ofstream out("result.txt");
void OnOrder(BiTree T, int l, int r, int cen, int fa)
{
    if(T)
    {
        
        OnOrder(T->lc, 1, 0, cen + 1, T->data); 
        if(cen > yu)
            yu = cen;
        if(fa == -1)
            out << "根节点" << " 该点为：" << T->data << " 层数为：" << cen << endl;
        else
        {
            if(l)
                out << "该点为：" << T->data << " 该节点为 " << fa << " 的左儿子" << " 层数为：" << cen << endl;
            if(r)
                out << "该点为：" << T->data << " 该节点为 " << fa << " 的右儿子" << " 层数为：" << cen << endl;
        }
        OnOrder(T->rc, 0, 1, cen + 1, T->data);
    }
}

int main()
{
    BiTree T;
    T = NULL;
    /* int n;
    cout << "请输入要插入的结点数：" << endl;
    cin >> n;
    cout << "依次输入每个结点的data, 空格分开" << endl;
    for(int i = 0;i < n;i++)
    {
        int x;
        cin >> x;
        InsertBST(T, x);
    }
    
    BiTree p = NULL;
    int x;
    cout << "输入查找的data：" << endl;
    cin >> x;
    if(SearchBST(T, x, NULL, p))
        cout << "找见了";
    else
        cout << "没找见";
    cout << endl;
    cout << endl << "这是这棵树：" << endl;  */
    ifstream in("record.txt");
    int x;
    while(in.good())
    {
        in>>x;
        InsertBST(T, x);
    }
    in.close();
    OnOrder(T, 0, 0, 1, -1);
    out.close();
    cout << yu;
    return 0;
}