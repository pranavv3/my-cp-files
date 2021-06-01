#include<bits/stdc++.h>
#define MOD 1000000007
#define MOD2 998244353
#define pb push_back
#define mp make_pair
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define N 20000001
#define M 1001
#define int long long //:( (KS). VVI:: USE 1LL.
#define float long double
using namespace std;
vector<vector<int>>adj;
vector<vector<int>>revadj;
vector<int>lst;
vector<int>visited;
vector<int>comp;
void dfs(int u) {
    visited[u]=true;
    for (int v: adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
    lst.pb(u);
}
void dfs2(int u, int c) {
    visited[u]=true;
    for (int v: revadj[u]) {
        if (!visited[v]) {
            dfs2(v, c);
        }
    }
    comp[u]=c;
}
int32_t main()
{
    IOS;
    int n, m; cin>>n>>m;
    adj=vector<vector<int>>(n);
    revadj=vector<vector<int>>(n);
    for (int i=0; i<m; i++) {
        int a, b; cin>>a>>b; a--; b--;
        adj[a].pb(b);
        revadj[b].pb(a);
    }
    visited=vector<int>(n, false);
    for (int i=0; i<n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    reverse(lst.begin(), lst.end());
    visited=vector<int>(n, false);
    comp=vector<int>(n, 0); //assign components to all.
    int num_comp=0;
    bool strongly_connected=true;
    for (int i=0; i<n; i++) {
        if (!visited[lst[i]]) {
            num_comp++;
            dfs2(lst[i], num_comp);
            if (i!=0) {
                strongly_connected=false; //graph not strongly connected
            }
        }
    }


	return 0;
}

