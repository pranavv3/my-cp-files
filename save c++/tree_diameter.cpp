#include<bits/stdc++.h>
#define ll long long
#define l long
#define m9 1000000007
#define pb push_back
#define mp make_pair

const int cc = 2*10e5;
const double pi = 3.14159265358979323846;
using namespace std;

vector<int>p;
vector<vector<int>>g;

//<furthest distance, furthest distance vertex> //For tree diameter.
pair<int, int>dfs (int v, int par=-1, int dist=0) {
    p[v]=par;
    pair<int, int>res = mp(dist, v);
    for (auto to: g[v]) {
        if (to!=par) {
            res=max(res, dfs(to, v, dist+1));
        }
    }
    return res;
}
int main()
{
    int n; cin>>n;
    p=vector<int>(n);
    g=vector<vector<int>>(n);
    for (int i=0; i<n-1; i++) {
        int x, y; cin>>x>>y; x--; y--;
        g[x].pb(y);
        g[y].pb(x);
    }
    pair<int, int>da=dfs(0);
    pair<int, int>db=dfs(da.second);

    //all parents modified in second dfs, so no need to worry.
    //with one end of diameter as root.
    vector<int>diam;
    int v=db.second;
    while (v!=da.second) {
        diam.pb(v);
        v=p[v];
    }
    diam.pb(da.second);


    return 0;
}
