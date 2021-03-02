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
	cout << "输入图的点数 与 弧数：" << endl;       // 无向图输入
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
        cout << "依次输入每条弧的 两个邻接点(输入点的值 不是坐标) 与 权值：" << endl; 
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

struct edge
{
    int st;
    int en;
    int cost;
};

int fa[MAX_VERTEX_NUM], peo[MAX_VERTEX_NUM];        // 并查集检查两个点是否存在于一个连通分量中
                                                    // peo数组保存当前集合元素个数
int find(int x)             // 并查集 find 操作
{
    if(fa[x] != x)
        return fa[x] = find(fa[x]);
    else
        return x;
}

bool cmp(edge a, edge b)
{
    if(a.cost < b.cost)
        return true;
    return false;
}

void Kruskal(MGraph &G)
{
    int num = 2 * G.arcnum;         // 无向图乘二
    struct edge edges[num];
    int cnt = 0;
    for(int i = 0;i < G.vexnum;i++)
    {
        for(int j = 0;j < G.vexnum;j++)
        {
            if(G.arcs[i][j].adj < INFINITY)
                edges[cnt++] = {i, j, G.arcs[i][j].adj};
        }
    }

    sort(edges, edges + num, cmp);

    for(int i = 0;i < G.vexnum;i++)
    {
        fa[i] = i;
        peo[i] = 1;
    }

    for(int j = 0;j < num;j++)
    {
        int x = edges[j].st, y = edges[j].en;
        x = find(x);
        y = find(y);
        if(x != y)
        {
            fa[y] = x;
            peo[x] += peo[y];       // 更新集合成员数
            cout << "起点：" << " " << G.vexs[edges[j].st] << "终点：" << " " << G.vexs[edges[j].en] << "权值：" << edges[j].cost << endl;
        }

        if(peo[x] == G.vexnum)
            break;                  // 如果 集合点数 与 图的点数相同 生成树建立完毕
    }
}

int main()
{
    MGraph a;
    CreateGraph(a);
    Kruskal(a);
    return 0;
}
