#include <bits/stdc++.h>
using namespace std;

 typedef long long int lli;
 typedef vector<int> vi;
 typedef vector<long long int> vlli;
 typedef vector<vi> vvi;
 typedef pair<int,int> ii;
 #define all(c) (c).begin(),(c).end()
 #define tr(container, it)  for(decltype((container).begin()) it = container.begin(); it != container.end(); it++)
 #define size 10000



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
            vector< list<int> > adj= vector< list<int> > (size);
            void addedge(int u,int v);                     //for undirected use addedge(u,v,w) and addedge(v,u,w)
            Graph(int x) {n=x;}
};

void Graph::addedge(int u,int v)
{
    adj[u].push_back(v);
   //adj[v].push_back(u);                           //remove " // " for undirected
}
void edgevisit(Graph G,int u,bool visited[],int start[],int end[],int parent[],col color[])
{   visited[u]=true;

    color[u]=grey;

    tr(G.adj[u],it)
    {    if (color[*it]==white)
        {    cout<<u<<"->"<<(*it)<<" tree edge\n";
             parent[*it]=u;                   //done in prev dfs
             edgevisit(G,(*it),visited,start,end,parent,color);
        }

        else if (color[*it]==grey)
            {   cout<<u<<"->"<<(*it)<<" back "<<endl;
                //if ((*it)!=parent[u])     //for undirected
                  //  cout<<u<<"->"<<(*it)<<" back "<<endl;;
            }
        else  if (color[*it]=black)
            {
             if (start[*it]>=start[u]&&end[*it]<=end[u])
                cout<<(u)<<"->"<<(*it)<<" is a forward edge\n";
             else if (start[*it]>=end[u]||end[*it]<=start[u])
                cout<<(u)<<"->"<<(*it)<<" is a cross edge\n";
             else ;

            }
        else ;


    }
    color[u]=black;
}
void edge(Graph G,int start[],int end[],int parent[])
{
   bool visited[G.n];
   for(int i=0;i<G.n;i++)
        visited[i]=false;

    col color[G.n];

    for(int i=0;i<G.n;i++)
        {
            color[i]=white;
        }
   for (int u=0;u<G.n;u++ )
        if  (color[u]==white)
            {
                edgevisit(G,u,visited,start,end,parent,color);
            }
}
void dfs_visit(Graph G,int u,int& time,bool visited[],int start[],int end[],int parent[],list<int> &topolist)
{
    time+=1;
    visited[u]=true;
    start[u]=time;
    tr(G.adj[u],it)
    {
        if (!visited[*it])
        {
           parent[*it]=u;
           dfs_visit(G,(*it),time,visited,start,end,parent,topolist);
        }
    }
    time+=1;
    end[u]=time;
    topolist.push_front(u);
}

void dfs(Graph G)
{
    bool visited[G.n];
    for(int i=0;i<G.n;i++)
        visited[i]=false;
    int time=0;
    int start[G.n],end[G.n],parent[G.n];
    list<int> topolist;
    for (int u=0;u<G.n;u++ )
        parent[u]=u;
    for (int u=0;u<G.n;u++ )
        if  (!visited[u])
            {
                dfs_visit(G,u,time,visited,start,end,parent,topolist);
            }

    for (int u=0;u<G.n;u++ )
        cout<<u<<" "<<start[u]<<" "<<end[u]<<" "<<parent[u]<<endl;

    tr(topolist,it)
    {
        cout<<(*it)<<"->";
    }
    cout<<endl;
    edge(G,start,end,parent);     //function call for edge classification
}
  void printcycle(int v,int u,int parent[])
{
    do
        {
            cout<<v<<" ";
            v=parent[v];
        }while(u!=v);
    cout<<u<<endl;
}

bool cycle_visit(Graph G,int u,bool visited[],int parent[],col color[])
{

    visited[u]=true;

    color[u]=grey;
    tr(G.adj[u],it)
    {   if (color[*it]==grey)
            {
                //if ((*it)!=parent[u])     //for undirected
                  //  return true;
               printcycle(u,(*it),parent);
                return true;              //for directed
            }
        if (color[*it]==white)
        {
           parent[*it]=u;
           return(cycle_visit(G,(*it),visited,parent,color));
        }

    }
    color[u]=black;
    return false;

}
bool hascycle(Graph G)
{
    bool visited[G.n];
    col color[G.n];
    int parent[G.n];
    for (int u=0;u<G.n;u++ )
        parent[u]=u;

    for(int i=0;i<G.n;i++)
        {
            visited[i]=false;
            color[i]=white;
        }


    for (int u=0;u<G.n;u++ )
        if  (color[u]==white)
            {
                if  (cycle_visit(G,u,visited,parent,color))
                    return true;
            }

    return false;

}


int main()
{
    cout<<"n"<<endl;
    int n;
    cin>>n;
    Graph G(n);
    int m;
    cout<<"m"<<endl;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        G.addedge(u,v);
    }
    dfs(G);
    hascycle(G);
    return 0;
}
