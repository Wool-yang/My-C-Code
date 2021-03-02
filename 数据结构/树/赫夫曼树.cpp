#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <utility>

#define swap(a, b) {int c = a; a = b; b = c;}

using namespace std;

typedef struct
{
    unsigned int weight;
    unsigned int parent, lchild, rchild;
    char data;
} HTNode, *HuffmanTree;

typedef char **HuffmanCode;

bool *visit;                    // 储存结点是否被选择过 

map<char, unsigned int> x;      // 读取模式2 下字符与权值储存在 map 容器中

struct w
{
    unsigned int w;             // 在 Select 函数中排序临时使用的结构体容器
    int pos;
};

bool cmp(w a, w b)
{
    if (a.w < b.w)
        return true;
    else
        return false;
}

void Select(HuffmanTree HT, int i, int &s1, int &s2)
{
    w we[i];                    // 使用临时的结构体 排序不改变原结构顺序
    for (int j = 1; j <= i; j++)
    {
        we[j].w = HT[j].weight;
        we[j].pos = j;
    }
    sort(we + 1, we + i + 1, cmp);  // 未使用 0 地址
    for (int j = 1; j <= i; j++)
    {
        if (!visit[we[j].pos])
        {
            if (s1 == 0)
                s1 = we[j].pos;
            else if (s2 == 0)
            {
                s2 = we[j].pos;
                break;
            }
        }
    }
    if (s1 > s2)
        swap(s1, s2);                // 确保 s1 <= s2
    visit[s1] = true;
    visit[s2] = true;
}

void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, unsigned int *w, int n)
{
    if (n < 1)
        return;
    int m = 2 * n - 1;
    HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode)); // 2n - 1 个空间，不使用 0 地址所以多开一个位置
    HuffmanTree p = HT + 1;
    int i;
    cout << "请输入各字符：(不需要空格分开，回车结束)" << endl;
    for (i = 1; i <= n; ++i, ++p, ++w)
    {
        char x;
        x = getchar();
        *p = {*w, 0, 0, 0, x};
    }
    getchar();
    for (; i <= m; ++i)
    {
        int s1 = 0;
        int s2 = 0;
        Select(HT, i - 1, s1, s2);
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }

    HT[m].parent = 0;       //编码时访问至根节点会查询根节点的双亲节点 所以初始化成0
    // 查了好久才发现的问题...
    HC = (HuffmanCode)malloc((n + 1) * sizeof(char *));
    char *cd = (char *)malloc(n * sizeof(char));        // cd 是临时储存编码过程的空间
    cd[n - 1] = '\0';
    for (i = 1; i <= n; ++i)
    {
        int start = n - 1;
        int f, c;
        for (c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent)
        {
            if (HT[f].lchild == c)
                cd[--start] = '0';
            else
                cd[--start] = '1';
        }
        HC[i] = (char *)malloc((n - start) * sizeof(char));
        strcpy(HC[i], &cd[start]);          // \0前的所有内容复制至 HC[i] 包括 \0
    }
    free(cd);
}

void HuffmanCoding3(HuffmanTree &HT, HuffmanCode &HC, int n)
{
    int i;
    int m = 2 * n - 1;
    HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));
    HuffmanTree p = HT + 1;
    map<char, unsigned int>::iterator it;       // 迭代器遍历 map
    cout << "字符" << " " << "权重" << endl;
    for (it = x.begin(); it != x.end(); it++)
    {
        *p = {it->second, 0, 0, 0, it->first};
        p++;
        cout << it->first << "    " << it->second << endl;
    }

    for (i = n + 1; i <= m; ++i)
    {
        int s1 = 0;
        int s2 = 0;
        Select(HT, i - 1, s1, s2);
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }

    HT[m].parent = 0; //编码时访问至根节点会查询根节点的双亲节点 所以初始化成0

    HC = (HuffmanCode)malloc((n + 1) * sizeof(char *));
    char *cd = (char *)malloc(n * sizeof(char));
    cd[n - 1] = '\0';
    for (i = 1; i <= n; ++i)
    {
        int start = n - 1;
        int f, c;
        for (c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent)
        {
            if (HT[f].lchild == c)
                cd[--start] = '0';
            else
                cd[--start] = '1';
        }
        HC[i] = (char *)malloc((n - start) * sizeof(char));
        strcpy(HC[i], &cd[start]);
    }
    free(cd);
}

void prt(int x, HuffmanCode HC)
{
    printf("%s\n", HC[x]);
}

void prtHuf(HuffmanTree HT, HuffmanCode HC, int n)
{
    char *read;
    read = (char *)malloc(1000 * sizeof(char));     // 不够你就开大点
    char a;
    a = getchar();
    //cin >> a;
    int cnt = 0;
    while (a != '#')
    {
        for (int i = 1; i <= n; i++)
        {
            if (a == HT[i].data)
            {
                strcpy(read + cnt, HC[i]);      //暴力写法，不要在意
                cnt += strlen(HC[i]);
            }
        }
        a = getchar();
    }
    getchar();
    cout << "Huffman编码：" << endl;
    cout << read << endl;
}

void prtData(HuffmanTree HT, int n)
{
    char a;
    int pos = 2 * n - 1;            // 由根节点开始译码
    char *ans = (char *)malloc(1000 * sizeof(char));        // 不够你就开大点
    int cnt = 0;
    //cin >> a;
    a = getchar();
    while (a != '#')
    {
        if (a == '0')
            pos = HT[pos].lchild;
        if (a == '1')
            pos = HT[pos].rchild;
        if (HT[pos].lchild == 0 || HT[pos].rchild == 0)
        {
            ans[cnt++] = HT[pos].data;
            pos = 2 * n - 1;                // 到叶子结点后返回根节点
        }
        //cin >> a;
        a = getchar();
    }
    getchar();
    ans[++cnt] = '\0';
    cout << "原字段：" << endl;
    cout << ans;
}

void HuffmanCoding2(HuffmanTree &HT, HuffmanCode &HC, unsigned int* w, int n)
{

    char *cd = (char *)malloc(n * sizeof(char));
    HC = (HuffmanCode)malloc((n + 1) * sizeof(char *));
    int p = 2 * n - 1;
    int cdlen = 0;              // 编码过程中维护的 cd 长度
    HT[p].parent = 0;
    for (int i = 1; i <= p; i++)
        HT[i].weight = 0;
    while (p)                   // 最后会指向 2n - 1 结点的父亲 设置的是 0
    {
        if (HT[p].weight == 0)
        {
            HT[p].weight = 1;   // 标记该结点左孩子结点已被遍历过
            if (HT[p].lchild != 0)
            {
                p = HT[p].lchild;
                cd[cdlen++] = '0';
            }
            else if (HT[p].rchild == 0)
            {
                HC[p] = (char *)malloc((cdlen + 1) * sizeof(char));
                cd[cdlen] = '\0';
                strcpy(HC[p], cd);      // 左右孩子结点都为空为叶子结点 完成编码一次
            }
        }
        else if (HT[p].weight == 1)
        {
            HT[p].weight = 2;           // 标记该结点右孩子结点已被遍历过
            if (HT[p].rchild != 0)
            {
                p = HT[p].rchild;
                cd[cdlen++] = '1';
            }
        }
        else
        {
            HT[p].weight = 0;
            p = HT[p].parent;           // 退回双亲结点
            --cdlen;                    // 长度减一
        }
    }
}

int main()
{
    cout << "1.手动输入字符与权重" << endl << "2.字段自动识别" << endl << "请输入相应序号：" << endl;
    int mode;
    cin >> mode;
    getchar();
    if (mode == 1)
    {
        int n;
        cout << "请输入字符个数：" << endl;
        cin >> n;
        unsigned int *w = (unsigned int *)malloc(n * sizeof(unsigned int));
        visit = (bool *)malloc((2 * n + 1) * sizeof(bool));
        for (int i = 0; i <= 2 * n + 1; i++)
            visit[i] = false;
        cout << "请输入各字符权重：(空格分开回车结束)" << endl;
        for (int i = 0; i < n; i++)
            cin >> w[i];
        getchar();
        HuffmanCode Code, Code1;
        HuffmanTree Tree;
        HuffmanCoding(Tree, Code, w, n);
        //HuffmanCoding2(Tree, Code1, n);
        cout << "请输入原字段,以#结束： " << endl;
        prtHuf(Tree, Code, n);
        cout << "请输入Huffman编码,以#结束：" << endl;
        prtData(Tree, n);
    }
    else if (mode == 2)
    {
        cout << "请输入一段话：(以#结束)" << endl;
        char a;
        //scanf("%c", &a);
        a = getchar();
        while (a != '#')
        {
            if (!x.count(a))
            {
                x[a] = 1;
            }
            else
            {
                x[a]++;
            }
            a = getchar();
            //scanf("%c", &a);
        }
        int n = x.size();
        unsigned int *w = (unsigned int *)malloc(n * sizeof(unsigned int));
        visit = (bool *)malloc((2 * n + 1) * sizeof(bool));
        for (int i = 0; i <= 2 * n + 1; i++)
            visit[i] = false;
        HuffmanCode Code;
        HuffmanTree Tree;
        HuffmanCoding3(Tree, Code, n);
        cout << "请输入原字段,以#结束： " << endl;
        prtHuf(Tree, Code, n);
        cout << "请输入Huffman编码,以#结束：" << endl;
        prtData(Tree, n);
    }
    return 0;
}
