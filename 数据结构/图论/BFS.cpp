#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<queue>

#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 20
#define OK 1
#define OVERFLOW -2
#define ERROR -1

using namespace std;

bool visited[MAX_VERTEX_NUM];

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
    cout << "����ͼ�ĵ��� �� ������" << endl; 
    cin >> G.vexnum >> G.arcnum;
    for(int i = 0;i < G.vexnum;i++)
    {
        cout << "����� " << i << " �Žڵ��data" << endl;
        cin >> G.vertices[i].data;
        G.vertices[i].firstarc = (ArcNode *)malloc(sizeof(ArcNode));
        ArcNode* temp = G.vertices[i].firstarc;
        char x;
        cout << "����� " << i << " �Žڵ���ڽӵ㣬�ո�ֿ���#����" << endl;
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

void visit(ALGraph g, int i)
{
	cout << "BFS˳������µ�ǰ��Ĵ���ֵΪ��"; 
    cout << g.vertices[i].data << endl;
}

void BFSTraverse(ALGraph G)
{
    for(int i = 0;i < G.vexnum;i++)
        visited[i] = false;
    queue<ArcNode *> q;
    for(int i = 0;i < G.vexnum;i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            visit(G, i);
            if(G.vertices[i].firstarc != NULL)
                q.push(G.vertices[i].firstarc);
            while(!q.empty())
            {
                ArcNode* t = q.front();
                q.pop();
                for(int j = t->adjvex;t->nextarc != NULL;t = t->nextarc, j = t->adjvex)
                {
                    if(!visited[j])
                    {
                        visited[j] = true;
                        visit(G, j);
                        q.push(G.vertices[j].firstarc);
                    }
                }
            }
        }
    }
}

int main()
{
    ALGraph g;
    CreateGraph(g);
    BFSTraverse(g);   
	return 0;
}
