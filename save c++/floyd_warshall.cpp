#include<bits/stdc++.h>
#define ll long long
#define l long
#define MOD 1000000009
#define pb push_back
#define mp make_pair
#define f first
#define s second

//pretty straightforward implementation of Floyd Warshall.
ll inf = 10e12;
using namespace std;
void gs(int x) {
    //cout<<"GREAT SUCCESS"<<x<<endl;
}
int main() {
    int n, m; cin>>n>>m //n vertices, m edges.
    int dist[n][n];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            dist[i][j]=inf;
            if (i==j) {
                dist[i][j]=0;
            }
        }
    }
    for (int i=0; i<m; i++) {
        int a, b;
        int c;
        cin>>a>>b>>c;
        dist[a-1][b-1]=c;
        dist[b-1][a-1]=c; //if undirected graph.

    }
    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (dist[i][j]>dist[i][k]+dist[k][j]) {
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }

    return 0;
}
