#include<bits/stdc++.h>
#define ll long long
#define l long
#define m9 1000000007
#define pb push_back
#define mp make_pair
const ll N = 10e5 + 5;
ll inf=10e5;
using namespace std;

vector<int>a[100000];
int visited[100000];

int cnt=0;

void dfs(int k, int layer) {
    if (!visited[k]) {
        visited[k]=1;
        if (layer%2==0) {
            cnt++; //black node.
        }
        for (auto x: a[k]) {
            dfs(x, layer+1);
        }
    }
}
int main() {
    int n; cin>>n;
    //nill = n+1.
    int root;
    for (int i=0; i<n; i++) {
        int keyy, left_child, right_child;
        cin>>keyy>>left_child>>right_child;
        if (i==0) {
            root=keyy;
        }
        if (left_child!=0) {
            a[keyy-1].pb(left_child-1);
        }
        if (right_child!=0) {
            a[keyy-1].pb(right_child-1);
        }
    }
    dfs(root-1, 0);

    //cnt is number of black nodes other than NILL nodes. There are n+1 nill nodes.
    cout<<cnt+n+1<<endl;
    return 0;
}
