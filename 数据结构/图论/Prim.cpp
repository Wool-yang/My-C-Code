#include<iostream>
#include<cstdio>
#include<algorithm>

#define INFINITY INT_MAX
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

struct close
{
    int adjvex;
    int lowcost;
    int pos;
}closeedge[MAX_VERTEX_NUM];

bool cmp(close a, close b)
{
    if(a.lowcost < b.lowcost)
        return true;
    return false;    
}

int mininum(int num, close* closeedge)
{
    close closeedge1[num];      // 另开一个结构体数组用来排序

    for(int i = 0;i < num;i++)
    {
        closeedge1[i].adjvex = closeedge[i].adjvex;
        closeedge1[i].lowcost = closeedge[i].lowcost;
        closeedge1[i].pos = closeedge[i].pos;
    }
    
    sort(closeedge1, closeedge1 + num, cmp);

    for(int i = 0;i < num;i++)
        if(closeedge1[i].lowcost > 0)            // 把已在集合中的边设 0
            return closeedge1[i].pos;
}

void MiniSpanTree_PRIM(MGraph G, int u)
{
    int k = LocateVex(G, u);
    for(int j = 0;j < G.vexnum;j++)
        if(j != k)
            closeedge[j] = {u, G.arcs[k][j].adj, j};
	closeedge[k].pos = k;
	closeedge[k].lowcost = 0;
    for(int i = 1;i < G.vexnum;i++)
    {
        k = mininum(G.vexnum, closeedge);
        cout << closeedge[k].adjvex << " " << G.vexs[k] << endl;
        closeedge[k].lowcost = 0;
        for(int j = 0;j < G.vexnum;j++)
            if(G.arcs[k][j].adj < closeedge[j].lowcost)
                closeedge[j] = {G.vexs[k], G.arcs[k][j].adj, j};        // 用新加入的点更新其余所有点到集合的代价
    }
}

int main()
{
    MGraph a;
    CreateGraph(a);
    MiniSpanTree_PRIM(a, 2);
    return 0;
}
