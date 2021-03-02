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
