#include<bits/stdc++.h>
#define MOD 1000000007
#define MOD2 998244353
#define pb push_back
#define mp make_pair
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define N 20000001
#define M 1001
//#define int long long //:( (KS).
#define float long double
using namespace std;

int n;
vector<vector<int>> adj;
vector<int>state; //0 (unprocessed), 1 (under processing), 2 (processed).
vector<int> ans;
bool exists;
void dfs(int v) {
    state[v]=1;
    for (int u : adj[v]) {
        if (!state[u])
            dfs(u);
        else
            if (state[u]==1)
                exists=false;
    }
    state[v]=2;
    ans.push_back(v);
}
void topological_sort() {
    state.assign(n, 0);
    ans.clear();
    exists=true;
    for (int i = 0; i < n; ++i) {
        if (!state[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
}

int32_t main()
{
    int m; cin>>n>>m;
    adj=vector<vector<int>>(n);
    for (int i=0; i<m; i++) {
        int a, b; cin>>a>>b;
        a--; b--;
        adj[a].pb(b);
    }
    topological_sort();
    if (!exists) {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else {
        for (int v: ans) {
            cout<<v+1<<" ";
        }
        cout<<endl;
    }

	return 0;
}
