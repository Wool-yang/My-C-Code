#include<iostream>
#include<cstdio>
#include<queue>

#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 20
#define OK 1
#define OVERFLOW -2
#define ERROR -1

using namespace std;

bool visited[MAX_VERTEX_NUM];

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

void visit(MGraph g, int i)
{
    cout << "BFS˳������µ�ǰ��Ĵ���ֵΪ�� "; 
    cout << g.vexs[i] << endl;
}

void BFSTraverse(MGraph G)
{
    for(int i = 0;i < G.vexnum;i++) 
        visited[i] = false;
    queue<int> q;
    for(int i = 0;i < G.vexnum;i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            visit(G, i);
            q.push(i);
            while(!q.empty())
            {
                int t = q.front();
                q.pop();
                for(int j = 0;j < G.vexnum;j++)
                {
                    if(G.arcs[t][j].adj != INFINITY && !visited[j])
                    {
                        visited[j] = true;
                        visit(G, j);
                        q.push(j);
                    }
                }
            }
        }
    }
}

int main()
{
    MGraph a;
    CreateGraph(a);
    BFSTraverse(a);
    return 0;
}