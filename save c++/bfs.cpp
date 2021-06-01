#include<bits/stdc++.h>
#define ll long long
#define l long
#define m9 1000000007
#define pb push_back
#define mp make_pair

#define s second
const int cc = 2*10e5;
const double pi = 3.14159265358979323846;
using namespace std;


//int parent[100000]; //in case want to print shortest path.\

//For BFS don't need a function necessarily. As not recursive.
const int INF=1e9;
vector<vector<int>>a;
void bfs (int k, vector<int>&d) {
    queue<int>q;
    q.push(k);
    d[k]=0;
    while(!q.empty()) {
        int s=q.front(); q.pop();
        for (auto u: a[s]) {
            if (d[u]==INF) {
                dist[u]=dist[s]+1;
                q.push(u);
            }
        }
    }
}
int main()
{

    /*BFS Without stupid function needed*::
    vector<int>dist(n, INF1);
        queue<int>q;
        q.push(0);
        dist[0]=0;
        while (!q.empty()) {
            int x=q.front();
            q.pop();
            for (auto y: adj[x]) {
                if (dist[y]!=INF1) {
                    continue;
                }
                dist[y]=dist[x]+1;
                q.push(y);

            }
        }/*
    int n, m;
    cin>>n>>m;
    a=vector<vector<int>>(n);

    //distance vector. Initialize to INF.
    vector<int>d(n, INF);
    for (int i=0; i<m; i++) {
        int x, y; cin>>x>>y;
        x--; y--;
        a[x].pb(y);
        a[y].pb(x);
    }
    bfs(0, d);

    //ALSO:: MULTISOURCE BFS:: (Minimum distance of each vertex from sources).

    /*  queue<int>q;
        vector<int>d(n, -1);
        for (auto v: sources) {
            d[v]=0;
            q.push(v);
        }
        while (!q.empty()) {
            int v=q.front();
            q.pop();
            for (auto to: g[v]) {
                if (d[to]==-1) {
                    d[to]=d[v]+1;
                    q.push(to);
                }
            }
        }*/

}

//ALTERNATE VERSION
/*
#include<bits/stdc++.h>
#define ll long long
#define l long
#define m9 1000000007
#define pb push_back
#define mp make_pair

#define s second
const int cc = 2*10e5;
const double pi = 3.14159265358979323846;
using namespace std;

bool visited[100000];
int n, m;
vector<int>a[100000];
int dist[100000];
queue<int>q;
int parent[100000]; //in case want to print shortest path.

void bfs (int k) {
    visited[k]=true;
    q.push(k);
    dist[k]=0;
    while(!q.empty()) {
        int s=q.front(); q.pop();
        for (auto u: a[s]) {
            if (!visited[u]) {
                visited[u]=true;
                dist[u]=dist[s]+1;
                q.push(u);
            }
        }
    }
}
int main()
{

    cin>>n>>m;
    for (int i=0; i<m; i++) {
        int x, y; cin>>x>>y;
        x--; y--;
        a[x].pb(y);
        a[y].pb(x);
    }
    bfs(0);

}
*/
