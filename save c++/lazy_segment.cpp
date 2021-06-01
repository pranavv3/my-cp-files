#include<bits/stdc++.h>
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define int long long
using namespace std;

//1. Sum Query with Range Assign.
int t[4*200000];
bool marked[4*200000];
void build(int *a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}
void push(int v, int tl, int tr) {
    if (marked[v]) {
        int mark_with=t[v]/(tr-tl+1);
        int tm=(tl+tr)/2;
        t[2*v]=mark_with*(tm-tl+1), t[2*v+1]=mark_with*(tr-tm);
        marked[2*v]=true; marked[2*v+1]=true;
        marked[v]=false;
    }
}
int query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    return query(v*2, tl, tm, l, min(r, tm))+
                query(v*2+1, tm+1, tr, max(l, tm+1), r);
}
void update(int v, int tl, int tr, int l, int r, int val) {
    if (l>r) {
        return;
    }
    if (tl==l && tr==r) {
        marked[v]=true;
        t[v]=val*(tr-tl+1);
    } else {
        int tm = (tl + tr) / 2;
        push(v, tl, tr);
        update(2*v, tl, tm, l, min(r, tm), val);
        update(2*v+1, tm+1, tr, max(l, tm+1), r, val);
        t[v]=t[2*v]+t[2*v+1];
    }
}

int32_t main()
{

    n=10;
    int a[10]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    build(a, 1, 0, n-1);

    update(1, 0, n-1, 0, 4, 1);
    update(1, 0, n-1, 7, 9, 3);
    update(1, 0, n-1, 3, 7, 7);

    cout<<query(1, 0, n-1, 0, 9)<<endl;
    cout<<query(1, 0, n-1, 3, 6)<<endl;
    cout<<query(1, 0, n-1, 0, 2)<<endl;
    cout<<query(1, 0, n-1, 3, 5)<<endl;
    for (int i=0; i<4*n; i++) {
        cout<<t[i]<<" ";
    }
    cout<<endl;

	return 0;
}
