#include<bits/stdc++.h>
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

//example: 1213G (my first application of this)
//mistake: getp(a) not []. lol.
//Below: soln. of CSES Road reparation.
//size of component with A:: rk[getp(a)]
vector<int>p,rk;
int getp(int v) {
	if (v == p[v]) return v;
	return p[v] = getp(p[v]);
}
void merge(int u, int v) {
	u = getp(u);
	v = getp(v);
	if (rk[u] < rk[v]) swap(u, v);
	rk[u] += rk[v];
	p[v] = u;
}
int32_t main()
{
    int n, m; cin>>n>>m;
    vector<pair<int, pair<int, int>>>ed;
    rk=vector<int>(n, 1);
    p=vector<int>(n, 0);
    iota(p.begin(), p.end(), 0);
    for (int i=0; i<m; i++) {
        int a, b, c; cin>>a>>b>>c; a--; b--;
        ed.pb(mp(c, mp(a, b)));
    }
    sort(ed.begin(), ed.end());
    int ans=0;
    for (auto e: ed) {
        int a=e.second.first, b=e.second.second;
        int c=e.first;
        if (getp(a)!=getp(b)) {
            merge(a, b);
            ans+=c;
        }
    }
    if (rk[getp(0)]!=n) {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else {
        cout<<ans<<endl;
    }
	return 0;
}
