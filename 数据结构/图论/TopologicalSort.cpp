#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<stack>

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
        {
            temp->adjvex = x - 48;
        }
        while(x != '#')
        {
            temp->nextarc = (ArcNode *)malloc(sizeof(ArcNode));
            temp = temp->nextarc;
            cin >> x;
            if(x != '#')
            {
                temp->adjvex = x - 48;
            }
        }
        temp->nextarc = NULL;
    }
}

int Topologic(ALGraph &G)
{
    int indegree[G.vexnum]; // 用数组保存每个结点的入度
    memset(indegree, 0, sizeof(indegree));

    for(int i = 0;i < G.vexnum;i++)
    {
         for(ArcNode* p = G.vertices[i].firstarc;p->nextarc != NULL;p = p->nextarc)
        {
            int k = p->adjvex;
            indegree[k]++; // 计算入度
        }
    }

    stack<int> s; // 用栈来保存入度为 0 的结点
    for(int i = 0;i < G.vexnum;i++)
        if(!indegree[i])
            s.push(i); // 先找一遍嗷
    
    int cnt = 0; // 记录拓扑排序过程中的结点数

    while(!s.empty())
    {
        int t = s.top(); // 每次出栈一个入度为 0 的一个结点 并将其并入拓扑排序中
        s.pop();
        cout << "当前入度为零的节点的序号为：" << t << endl << "保存的数据为：" << G.vertices[t].data << endl;
        cnt++;
        for(ArcNode* p = G.vertices[t].firstarc;p->nextarc != NULL;p = p->nextarc)
        {
            int k = p->adjvex;  // 用出栈结点更新与他相连的结点入度
            if(!(--indegree[k])) // 入度为 0 入栈
                s.push(k);
        }
    }
    if(cnt < G.vexnum) // 拓扑排序中的点小于图中点数 存在环
        return ERROR;
    else
        return OK;
}

int main()
{
    ALGraph g;
    CreateGraph(g);
    Topologic(g);
    return 0;
}
