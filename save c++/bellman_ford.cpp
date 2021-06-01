#include<bits/stdc++.h>
#define MOD 1000000007
#define MOD2 998244353
#define pb push_back
#define mp make_pair
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define N 20000001
#define M 1001
#define int long long //:( (KS).
#define float long double
using namespace std;

//Clean bellman ford implementation.
//This is the code for CSES: Find and output a negative cycle in a graph.

struct edge {
    int a, b, cost;
};
int n, m;
vector<edge>edges;
ll inf = 10e14;

void solve() {
    vector<int>d(n, inf);
    vector<int>p(n, -1);
    int x;
    for (int i=0; i<n; i++) {
        x=-1;
        for (edge e: edges) {
            if (d[e.a]+e.cost<d[e.b]) {
                d[e.b]=d[e.a]+e.cost;
                p[e.b]=e.a;
                x=e.b;
            }
        }
        if (x==-1) {
            break; //to speed up things. If no cycle found in current iteration, won't be found later too.
        }
    }
    //x: any node that is updated.
    if (x==-1) {
        //last iteration: no update. No negative cycle found.
        cout<<"NO"<<endl;
    }
    else {
        cout<<"YES"<<endl;

        //n times:: I definitely get to a node which is part of the cycle.
        //IMP.
        for (int i=0; i<n; i++) {
            x=p[x];
        }
        vector<int>cycle;
        for (int v=x; true ;v=p[v]) {
            cycle.push_back(v);
            if (v==x && cycle.size()>1) {
                break;
            }
        }
        reverse(cycle.begin(), cycle.end());
        for (int v: cycle) {
            cout<<v+1<<" ";
        }
        cout<<endl;
    }
}
int32_t main()
{
    cin>>n>>m;
    for (int i=0; i<m; i++) {
        int a, b, cost; cin>>a>>b>>cost;
        a--; b--;
        edge e = {a, b, cost};
        edges.push_back(e);
    }
    solve();
    return 0;
}
