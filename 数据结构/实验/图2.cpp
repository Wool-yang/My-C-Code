#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>

#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 20
#define OK 1
#define OVERFLOW -2
#define ERROR -1

using namespace std;

typedef struct ArcNode
{
    int adjvex;                    // �û�ָ��Ķ����λ��
    struct ArcNode *nextarc;       // ָ����һ������ָ��
    //InfoType *info;                 �û������Ϣ��ָ��
    int cost;
}ArcNode;

typedef struct VNode
{
    int data;                      // ������Ϣ
    ArcNode *firstarc;             // ָ���һ�������ö���Ļ���ָ��
}VNode, AdjList[MAX_VERTEX_NUM];

typedef struct
{
    AdjList vertices;              
    int vexnum, arcnum;            // ͼ�ĵ�ǰ ������ �� ����
    int kind;                      // ͼ�������־
}ALGraph;

int Locate(ALGraph G, int x)
{
    for(int i = 0;i < G.vexnum;i++)
    {
        if(G.vertices[i].data == x)
            return i;
    }
}

void CreateGraph(ALGraph &G)
{
    cout << "����ͼ�ĵ��� �� ������" << endl; 
    cin >> G.vexnum >> G.arcnum;
    for(int i = 0;i < G.vexnum;i++)
    {
        cout << "����� " << i << " �Žڵ��data" << endl;
        cin >> G.vertices[i].data;
    }

    for(int i = 0;i < G.vexnum;i++)
    {
        G.vertices[i].firstarc = (ArcNode *)malloc(sizeof(ArcNode));
        ArcNode* temp = G.vertices[i].firstarc;
        char x;
        cout << "����� " << i << " �Žڵ���ڽӵ㣬����#����" << endl;
        cin >> x;
        if(x != '#')
        {
            temp->adjvex = Locate(G, x - 48);
            cout << "���뵽���ڽӵ�ľ��룺";
            cin >> temp->cost;
        }
        while(x != '#')
        {
            temp->nextarc = (ArcNode *)malloc(sizeof(ArcNode));
            temp = temp->nextarc;
            cout << "����� " << i << " �Žڵ���ڽӵ㣬����#����" << endl;
            cin >> x;
            if(x != '#')
            {
                temp->adjvex = Locate(G, x - 48);
                cout << "���뵽���ڽӵ�ľ��룺";
                cin >> temp->cost;
            }
        }
        temp->nextarc = NULL;
    }
}

bool visited[MAX_VERTEX_NUM];

bool n = false;

void DFStravels(ALGraph G, int vi, int vj)
{
    for(ArcNode* p = G.vertices[vi].firstarc;p->nextarc;p = p->nextarc)
    {
        if(!visited[p->adjvex])
        {
            visited[p->adjvex] = true;
            cout << G.vertices[p->adjvex].data << endl;
            if(p->adjvex == vj)
                n = true;
            else 
                DFStravels(G, p->adjvex, vj);
        }
    }
}

int main()
{
    memset(visited, 0, sizeof(visited));
    ALGraph g;
    CreateGraph(g);
    printf("Input Vi and Vj:");
    int vi,vj;
    scanf("%d%d", &vi, &vj);
    vi = Locate(g, vi);
    vj = Locate(g, vj);
    cout << vi << " " << vj << endl;
    DFStravels(g, vi, vj);
    cout << n << endl;
    return 0;
}
