#include<iostream>
#include<cstdio>
#include<cstdlib>

#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 20
#define OK 1
#define OVERFLOW -2
#define ERROR -1

using namespace std;

typedef struct ArcNode
{
    int adjvex;                    // 该弧指向的顶点的位置
    struct ArcNode *nextarc;       // 指向下一条弧的指针
    //InfoType *info;                 该弧相关信息的指针
    int cost;
}ArcNode;

typedef struct VNode
{
    int data;                      // 顶点信息
    ArcNode *firstarc;             // 指向第一条依附该顶点的弧的指针
}VNode, AdjList[MAX_VERTEX_NUM];

typedef struct
{
    AdjList vertices;              
    int vexnum, arcnum;            // 图的当前 顶点数 和 弧数
    int kind;                      // 图的种类标志
}ALGraph;

int fa[MAX_VERTEX_NUM];

int find(int x)
{
    if(fa[x] != x)
        return fa[x] = find(fa[x]);
    else
        return x;
}

int Locate(ALGraph G, int x)
{
    for(int i = 0;i < G.vexnum;i++)
    {
        if(G.vertices[i].data == x)
            return i;
    }
}

void CreateGraph(ALGraph &G)
{
    cout << "输入图的点数 与 弧数：" << endl; 
    cin >> G.vexnum >> G.arcnum;
    for(int i = 0;i < G.vexnum;i++)
    {
        cout << "输入第 " << i << " 号节点的data" << endl;
        cin >> G.vertices[i].data;
    }

    for(int i = 0;i < G.vexnum;i++)
    {
        G.vertices[i].firstarc = (ArcNode *)malloc(sizeof(ArcNode));
        ArcNode* temp = G.vertices[i].firstarc;
        char x;
        cout << "输入第 " << i << " 号节点的邻接点，输入#结束" << endl;
        cin >> x;
        if(x != '#')
        {
            temp->adjvex = Locate(G, x - 48);
            cout << "输入到该邻接点的距离：";
            cin >> temp->cost;
        }
        while(x != '#')
        {
            temp->nextarc = (ArcNode *)malloc(sizeof(ArcNode));
            temp = temp->nextarc;
            cout << "输入第 " << i << " 号节点的邻接点，输入#结束" << endl;
            cin >> x;
            if(x != '#')
            {
                temp->adjvex = Locate(G, x - 48);
                cout << "输入到该邻接点的距离：";
                cin >> temp->cost;
            }
        }
        temp->nextarc = NULL;
    }
}

int uni(ALGraph G)
{
    for(int i = 0;i < G.vexnum;i++)
    {
        fa[i] = i;
    }

    for(int i = 0;i < G.vexnum;i++)
    {
        int y = find(i);
        for(ArcNode* p = G.vertices[i].firstarc;p->nextarc;p = p->nextarc)
        {
            int j = p->adjvex;
            int x = find(j);
            if(x != y)
                fa[x] = y;
        }
    }

    int cnt = 0;

    for(int i = 0;i < G.vexnum;i++)
    {
        if(fa[i] == i)
            cnt++;
    }
    return cnt;
}

int main()
{
    ALGraph g;
    CreateGraph(g);
    printf("The number of connected components in this UDN is: \n");
    printf("%d", uni(g));
    return 0;
}
