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
    int cost;                     // �û������Ϣ��ָ��
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

int Locate(ALGraph &G, int x)
{
    for(int i = 0;i < G.vexnum;i++)
        if(G.vertices[i].data == x)
            return i;
}

void CreateGraphDouble(ALGraph &G)
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

stack<int> T;

int ve[MAX_VERTEX_NUM]; // ����ÿ��������翪ʼʱ��

int vl[MAX_VERTEX_NUM]; // ����ÿ�������ٿ�ʼʱ��                                                       

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
        T.push(t);  // ��ջ T ��������������
        cout << "��ǰ���Ϊ��Ľڵ�����Ϊ��" << t << endl << "���������Ϊ��" << G.vertices[t].data << endl;
        cnt++;
        for(ArcNode* p = G.vertices[t].firstarc;p->nextarc != NULL;p = p->nextarc)
        {
            int k = p->adjvex;
            int dut = p->cost;
            if(ve[k] < ve[t] + dut)
                ve[k] = ve[t] + dut; // ������翪ʼʱ����֮ǰ���л�� ��ʱ��Ļ����
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
    if(!Topologic(G)) return ERROR; // ���ͼ���л� ������������ �޹ؼ�·��
    for(int i = 0;i < G.vexnum;i++)
        vl[i] = ve[G.vexnum - 1]; // ��ʼ�����л����ٿ�ʼʱ��
    while(!T.empty())
    {
        int t = T.top();
        T.pop();
        for(ArcNode* p = G.vertices[t].firstarc;p->nextarc != NULL;p = p->nextarc)
        {
            int k = p->adjvex;
            int dut = p->cost;
            if(vl[k] - dut < vl[t]) vl[t] = vl[k] - dut; // �����ٿ�ʼʱ����֮�����л�� ��ʱ��Ļ����
        }
    }
    for(int i = 0;i < G.vexnum;i++)
    {
        for(ArcNode* p = G.vertices[i].firstarc;p->nextarc != NULL;p = p->nextarc)
        {
            int k = p->adjvex;
            int dut = p->cost;
            int ee = ve[i], el = vl[k] - dut;
            char tag = (ee == el) ? '*' : ' '; // �Ƿ�Ϊ�ؼ�·��
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
