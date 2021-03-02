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
    ArcNode* first;             // 用单链表保存起点到每个节点的路径
    int num;
}path[MAX_VERTEX_NUM];

bool final[MAX_VERTEX_NUM];    // final数组 记录每个点的最短路是否被确定

void dijkstra(MGraph &G, int v0, Path* p, int d[])
{
    for(int i = 0;i < G.vexnum;i++)
    {
        final[i] = false;
        p[i].num = 1;
        p[i].first = (ArcNode *)malloc(sizeof(ArcNode));
        p[i].first->vex = v0;
        d[i] = G.arcs[v0][i].adj;
        if(d[i] < INFINITY)
        {
            p[i].first->next = (ArcNode *)malloc(sizeof(ArcNode));
            p[i].first->next->vex = i;
            p[i].num = 2;          // 初始化路径
        }
    }
    
    int poi;

    for(int i = 1;i < G.vexnum;i++)
    {
        int min = INFINITY;
        for(int j = 0;j < G.vexnum;j++)
        {
            if(!final[j])
            {
                if(d[j] < min)
                {
                    poi = j;
                    min = d[j];       // 每次在所有点中选择距离起点最近的点
                }   
            }
        }

        final[poi] = true;            // 记录此点已确定最短路

        for(int j = 0;j < G.vexnum;j++)
        {
            // 用已确定最短路的点更新其余所有未确定最短路的点的 dist
            if(!final[j] && (min + G.arcs[poi][j].adj < d[j]))
            {
                d[j] = min + G.arcs[poi][j].adj;     
                
                ArcNode* clean = p[j].first;

                for(int i = 0;i < path[j].num;i++)
                {
                    ArcNode* last = clean;
                    clean = clean->next;
                    free(last);                    // 删除 j点 原路径
                }           

                p[j].first = (ArcNode *)malloc(sizeof(ArcNode));

                ArcNode* tep = p[j].first;
                ArcNode* tmp = p[poi].first;        // 更新 起点到j点 的最短路径记录

                for(int k = 0;k < p[poi].num;k++, tep = tep->next, tmp = tmp->next)
                {
                    tep->vex = tmp->vex;
                    tep->next = (ArcNode *)malloc(sizeof(ArcNode));
                }

                p[j].num = p[poi].num;
                tep->vex = j;
                p[j].num++;
            }
        }
    }
}

int main()
{
    MGraph a;
    CreateGraph(a);
    int d[a.vexnum];       // 维护一个 dist数组储存起点到其余各点的最短路径

    int x, y;
    cout << "请输入起点与要查询的点(输入点的储存值)：";
    cin >> x >> y;

    x = LocateVex(a, x);
    y = LocateVex(a, y);

    dijkstra(a, x, path, d);
    
    cout << x << "号结点到" << y << "号结点的最短路长度为：";
    cout << d[y] << endl;

    cout << x << "号结点到" << y << "号结点的最短路路径长度为：";
    cout << path[y].num << endl;

    ArcNode* j = path[y].first;
    cout << "记录的路径为：" << endl;
    for(int i = 0;i < path[y].num;i++, j = j->next)
    {
        cout << j->vex << endl;
    }
    return 0;
}
