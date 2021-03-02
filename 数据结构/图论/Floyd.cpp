#include<iostream>
#include<cstdio>
#include<cstdlib>

#define INFINITY 0x3f3f3f3f
#define MAX_VERTEX_NUM 20
#define OK 1
#define OVERFLOW -2
#define ERROR -1

using namespace std;

typedef enum{DG, DN, UDG, UDN} GraphKind;          // {����ͼ��������������ͼ��������}

typedef struct ArcCell
{
    int adj;                                       // ��Ȩͼ �� ����֮���Ȩֵ ��Ȩͼ�� 0 1 ���Ƿ�����
    
    // �ɴ���һЩ�뻡��ص���Ϣ
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];  

typedef struct
{
    int vexs[MAX_VERTEX_NUM];                      // ��������        
    AdjMatrix arcs;                                // �ڽӾ���
    int vexnum, arcnum;                            // ͼ�� ������ �� ����
    GraphKind kind;                                // ͼ������
}MGraph;

int LocateVex(MGraph g, int x)
{
    for(int i = 0;i < g.vexnum;i++)
    {
        if(g.vexs[i] == x)
            return i;
    }
}

int CreateDG(MGraph &G)
{
    return OK;
}

int CreateDN(MGraph &G)
{
    return OK;
}

int CreateUDG(MGraph &G)
{
    return OK;
}

int CreateUDN(MGraph &G)
{
	cout << "����ͼ�ĵ��� �� ������" << endl; 
    cin >> G.vexnum >> G.arcnum;
    for(int i = 0; i < G.vexnum; i++)
    {
    	cout << "��������ͼ�ĸ���� ֵ��" << endl; 
        cin >> G.vexs[i];
	} 	
    for(int i = 0; i < G.vexnum; i++)
        for(int j = 0; j < G.vexnum; j++)
            G.arcs[i][j].adj = INFINITY;
    for(int k = 0; k < G.arcnum; k++)
    {
        int v1, v2, w;
        int i, j;
        cout << "��������ÿ������ ��� �� �յ�(������ֵ ��������) �� Ȩֵ��" << endl; 
        cin >> v1 >> v2 >> w;
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        G.arcs[i][j].adj = w;
        G.arcs[j][i] = G.arcs[i][j];
    }
    return OK;
}

int CreateGraph(MGraph &G)
{
    string a;
    cout << "����ͼ�����ͣ�" << endl; 
    cin >> a;
    if(a == "DG") G.kind = DG;
    if(a == "DN") G.kind = DN;
    if(a == "UDG") G.kind = UDG;
    if(a == "UDN") G.kind = UDN;
    switch(G.kind)
    {
        case DG: return CreateDG(G);
        case DN: return CreateDN(G);
        case UDN: return CreateUDN(G);
        case UDG: return CreateUDG(G);
        default : return ERROR;
    }
    return OK;
}

typedef struct ArcNode
{
    struct ArcNode* next;
    int vex;
}ArcNode;

struct Path
{
    ArcNode* first;
    int num;
}**path;          // ��������һ�㵽��һ�����·��

void Floyd(MGraph &G, Path** p, int** d)
{
    for(int i = 0;i < G.vexnum;i++)
    {
        for(int j = 0;j < G.vexnum;j++)
        {
            p[i][j].num = 1;
            p[i][j].first = (ArcNode *)malloc(sizeof(ArcNode));
            p[i][j].first->vex = i;
            d[i][j] = G.arcs[i][j].adj;
            if(d[i][j] < INFINITY)
            {
                p[i][j].first->next = (ArcNode *)malloc(sizeof(ArcNode));
                p[i][j].first->next->vex = j;
                p[i][j].num = 2;
            }                           // ��ʼ��·��
        }
    }
    
    for(int i = 0;i < G.vexnum;i++)
    {
        for(int j = 0;j < G.vexnum;j++)
        {
            for(int k = 0;k < G.vexnum;k++)
            {
                if(d[i][k] + d[k][j] < d[i][j])    
                {
                    d[i][j] = d[i][k] + d[k][j];      // �������� �������·��

                    ArcNode* clean = p[i][j].first;

                    for(int u = 0;u < path[i][j].num;u++)
                    {
                        ArcNode* last = clean;
                        clean = clean->next;
                        free(last);                    // ɾ�� i �� j ���ԭ·��
                    }

                    p[i][j].first = (ArcNode *)malloc(sizeof(ArcNode));

                    ArcNode* tep = p[i][j].first;
                    ArcNode* tmp = p[i][k].first;

                    for(int u = 0;u < p[i][k].num;u++, tep = tep->next, tmp = tmp->next)
                    {
                        tep->vex = tmp->vex;
                        tep->next = (ArcNode *)malloc(sizeof(ArcNode));
                    }

                    tmp = p[k][j].first->next; // i �� k ��·�������һ���� �� k �� j ��·���ĵ�һ�������ظ��ģ�ɾ����һ
                    for(int u = 0;u < p[k][j].num - 1;u++, tep = tep->next, tmp = tmp->next)
                    {
                        tep->vex = tmp->vex;
                        tep->next = (ArcNode *)malloc(sizeof(ArcNode));
                    }

                    p[i][j].num = p[i][k].num + p[k][j].num - 1;  // i �� k ��·�������һ���� �� k �� j ��·���ĵ�һ�������ظ��ģ����ȼ�һ
                }
            }
        }
    }
}

int main()
{
    MGraph a;
    CreateGraph(a);
    int** d;
    path = (Path**)malloc(a.vexnum * sizeof(Path*));
    for(int i = 0;i < a.vexnum;i++)
        path[i] = (Path*)malloc(a.vexnum * sizeof(Path));

    d = (int**)malloc(a.vexnum * sizeof(int*));
    for(int i = 0;i < a.vexnum;i++)
        d[i] = (int*)malloc(a.vexnum * sizeof(int));
    Floyd(a, path, d);

    int x, y;
    cout << "�������ѯ��������յ�(�����Ĵ���ֵ)��";
    cin >> x >> y;

    x = LocateVex(a, x);
    y = LocateVex(a, y);

    cout << x << "�Ž�㵽" << y << "�Ž������·����Ϊ��";
    cout << d[x][y] << endl;

    cout << x << "�Ž�㵽" << y << "�Ž������··������Ϊ��";
    cout << path[x][y].num << endl;

    ArcNode* tep = path[x][y].first;
    cout << "��¼��·��Ϊ��" << endl;
    for(int u = 0;u < path[x][y].num;u++, tep = tep->next)
        cout << tep->vex << endl;
    return 0;
}