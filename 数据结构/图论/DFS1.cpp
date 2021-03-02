#include<iostream>
#include<cstdio>

#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 20
#define OK 1
#define OVERFLOW -2
#define ERROR -1

using namespace std;

typedef enum{DG, DN, UDG, UDN} GraphKind;

bool visited[MAX_VERTEX_NUM];

typedef struct ArcCell
{
    int adj;

    // 可储存一些与弧相关的信息
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct
{
    int vexs[MAX_VERTEX_NUM];
    AdjMatrix arcs;
    int vexnum, arcnum;
    GraphKind kind;
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

void visit(MGraph g, int i)
{
    cout << "DFS顺序遍历下当前点的储存值为： "; 
    cout << g.vexs[i] << endl;
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

void DFS(MGraph G, int i)
{
    visited[i] = true;
    visit(G, i);
    int j = 0;
    for(int k = 0;k < G.vexnum;k++)
        if(!visited[k] && G.arcs[i][k].adj != INFINITY)
            DFS(G, k);
}

void DFSTraverse(MGraph &G)
{
    for(int i = 0;i < G.vexnum;i++)
        visited[i] = false;
    for(int i = 0;i < G.vexnum;i++)
        if(!visited[i])
            DFS(G, i);
}

int main()
{
    MGraph a;
    CreateGraph(a);
    DFSTraverse(a);
    return 0;
}
