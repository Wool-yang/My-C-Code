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

int main()
{
    ALGraph g;
    CreateGraph(g);
    int j;
    ArcNode* i;
    for(j = g.vertices[0].firstarc->adjvex, i = g.vertices[0].firstarc;i->nextarc != NULL;i = i->nextarc, j = i->adjvex)
	    cout << j << endl;
    return 0;
}
