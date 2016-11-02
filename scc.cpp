#include <bits/stdc++.h>
using namespace std;

 typedef long long int lli;
 typedef vector<int> vi;
 typedef vector<long long int> vlli;
 typedef vector<vi> vvi;
 typedef pair<int,int> ii;

 #define tr(container, it)  for(typeof((container).begin()) it = container.begin(); it != container.end(); it++)
 #define size_max 10000



 typedef struct{
 lli node;
 lli distance;
 }vertex;
 enum col {white,grey,black };


 class compare{
public: bool operator()(vertex v1,vertex v2)
        {
            if (v1.distance>v2.distance)
                return true;
            else return false;
        }
 };

 class Graph{
   public:  int n;
            vector< list<int> > adj= vector< list<int> > (size_max);
            void addedge(int u,int v);                     //for undirected use addedge(u,v,w) and addedge(v,u,w)
            Graph(int x) {n=x;}
};
void Graph::addedge(int u,int v)
{
    adj[u].push_back(v);
    //adj[v].push_back(u);                           //remove " // " for undirected
}
Graph transpose(Graph G)
{
    Graph gt(G.n);
    int n=G.n;
    for(int i=0;i<n;i++)
    {
        list<int> ::iterator it;
        for(it=G.adj[i].begin();it!=G.adj[i].end();it++)
        {
            gt.adj[*it].push_back(i);
        }
    }
    return gt;
}
void dfs_visit(Graph G,int u,bool visited[],vector<vector<int> > &scc,int index)
{

    visited[u]=true;
    scc[index].push_back(u);

    tr(G.adj[u],it)
    {
        if (!visited[*it])
        {

           dfs_visit(G,(*it),visited,scc,index);
        }
    }


}

void dfs_visit(Graph G,int u,bool visited[],list<int> &topolist)
{

    visited[u]=true;

    tr(G.adj[u],it)
    {
        if (!visited[*it])
        {

           dfs_visit(G,(*it),visited,topolist);
        }
    }

    topolist.push_front(u);
}
list<int> dfs(Graph G)
{
    bool visited[G.n];
    for(int i=0;i<G.n;i++)
        visited[i]=false;

    list<int> topolist;

    for (int u=0;u<G.n;u++ )
        if  (!visited[u])
            {
                dfs_visit(G,u,visited,topolist);
            }
    return topolist;

}
void SCC(Graph G)
{   list<int> topolist=dfs(G);
    Graph gt=transpose(G);
    bool visited[G.n];
    int index=0;
    int n=G.n;
    vector< vector<int> > scc(n);
    for(int i=0;i<G.n;i++)
        visited[i]=false;
        while(!topolist.empty())
        {
            int u=topolist.front();
            topolist.pop_front();
            if  (!visited[u])
            {
                dfs_visit(gt,u,visited,scc,index);
                index++;
            }

        }
    for(int i=0;i<index;i++)
        {
        for(int j=0;j<scc[i].size();j++)
            cout<<" scc no "<<i<<" "<<scc[i][j]<<endl;

    }


}



int main()
{
    int n,m;
    cin>>n>>m;
    Graph G(n);
    for(int i=0;i<m;i++)
        {
        int u,v;
        cin>>u>>v;
        G.addedge(u,v);

    }
    SCC(G);

}
