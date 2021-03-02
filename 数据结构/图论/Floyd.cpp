#include<iostream>
#include<cstdio>
#include<cstdlib>

#define INFINITY 0x3f3f3f3f
#define MAX_VERTEX_NUM 20
#define OK 1
#define OVERFLOW -2
#define ERROR -1

using namespace std;

typedef enum{DG, DN, UDG, UDN} GraphKind;          // {有向图，有向网，无向图，无向网}

typedef struct ArcCell
{
    int adj;                                       // 有权图 表 顶点之间的权值 无权图用 0 1 表是否相邻
    
    // 可储存一些与弧相关的信息
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];  

typedef struct
{
    int vexs[MAX_VERTEX_NUM];                      // 顶点向量        
    AdjMatrix arcs;                                // 邻接矩阵
    int vexnum, arcnum;                            // 图的 顶点数 和 弧数
    GraphKind kind;                                // 图的种类
}MGraph;

int LocateVex(MGraph g, int x)
{
    for(int i = 0;i < g.vexnum;i++)
    {
        if(g.vexs[i] == x)
            return i;
    }
}

int CreateDG(MGraph &G)
{
    return OK;
}

int CreateDN(MGraph &G)
{
    return OK;
}

int CreateUDG(MGraph &G)
{
    return OK;
}

int CreateUDN(MGraph &G)
{
	cout << "输入图的点数 与 弧数：" << endl; 
    cin >> G.vexnum >> G.arcnum;
    for(int i = 0; i < G.vexnum; i++)
    {
    	cout << "依次输入图的各点的 值：" << endl; 
        cin >> G.vexs[i];
	} 	
    for(int i = 0; i < G.vexnum; i++)
        for(int j = 0; j < G.vexnum; j++)
            G.arcs[i][j].adj = INFINITY;
    for(int k = 0; k < G.arcnum; k++)
    {
        int v1, v2, w;
        int i, j;
        cout << "依次输入每条弧的 起点 与 终点(输入点的值 不是坐标) 与 权值：" << endl; 
        cin >> v1 >> v2 >> w;
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        G.arcs[i][j].adj = w;
        G.arcs[j][i] = G.arcs[i][j];
    }
    return OK;
}

int CreateGraph(MGraph &G)
{
    string a;
    cout << "输入图的类型：" << endl; 
    cin >> a;
    if(a == "DG") G.kind = DG;
    if(a == "DN") G.kind = DN;
    if(a == "UDG") G.kind = UDG;
    if(a == "UDN") G.kind = UDN;
    switch(G.kind)
    {
        case DG: return CreateDG(G);
        case DN: return CreateDN(G);
        case UDN: return CreateUDN(G);
        case UDG: return CreateUDG(G);
        default : return ERROR;
    }
    return OK;
}

typedef struct ArcNode
{
    struct ArcNode* next;
    int vex;
}ArcNode;

struct Path
{
    ArcNode* first;
    int num;
}**path;          // 单链表储存一点到另一点最短路径

void Floyd(MGraph &G, Path** p, int** d)
{
    for(int i = 0;i < G.vexnum;i++)
    {
        for(int j = 0;j < G.vexnum;j++)
        {
            p[i][j].num = 1;
            p[i][j].first = (ArcNode *)malloc(sizeof(ArcNode));
            p[i][j].first->vex = i;
            d[i][j] = G.arcs[i][j].adj;
            if(d[i][j] < INFINITY)
            {
                p[i][j].first->next = (ArcNode *)malloc(sizeof(ArcNode));
                p[i][j].first->next->vex = j;
                p[i][j].num = 2;
            }                           // 初始化路径
        }
    }
    
    for(int i = 0;i < G.vexnum;i++)
    {
        for(int j = 0;j < G.vexnum;j++)
        {
            for(int k = 0;k < G.vexnum;k++)
            {
                if(d[i][k] + d[k][j] < d[i][j])    
                {
                    d[i][j] = d[i][k] + d[k][j];      // 满足条件 更新最短路径

                    ArcNode* clean = p[i][j].first;

                    for(int u = 0;u < path[i][j].num;u++)
                    {
                        ArcNode* last = clean;
                        clean = clean->next;
                        free(last);                    // 删除 i 到 j 点的原路径
                    }

                    p[i][j].first = (ArcNode *)malloc(sizeof(ArcNode));

                    ArcNode* tep = p[i][j].first;
                    ArcNode* tmp = p[i][k].first;

                    for(int u = 0;u < p[i][k].num;u++, tep = tep->next, tmp = tmp->next)
                    {
                        tep->vex = tmp->vex;
                        tep->next = (ArcNode *)malloc(sizeof(ArcNode));
                    }

                    tmp = p[k][j].first->next; // i 到 k 的路径的最后一个点 与 k 到 j 的路径的第一个点是重复的，删除其一
                    for(int u = 0;u < p[k][j].num - 1;u++, tep = tep->next, tmp = tmp->next)
                    {
                        tep->vex = tmp->vex;
                        tep->next = (ArcNode *)malloc(sizeof(ArcNode));
                    }

                    p[i][j].num = p[i][k].num + p[k][j].num - 1;  // i 到 k 的路径的最后一个点 与 k 到 j 的路径的第一个点是重复的，长度减一
                }
            }
        }
    }
}

int main()
{
    MGraph a;
    CreateGraph(a);
    int** d;
    path = (Path**)malloc(a.vexnum * sizeof(Path*));
    for(int i = 0;i < a.vexnum;i++)
        path[i] = (Path*)malloc(a.vexnum * sizeof(Path));

    d = (int**)malloc(a.vexnum * sizeof(int*));
    for(int i = 0;i < a.vexnum;i++)
        d[i] = (int*)malloc(a.vexnum * sizeof(int));
    Floyd(a, path, d);

    int x, y;
    cout << "请输入查询的起点与终点(输入点的储存值)：";
    cin >> x >> y;

    x = LocateVex(a, x);
    y = LocateVex(a, y);

    cout << x << "号结点到" << y << "号结点的最短路长度为：";
    cout << d[x][y] << endl;

    cout << x << "号结点到" << y << "号结点的最短路路径长度为：";
    cout << path[x][y].num << endl;

    ArcNode* tep = path[x][y].first;
    cout << "记录的路径为：" << endl;
    for(int u = 0;u < path[x][y].num;u++, tep = tep->next)
        cout << tep->vex << endl;
    return 0;
}