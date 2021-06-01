#include<bits/stdc++.h>
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define int long long
using namespace std;

//MISTAKE I MADE IN CSES PROBLEM:: GRAPH CAN BE DISCONNECTED TOO... (VVI). General point to keep in mind for graph problems.
// CYCLE CAN BE IN ANOTHER SEGMENT NOT CONTAINING NODE 0.

//https://cp-algorithms.com/graph/finding-cycle.html
//Above implementation is better.

//For directed graph: my CSES solution (which is copied from cp-algorithms site).

vector<vector<int>>adj;
vector<int>visited;
vector<int>curr_active;
bool cycle_found=false;
void dfs (int x, int prev) {
    if (cycle_found) {
        return;
    }
    visited[x]=true;
    curr_active.push_back(x);
    for (int k: adj[x]) {
        if (cycle_found) {
            return;
        }
        if (!visited[k]) {
            dfs(k, x);
        }
        else {
            if (k!=prev) {
                curr_active.push_back(k);
                cycle_found=true;
                return;
            }
        }
    }
    if (cycle_found) {
        return;
    }
    curr_active.pop_back();
}
int32_t main()
{
    IOS;
    int n, m; cin>>n>>m;
    adj=vector<vector<int>>(n);
    visited=vector<int>(n, 0);
    for (int i=0; i<m; i++) {
        int a, b; cin>>a>>b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for (int i=0; i<n; i++) {
        if (!visited[i]) {
            dfs(i, -1);
        }
        if (cycle_found) {
            break;
        }
    }
    if (!cycle_found) {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else {
        vector<int>cycle;
        cycle.push_back(curr_active.back());
        for (int i=curr_active.size()-2; i>=0; i--) {
            cycle.push_back(curr_active[i]);
            if (cycle.back()==cycle[0]) {
                break;
            }
        }
        cout<<cycle.size()<<endl;
        for (int node: cycle) {
            cout<<node+1<<" ";
        }
        cout<<endl;
    }
	return 0;
}
