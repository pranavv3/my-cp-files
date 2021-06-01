#include<bits/stdc++.h>
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define int long long
using namespace std;

int inf=10e10;
int t[4*200000]; //maxn.

//refer EDU codes/CSES codes... for things like assign+range add, etc.
//I also have a lazy_segment.cpp file.
//Eg: CSES Range Update Queries (sum to range)
//v=1 (root of seg tree), tl=0, tr=n-1, fixed in all queries.

//1. Sum Query
/*void build(int *a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}
int query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return query(v*2, tl, tm, l, min(r, tm))
           + query(v*2+1, tm+1, tr, max(l, tm+1), r);
}
void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}*/
//2. Max query / Min Query.

void build(int *a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = max(t[v*2], t[v*2+1]);
    }
}
int query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        //return 0; (for max query, sum query, GCD query).
        //IN CASE OF MINIMUM QUERY:: RETURN INF. Or else won't work.
        //IN CASE OF MAXIMUM QUERY:: RETURN -INF. (if all elem's -ve...).
        return -inf;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return max(query(v*2, tl, tm, l, min(r, tm)),
                query(v*2+1, tm+1, tr, max(l, tm+1), r));
}
void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = max(t[v*2], t[v*2+1]);
    }
}
int32_t main()
{

    IOS;
    int n; cin>>n;
    int a[n];
    for (int i=0; i<n; i++) {
        cin>>a[i];
    }
    build(a, 1, 0, n-1);
    cout<<query(1, 0, n-1, 3, 6)<<endl;
    cout<<query(1, 0, n-1, 4, 5)<<endl;
    cout<<query(1, 0, n-1, 2, 6)<<endl;
    cout<<query(1, 0, n-1, 5, 5)<<endl;
	return 0;
}
