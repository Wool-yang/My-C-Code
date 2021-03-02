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
    char adjvex;
    struct ArcNode *nextarc;
}ArcNode;

typedef struct VNode
{
    char data;
    ArcNode *firstarc;
}VNode, AdjList[MAX_VERTEX_NUM];


typedef struct
{
    AdjList vertices;
    int vexnum, arcnum;
    int kind;
}ALGraph;

void CreateGraph(ALGraph &G)
{
    cout << "输入图的点数 与 弧数：" << endl; 
    cin >> G.vexnum >> G.arcnum;
    for(int i = 0;i < G.vexnum;i++)
    {
        cout << "输入第 " << i << " 号节点的data" << endl;
        cin >> G.vertices[i].data;
        G.vertices[i].firstarc = (ArcNode *)malloc(sizeof(ArcNode));
        ArcNode* temp = G.vertices[i].firstarc;
        char x;
        cout << "输入第 " << i << " 号节点的邻接点，空格分开，#结束" << endl;
        cin >> x;
        if(x != '#')
            temp->adjvex = x - 48;
        while(x != '#')
        {
            temp->nextarc = (ArcNode *)malloc(sizeof(ArcNode));
            temp = temp->nextarc;
            cin >> x;
            if(x != '#')
                temp->adjvex = x - 48;
        }
        temp->nextarc = NULL;
    }
}

bool visited[MAX_VERTEX_NUM];

void visit(ALGraph g, int i)
{
	cout << "DFS顺序遍历下当前点的储存值为： "; 
    cout << g.vertices[i].data << endl;
}

void DFS(ALGraph g, int i)
{
    visited[i] = true; 
    visit(g, i);
    int j;
    ArcNode* k;
    for(j = g.vertices[i].firstarc->adjvex, k = g.vertices[i].firstarc;k->nextarc != NULL;k = k->nextarc, j = k->adjvex)
        if(!visited[j])
			DFS(g, j);
}

void DFSTraverse(ALGraph g)
{
    for(int i = 0;i < g.vexnum;i++)
        visited[i] = false;
    for(int i = 0;i < g.vexnum;i++)
        if(!visited[i])
            DFS(g, i);
}


int main()
{
    ALGraph g;
    CreateGraph(g);
    DFSTraverse(g);   
	return 0;
}
