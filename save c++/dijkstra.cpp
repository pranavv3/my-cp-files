#include<bits/stdc++.h>
#define ll long long
#define l long
#define m9 1000000009
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

int main()
{
    ll inf=10e16;
    ll n, m; cin>>n>>m;

    vector<pair<ll, ll>>adj[n];
    for (ll i=0; i<m; i++) {
        ll a, b, w; cin>>a>>b>>w;
        a--; b--;
        adj[a].pb({b, w});
        //adj[b].pb({a, w}); //if one way connection, don't include this.
        //(djikstra can be used for directed graphs too).
    }

    ll dist[n];
    for (ll i=0; i<n; i++) {
        dist[i]=inf;
    }
    dist[0]=0;
    bool processed[n];
    for (ll i=0; i<n; i++) processed[i]=false;

    ll parent[n];
    parent[0]=-1;
    priority_queue<pair<ll, ll>>q; //(-d, x)
    q.push({0, 0});
    while (!q.empty()) {
        ll a=q.top().second;
        q.pop();
        if (processed[a]) continue;
        processed[a]=true;
        for (auto u: adj[a]) {
           ll b=u.first, w=u.second;
           if (dist[a]+w<dist[b]) {
               dist[b]=dist[a]+w;
               parent[b]=a;
               q.push({-dist[b], b});
           }

        }
    }

    //find if no path...
    if (processed[n-1]==false) {
        cout<<-1<<endl;
    }

    else {
        //Output path 1 to n. (if path exists)
        vector<ll>path;
        path.pb(n-1);
        ll x=n-1;
        while (parent[x]!=-1) {
            path.pb(parent[x]);
            x=parent[x];
        }
        for (ll i=path.size()-1; i>=0; i++) {
            cout<<path[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
