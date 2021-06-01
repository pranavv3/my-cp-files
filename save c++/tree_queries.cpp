#include<bits/stdc++.h>
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
using namespace std;

//FOR FINDING LCA or k'th ancestor or DIST.
int n, l;
vector<vector<int>> adj;
int timer;
vector<int> tin, tout;
vector<vector<int>> up;
vector<int>depth;

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p; //HMMM... //in this implementation, have made ancestor of root itself. NEAT.
    for (int i = 1; i <= l; ++i) {
        up[v][i] = up[up[v][i-1]][i-1];
    }
    depth[v]=depth[p]+1;
    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}
bool is_ancestor(int u, int v)
{
    //u ancestor of v.
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}
int find_ancestor (int x, int k) {
    //k'th ancestor of x.
    if (depth[x]<=k) {
        return -1;
    }
    int lim=pow(2, l);
    int curr=k;
    int curr_node=x;
    for (int i=l; i>=0; i--) {
        if (curr>=lim) {
            curr-=lim;
            curr_node=up[curr_node][i];
        }
        lim/=2;
    }
    return curr_node+1; //or curr_node of 0-based.
}

int dist (int a, int b) {
    int x = lca(a, b);
    return depth[a]+depth[b]-2*depth[x];
}
void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    depth=vector<int>(n, 0);
    timer = 0;
    l = ceil(log2(n));
    up=vector<vector<int>>(n, vector<int>(l+1));
    dfs(root, root);
}
int32_t main()
{

    IOS;
    cin>>n;
    adj=vector<vector<int>>(n);
    int q; cin>>q;
    for (int i=0; i<n-1; i++) {
        int x, y; cin>>x>>y;
        x--; y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    preprocess(0);
    while (q--) {
        int x, y; cin>>x>>y;
        x--; y--;
        cout<<dist(x, y)<<endl;
    }

	return 0;
}
