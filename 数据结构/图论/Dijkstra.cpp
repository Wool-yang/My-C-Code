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
    ArcNode* first;             // �õ���������㵽ÿ���ڵ��·��
    int num;
}path[MAX_VERTEX_NUM];

bool final[MAX_VERTEX_NUM];    // final���� ��¼ÿ��������·�Ƿ�ȷ��

void dijkstra(MGraph &G, int v0, Path* p, int d[])
{
    for(int i = 0;i < G.vexnum;i++)
    {
        final[i] = false;
        p[i].num = 1;
        p[i].first = (ArcNode *)malloc(sizeof(ArcNode));
        p[i].first->vex = v0;
        d[i] = G.arcs[v0][i].adj;
        if(d[i] < INFINITY)
        {
            p[i].first->next = (ArcNode *)malloc(sizeof(ArcNode));
            p[i].first->next->vex = i;
            p[i].num = 2;          // ��ʼ��·��
        }
    }
    
    int poi;

    for(int i = 1;i < G.vexnum;i++)
    {
        int min = INFINITY;
        for(int j = 0;j < G.vexnum;j++)
        {
            if(!final[j])
            {
                if(d[j] < min)
                {
                    poi = j;
                    min = d[j];       // ÿ�������е���ѡ������������ĵ�
                }   
            }
        }

        final[poi] = true;            // ��¼�˵���ȷ�����·

        for(int j = 0;j < G.vexnum;j++)
        {
            // ����ȷ�����·�ĵ������������δȷ�����·�ĵ�� dist
            if(!final[j] && (min + G.arcs[poi][j].adj < d[j]))
            {
                d[j] = min + G.arcs[poi][j].adj;     
                
                ArcNode* clean = p[j].first;

                for(int i = 0;i < path[j].num;i++)
                {
                    ArcNode* last = clean;
                    clean = clean->next;
                    free(last);                    // ɾ�� j�� ԭ·��
                }           

                p[j].first = (ArcNode *)malloc(sizeof(ArcNode));

                ArcNode* tep = p[j].first;
                ArcNode* tmp = p[poi].first;        // ���� ��㵽j�� �����·����¼

                for(int k = 0;k < p[poi].num;k++, tep = tep->next, tmp = tmp->next)
                {
                    tep->vex = tmp->vex;
                    tep->next = (ArcNode *)malloc(sizeof(ArcNode));
                }

                p[j].num = p[poi].num;
                tep->vex = j;
                p[j].num++;
            }
        }
    }
}

int main()
{
    MGraph a;
    CreateGraph(a);
    int d[a.vexnum];       // ά��һ�� dist���鴢����㵽�����������·��

    int x, y;
    cout << "�����������Ҫ��ѯ�ĵ�(�����Ĵ���ֵ)��";
    cin >> x >> y;

    x = LocateVex(a, x);
    y = LocateVex(a, y);

    dijkstra(a, x, path, d);
    
    cout << x << "�Ž�㵽" << y << "�Ž������·����Ϊ��";
    cout << d[y] << endl;

    cout << x << "�Ž�㵽" << y << "�Ž������··������Ϊ��";
    cout << path[y].num << endl;

    ArcNode* j = path[y].first;
    cout << "��¼��·��Ϊ��" << endl;
    for(int i = 0;i < path[y].num;i++, j = j->next)
    {
        cout << j->vex << endl;
    }
    return 0;
}
