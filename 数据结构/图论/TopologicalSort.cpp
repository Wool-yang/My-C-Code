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
    int indegree[G.vexnum]; // �����鱣��ÿ���������
    memset(indegree, 0, sizeof(indegree));

    for(int i = 0;i < G.vexnum;i++)
    {
         for(ArcNode* p = G.vertices[i].firstarc;p->nextarc != NULL;p = p->nextarc)
        {
            int k = p->adjvex;
            indegree[k]++; // �������
        }
    }

    stack<int> s; // ��ջ���������Ϊ 0 �Ľ��
    for(int i = 0;i < G.vexnum;i++)
        if(!indegree[i])
            s.push(i); // ����һ���
    
    int cnt = 0; // ��¼������������еĽ����

    while(!s.empty())
    {
        int t = s.top(); // ÿ�γ�ջһ�����Ϊ 0 ��һ����� �����䲢������������
        s.pop();
        cout << "��ǰ���Ϊ��Ľڵ�����Ϊ��" << t << endl << "���������Ϊ��" << G.vertices[t].data << endl;
        cnt++;
        for(ArcNode* p = G.vertices[t].firstarc;p->nextarc != NULL;p = p->nextarc)
        {
            int k = p->adjvex;  // �ó�ջ���������������Ľ�����
            if(!(--indegree[k])) // ���Ϊ 0 ��ջ
                s.push(k);
        }
    }
    if(cnt < G.vexnum) // ���������еĵ�С��ͼ�е��� ���ڻ�
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
