#include<bits/stdc++.h>
#define ll long long
#define l long
#define m9 1000000007
#define pb push_back
#define mp make_pair
const ll N = 10e5 + 5;
ll inf=10e5;
using namespace std;

void ins_sort(int *a, int gap_len, int n) {
    for (int start=0; start<gap_len; start++) {
        //starting index for insertion sort.
        //apply insertion sort on a[start], a[start+gap]...
        for (int i=start+gap_len; i<n; i+=gap_len) {
            int temp=a[i];
            for (int j=i-gap_len; j>=start; j-=gap_len) {
                if (a[j]<=temp) {
                    a[j+gap_len]=temp;
                    break;
                }
                else {
                    a[j+gap_len]=a[j];
                    if (j==start) {
                        a[start]=temp;
                    }
                }
            }
        }
    }
}
int main() {
    int n; cin>>n;
    int a[n];
    for (int i=0; i<n; i++) {
        cin>>a[i];
    }
    int gap_size; cin>>gap_size;
    int g[gap_size];
    for (int i=0; i<gap_size; i++) {
        cin>>g[i];
    }
    for (int i=0; i<gap_size; i++) {
        ins_sort(a, g[i], n);
        for (int j=0; j<n; j++) {
            cout<<a[j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
