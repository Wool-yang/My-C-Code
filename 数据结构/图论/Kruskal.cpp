#include<iostream>
#include<cstdio>
#include<algorithm>

#define INFINITY INT_MAX
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
	cout << "����ͼ�ĵ��� �� ������" << endl;       // ����ͼ����
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
        cout << "��������ÿ������ �����ڽӵ�(������ֵ ��������) �� Ȩֵ��" << endl; 
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

struct edge
{
    int st;
    int en;
    int cost;
};

int fa[MAX_VERTEX_NUM], peo[MAX_VERTEX_NUM];        // ���鼯����������Ƿ������һ����ͨ������
                                                    // peo���鱣�浱ǰ����Ԫ�ظ���
int find(int x)             // ���鼯 find ����
{
    if(fa[x] != x)
        return fa[x] = find(fa[x]);
    else
        return x;
}

bool cmp(edge a, edge b)
{
    if(a.cost < b.cost)
        return true;
    return false;
}

void Kruskal(MGraph &G)
{
    int num = 2 * G.arcnum;         // ����ͼ�˶�
    struct edge edges[num];
    int cnt = 0;
    for(int i = 0;i < G.vexnum;i++)
    {
        for(int j = 0;j < G.vexnum;j++)
        {
            if(G.arcs[i][j].adj < INFINITY)
                edges[cnt++] = {i, j, G.arcs[i][j].adj};
        }
    }

    sort(edges, edges + num, cmp);

    for(int i = 0;i < G.vexnum;i++)
    {
        fa[i] = i;
        peo[i] = 1;
    }

    for(int j = 0;j < num;j++)
    {
        int x = edges[j].st, y = edges[j].en;
        x = find(x);
        y = find(y);
        if(x != y)
        {
            fa[y] = x;
            peo[x] += peo[y];       // ���¼��ϳ�Ա��
            cout << "��㣺" << " " << G.vexs[edges[j].st] << "�յ㣺" << " " << G.vexs[edges[j].en] << "Ȩֵ��" << edges[j].cost << endl;
        }

        if(peo[x] == G.vexnum)
            break;                  // ��� ���ϵ��� �� ͼ�ĵ�����ͬ �������������
    }
}

int main()
{
    MGraph a;
    CreateGraph(a);
    Kruskal(a);
    return 0;
}
