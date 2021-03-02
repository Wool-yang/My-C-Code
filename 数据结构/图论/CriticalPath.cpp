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
    int cost;                     // 该弧相关信息的指针
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

int Locate(ALGraph &G, int x)
{
    for(int i = 0;i < G.vexnum;i++)
        if(G.vertices[i].data == x)
            return i;
}

void CreateGraphDouble(ALGraph &G)
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

stack<int> T;

int ve[MAX_VERTEX_NUM]; // 保存每个活动的最早开始时间

int vl[MAX_VERTEX_NUM]; // 保存每个活动的最迟开始时间                                                       

int Topologic(ALGraph &G)
{
    int indegree[G.vexnum];
    memset(indegree, 0, sizeof(indegree));
    memset(ve, 0,sizeof(ve));

    for(int i = 0;i < G.vexnum;i++)
    {
         for(ArcNode* p = G.vertices[i].firstarc;p->nextarc != NULL;p = p->nextarc)
        {
            int k = p->adjvex;
            indegree[k]++;
        } 
    }

    stack<int> s;

    for(int i = 0;i < G.vexnum;i++)
        if(!indegree[i])
            s.push(i);
    
    int cnt = 0;

    while(!s.empty())
    {
        int t = s.top();
        s.pop();
        T.push(t);  // 用栈 T 保存逆拓扑排序
        cout << "当前入度为零的节点的序号为：" << t << endl << "保存的数据为：" << G.vertices[t].data << endl;
        cnt++;
        for(ArcNode* p = G.vertices[t].firstarc;p->nextarc != NULL;p = p->nextarc)
        {
            int k = p->adjvex;
            int dut = p->cost;
            if(ve[k] < ve[t] + dut)
                ve[k] = ve[t] + dut; // 活动的最早开始时间由之前所有活动中 用时最长的活动决定
            if(!(--indegree[k]))
                s.push(k);
        }
    }
    if(cnt < G.vexnum)
        return ERROR;
    else
        return OK;
}

int CriticalPach(ALGraph &G)
{
    if(!Topologic(G)) return ERROR; // 如果图中有环 则无拓扑序列 无关键路径
    for(int i = 0;i < G.vexnum;i++)
        vl[i] = ve[G.vexnum - 1]; // 初始化所有活动的最迟开始时间
    while(!T.empty())
    {
        int t = T.top();
        T.pop();
        for(ArcNode* p = G.vertices[t].firstarc;p->nextarc != NULL;p = p->nextarc)
        {
            int k = p->adjvex;
            int dut = p->cost;
            if(vl[k] - dut < vl[t]) vl[t] = vl[k] - dut; // 活动的最迟开始时间由之后所有活动中 用时最长的活动决定
        }
    }
    for(int i = 0;i < G.vexnum;i++)
    {
        for(ArcNode* p = G.vertices[i].firstarc;p->nextarc != NULL;p = p->nextarc)
        {
            int k = p->adjvex;
            int dut = p->cost;
            int ee = ve[i], el = vl[k] - dut;
            char tag = (ee == el) ? '*' : ' '; // 是否为关键路径
            cout << G.vertices[i].data << " " << G.vertices[k].data << " " << dut << " " << ee << " " << el << " " << tag << endl; 
        }
    }
}
int main()
{
    ALGraph g1;
    CreateGraphDouble(g1);
    CriticalPach(g1);
    return 0;
}
