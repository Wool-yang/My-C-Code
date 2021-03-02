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

int fa[MAX_VERTEX_NUM];

int find(int x)
{
    if(fa[x] != x)
        return fa[x] = find(fa[x]);
    else
        return x;
}

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

int uni(ALGraph G)
{
    for(int i = 0;i < G.vexnum;i++)
    {
        fa[i] = i;
    }

    for(int i = 0;i < G.vexnum;i++)
    {
        int y = find(i);
        for(ArcNode* p = G.vertices[i].firstarc;p->nextarc;p = p->nextarc)
        {
            int j = p->adjvex;
            int x = find(j);
            if(x != y)
                fa[x] = y;
        }
    }

    int cnt = 0;

    for(int i = 0;i < G.vexnum;i++)
    {
        if(fa[i] == i)
            cnt++;
    }
    return cnt;
}

int main()
{
    ALGraph g;
    CreateGraph(g);
    printf("The number of connected components in this UDN is: \n");
    printf("%d", uni(g));
    return 0;
}
