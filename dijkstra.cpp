#include <bits/stdc++.h>
using namespace std;

 typedef long long int lli;
 typedef vector<int> vi;
 typedef vector<long long int> vlli;
 typedef vector<vi> vvi;
 typedef pair<int,int> ii;
 #define all(c) (c).begin(),(c).end()
 //#define tr(c,it) for((typeof((c).begin())) it = (c).begin(); it != ((c).end()); it++)
#define tr(container, it)  for(typeof((container).begin()) it = container.begin(); it != container.end(); it++)



 typedef struct{
 lli node;
 lli distance;
 }vertex;

 class compare{
public: bool operator()(vertex v1,vertex v2)
        {
            if (v1.distance>v2.distance)
                return true;
            else return false;
        }
 };

 class Graph{
   public:  lli n;

            vector<lli> dist= vector<lli> (n,INT_MAX);            //distance array considering dijkstra
            vector< list<vertex> > adj= vector< list<vertex> > (n);
            void addedge(int u,int v,int w);                     //for undirected use addedge(u,v,w) and addedge(v,u,w)
            Graph(int x) {n=x;}

            void dijkstra(lli s);
            //void bfs(int s);


};

void Graph::addedge(int u,int v,int w)
{   vertex tmp;
    tmp.node=v;
    tmp.distance=w;
    adj[u].push_back(tmp);
    tmp.node=u;
    adj[v].push_back(tmp);                           //remove " // " for undirected
}


void Graph::dijkstra(lli s)
{   compare cmp;
    bool visited[n+1];
    for(int i=1;i<=n;i++)
        visited[i]=false;
    priority_queue<vertex,vector<vertex>,compare> pq;
    vertex first = {s,1};
    pq.push(first);
    dist[s]=0;
    while(pq.size())
    {

        vertex u = pq.top();
        pq.pop();

        lli node= u.node;
        //(typeof((adj[node]).begin())) it;


        tr(adj[node],it)
        {


                // Update the distance if it is smaller than the current distance
                if(dist[((*(it))).node] > (dist[node]+(((*(it))).distance)))
                    dist[((*(it))).node] = dist[node]+(((*(it))).distance);

                // If not visited put it into the queue
                if(!visited[(*(it)).node])
                {
                    vertex newNode;
                    newNode.node=(*(it)).node;
                    newNode.distance=dist[(*(it)).node];
                    pq.push(newNode);
                    visited[(*(it)).node]=true;
                }

        }


    }
    for(lli i=1;i<=n;i++)
        cout<<i-1<<" "<<dist[i]<<endl;


}

int main()
{   // create the Graph given in above fugure
    int V = 9;
    Graph g(V);

    //  making above shown Graph
    g.addedge(1, 2, 4);
    g.addedge(1, 8, 8);
    g.addedge(2, 3, 8);
    g.addedge(2, 8, 11);
    g.addedge(3, 4, 7);
    g.addedge(3, 9, 2);
    g.addedge(3, 6, 4);
    g.addedge(4, 5, 9);
    g.addedge(4, 6, 14);
    g.addedge(5, 6, 10);
    g.addedge(6, 7, 2);
    g.addedge(7, 8, 1);
    g.addedge(7, 9, 6);
    g.addedge(8, 9, 7);

    g.dijkstra(1);


    return 0;
}
