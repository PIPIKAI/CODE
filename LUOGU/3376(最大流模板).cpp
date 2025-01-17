#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int inf=1e9;

int n,m,x,y,z,maxflow,deep[500];//deep深度
struct Edge{
    int next,to,dis;
}edge[500];
int num_edge=-1,head[500],cur[500];//cur用于复制head
queue <int> q;

void add_edge(int from,int to,int dis,bool flag)
{
    edge[++num_edge].next=head[from];
    edge[num_edge].to=to;
    if (flag) edge[num_edge].dis=dis;//反图的边权为 0
    head[from]=num_edge;
}

//bfs用来分层
bool bfs(int s,int t)
{
    memset(deep,0x7f,sizeof(deep));
    while (!q.empty()) q.pop();
    for (int i=1; i<=n; i++) cur[i]=head[i];
    deep[s]=0;
    q.push(s);

    while (!q.empty())
    {
        int now=q.front(); q.pop();
        for (int i=head[now]; i!=-1; i=edge[i].next)
        {
            if (deep[edge[i].to]>inf && edge[i].dis)//dis在此处用来做标记 是正图还是返图
            {
                deep[edge[i].to]=deep[now]+1;
                q.push(edge[i].to);
            }
        }
    }
    if (deep[t]<inf) return true;
    else return false;
}

//dfs找增加的流的量
int dfs(int now,int t,int limit)//limit为源点到这个点的路径上的最小边权
{
    if (!limit || now==t) return limit;

    int flow=0,f;
    for (int i=cur[now]; i!=-1; i=edge[i].next)
    {
        cur[now]=i;
        if (deep[edge[i].to]==deep[now]+1 && (f=dfs(edge[i].to,t,min(limit,edge[i].dis))))
        {
            flow+=f;
            limit-=f;
            edge[i].dis-=f;
            edge[i^1].dis+=f;
            if (!limit) break;
        }
    }
    return flow;
}

void Dinic(int s,int t)
{
    while (bfs(s,t))
        maxflow+=dfs(s,t,inf);
}

int main()
{
//  for (int i=0; i<=500; i++) edge[i].next=-1;
    memset(head,-1,sizeof(head));
    scanf("%d%d",&m,&n);
    for (int i=1; i<=m; i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        add_edge(x,y,z,1); add_edge(y,x,z,0);
    }
    Dinic(1,n);
    printf("%d",maxflow);
    return 0;
}
