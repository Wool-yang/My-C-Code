#include<iostream>

#define LH + 1
#define EH 0
#define RH - 1

using namespace std;

typedef struct BSTNode
{
    int data;
    int bf; // 平衡化因子
    struct BSTNode *lchild, *rchild;
}BSTNode, *BSTree;

void OnOrder(BSTree T, int l, int r, int cen, int fa) // 中序输出一下结果
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

void R_Rotate(BSTree &p) // 单向右旋操作
{
    BSTree lc = p->lchild;
    p->lchild = lc->rchild;
    lc->rchild = p;
    p = lc;
}

void L_Rotate(BSTree &p) // 单向左旋操作
{
    BSTree rc = p->rchild;
    p->rchild = rc->lchild;
    rc->lchild = p;
    p = rc;
}

void LeftBalance(BSTree &T) // 结点所在左子树失衡 两种情况
{
    BSTree lc = T->lchild;
    switch (lc->bf)
    {
        case LH: // 左儿子的左子树高 意味着在左儿子的左子树下插入了一个结点
            T->bf = lc->bf = EH;
            R_Rotate(T); // 单向右旋
            break;
        case RH: // 左儿子的右子树高 意味着在左儿子的右子树下插入了一个结点
        {
            BSTree rd = lc->rchild;
            switch (rd->bf)
            {
                case LH:
                    T->bf = RH;
                    lc->bf = EH;
                    break;
                case RH:
                    T->bf = EH; // 这里建议画图理解吧
                    lc->bf = LH;
                    break;
                case EH:
                    T->bf = EH;
                    lc->bf = EH;
            } 
            rd->bf = EH;
            L_Rotate(T->lchild); // 先左旋后右旋
            R_Rotate(T);
            break;
        }
        case EH: // 这就是删除结点时才会出现的特殊情况 左儿子左右子树等高
            T->bf = LH;
            lc->bf = RH;
            R_Rotate(T); // 子树左子树比右子树高两个高度 直接单向右旋解决问题
            break;
    }
}

void RightBalance(BSTree &T) // 结点所在右子树失衡 两种情况
{
    BSTree rc = T->rchild;
    switch (rc->bf)
    {
        case RH: // 右儿子的右子树高 意味着在右儿子的右子树下插入了一个结点
            T->bf = rc->bf = EH;
            L_Rotate(T); // 单向右旋
            break;
        case LH: // 右儿子的左子树高 意味着在右儿子的左子树下插入了一个结点
        {
            BSTree rd = rc->lchild;
            switch (rd->bf)
            {
                case LH:
                    T->bf = EH;
                    rc->bf = RH;
                    break;
                case RH: // 这里还是建议画图理解吧
                    T->bf = LH;
                    rc->bf = EH;
                    break;
                case EH:
                    T->bf = EH;
                    rc->bf = EH;
                    break;
            } 
            rd->bf = EH;
            R_Rotate(T->rchild); // 先右旋后左旋
            L_Rotate(T);
            break;
        }
        case EH: // 这还是删除结点时才会出现的特殊情况 右儿子左右子树等高
            T->bf = RH;
            rc->bf = LH;
            L_Rotate(T); // 子树右子树比左子树高两个高度 直接单向左旋解决问题
            break;
    }
}

int InsertAVL(BSTree &T, int key, bool &taller)
{
    if(!T) // 在空指针上插入新的结点
    {
        T = (BSTree)malloc(sizeof(BSTNode));
        T->data = key;
        T->lchild = T->rchild = NULL;
        T->bf = EH;
        taller = true; // 新结点所在子树变高
    }
    else
    { // 寻找插入位置的三种情况 当前结点的 data 等于 大于 小于 key
        if(EQ(key, T->data))
        {
            taller = false; // 存在要插入的结点 插入失败 不插入则 taller 置 false  
            return 0;
        }
        if(LT(key, T->data))
        {
            if(!InsertAVL(T->lchild, key, taller))
                return 0; // 如果插入结点存在则 return 0
            if(taller) // 正常情况下检查层次低的子树变高对这一层递归中的结点平衡性的影响
                switch (T->bf)
                {
                    case LH:
                        LeftBalance(T); // 本来左子树就高还往左子树插结点  需要平衡化
                        taller = false; // 平衡化后此层递归的结点所在子树不会变高
                        break;
                    case EH:
                        T->bf = LH; // 本来左右子树等高 往左子树插结点 则左子树高
                        taller = true; // 所以此层递归的结点所在子树会变高
                        break;
                    case RH:
                        T->bf = EH; // 本来右子树高 往左子树插结点 则左右等高
                        taller = false; // 所以此层递归的结点所在子树不会变高
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
                        T->bf = EH; // 本来左子树就高 往右子树插结点 则左右等高
                        taller = false; // 所以此层递归的结点所在子树不会变高
                        break;
                    case EH:
                        T->bf = RH; // 本来左右子树等高 往右子树插结点 则右子树高
                        taller = true; // 所以此层递归的结点所在子树会变高
                        break;
                    case RH:
                        RightBalance(T); // 本来右子树就高还往右子树插结点 需要平衡化
                        taller = false; // 平衡化后此层递归的结点所在子树不会变高
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

void Delete(BSTree &p) // 删除操作 存在三种情况
{
    BSTree q;
    if(!p->lchild) // 删除结点没有左子树
    {
        q = p;
        p = p->rchild; // 直接用结点右子树的根结点代替此结点
        free(q);
    }
    else if(!p->rchild) // 删除结点没有右子树
    {
        q = p;
        p = p->lchild; // 直接用结点左子树的根结点代替此结点
        free(q);
    }
    else // 删除结点既有左子树又有右子树
    {
        q = p;
        BSTree t = p; // 删除前驱结点时失衡调整会更改 p指针 所指向的结点 此处保存一下
        BSTree s = p->lchild;
        while(s->rchild)
        {
            q = s;
            s = s->rchild;
        }
        BSTree tmp = s->lchild; // 删除前驱结点s 需要保存 s的左儿子
        int x = s->data; // 以及保存 s的data
        bool lower = false;
        DeleteAVL(root, x, lower);
        if(q != t)
            q->rchild = tmp;
        else
            q->lchild = tmp;
        t->data = x; // 用前驱结点的 data 代替 删除结点的data
    }
}

bool DeleteAVL(BSTree &T, int key, bool &lower)
{
    if(!T) 
    {
        lower = false; // 找不到删除的结点 lower 置 false
        return false; // 删除失败 返回false
    }
    else
    { // 寻找删除结点的三种情况 当前结点的 data 等于 大于 小于 key
        if(EQ(key, T->data))
        {
            Delete(T); // 找到删除的结点 进行删除操作
            lower = true; // 删除结点所在的相应子树高度变低
        }
        else if(LT(key, T->data))
        {
            if(!DeleteAVL(T->lchild, key, lower))
                return false; // 如果不存在删除结点存在则 return false
            if(lower)
            {
                switch (T->bf)
                {
                    case EH:
                        T->bf = RH; // 本来左右子树等高 删除左子树上结点 右子树高
                        lower = false; // 所以此层递归的结点所在子树不会变低
                        break;
                    case LH:
                        T->bf = EH; // 本来左子树高 删除左子树上结点 左右子树等高
                        lower = true; // 所以此层递归的结点所在子树会变低
                        break;
                    case RH:
                        RightBalance(T); // 本来右子树高 删除左子树上结点 需要平衡化
                        lower = true; // 平衡化后此层递归的结点所在子树会变低
                        break;
                }
            }
        }
        else
        {
            if(!DeleteAVL(T->rchild, key, lower))
                return false; // 如果不存在删除结点存在则 return false
            if(lower)
            {
                switch (T->bf)
                {
                    case EH:
                        T->bf = LH; // 本来左右子树等高 删除右子树上结点 左子树高
                        lower = false; // 所以此层递归的结点所在子树不会变低
                        break;
                    case RH:
                        T->bf = EH; // 本来右子树高 删除右子树上结点 左右子树等高
                        lower = true; // 所以此层递归的结点所在子树会变低
                        break;
                    case LH:
                        LeftBalance(T); // 本来左子树高 删除右子树上结点 需要平衡化
                        lower = true; // 平衡化后此层递归的结点所在子树会变低
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
    cout << "请输入树的结点数：" << endl;
    cin >> num;
    cout << "依次输入每个结点的 data 值，空格分开" << endl;
    for(int i = 0;i < num;i++)
    {
        int key;
        cin >> key;
        bool taller = false;
        InsertAVL(T, key, taller);
    }
    cout << "构建的平衡二叉树为：" << endl;
    OnOrder(T, 0, 0, 1, -1);
    cout << "请输入删除的结点数：" << endl;
    cin >> num; 
    cout << "依次输入删除的结点的data值，空格分开" << endl;
    for(int i = 0;i < num;i++)
    {
        getRoot(T);
        int key;
        cin >> key;
        bool lower = false;
        DeleteAVL(T, key, lower);
    } 
    cout << "删除后的平衡二叉树为：" << endl;
    OnOrder(T, 0, 0, 1, -1);
    return 0;
}