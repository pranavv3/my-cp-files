#include<bits/stdc++.h>
#define ll long long
#define l long
#define m9 1000000009
#define pb push_back
#define mp make_pair
#define f first
#define s second
const int N = 10e5 + 5;

using namespace std;

int n;
vector<int>a[100000];
int visited[100000]; //global variable, default everything initialized to 0


void dfs(int k) {
    if (!visited[k]) {
        visited[k]=1;
        for (auto x: a[k]) {
                dfs(x);
        }

    }
}
/*
//cycle detection:
void dfs(int k, int prev) {
    if (!visited[k]) {
        visited[k]=1;
        for (auto x: a[k]) {
            if (!visited[x]) {
                dfs(x, k);
            }
            else {
                if (x!=prev) {
                    cycle_poss=true;
                }
            }
        }
    }
}

*/
int main()
{

    cin>>n;
    for (int i=0; i<n-1; i++) {
        int p, q; cin>>p>>q;
        a[p-1].pb(q-1);
        a[q-1].pb(p-1);
    }

    dfs(0);
    for (int i=0; i<n; i++) {
        a[i].clear(); //clear
        visited[i]=0; //reset
    }

    return 0;
}

