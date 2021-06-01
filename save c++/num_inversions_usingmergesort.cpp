#include<bits/stdc++.h>
#define ll long long
#define l long
#define m9 1000000007
#define pb push_back
#define mp make_pair
#define f first
#define ss second
const int N = 10e5 + 5;
int maxx = 10e6;
using namespace std;

int inf=10e9; //grtr than max element.
int merge1(int* a, int p, int q, int r) {
    int inv=0;
    int b[q-p+1], c[r-q+2];
    for (int i=p; i<q; i++) {
        b[i-p]=a[i];
    }
    b[q-p]=inf;
    for (int i=q; i<=r; i++) {
        c[i-q]=a[i];
    }
    c[r-q+1]=inf;
    int i=0, j=0; //counters
    for (int k=p; k<=r; k++) {
        if (b[i]<=c[j]) {
            a[k]=b[i];
            i++;
        }
        else {
            a[k]=c[j];
            j++;
            inv+=(q-p-i);
        }
    }
    return inv;
}
int merge_sort(int* a, int p, int r) {
    int inv=0;
    if (p>=r) {
        return 0;
    }

    int q=(p+r)/2;

    inv+=merge_sort(a, p, q);
    inv+=merge_sort(a, q+1, r);

    inv+=merge1(a, p, q+1, r);
    return inv;
}

int main() {
    int n; cin>>n;
    string s; cin>>s;
    int final_pos[n]; //final posn of each element.
    vector<int>poss[26];
    int tracker[26];
    for (int i=0; i<26; i++) {
        tracker[i]=0;
    }
    for (int i=0; i<n; i++) {
        poss[s[i]-'a'].pb(i);
    }
    int j=0;
    for (int i=n-1; i>=0; i--) {
        if(poss[s[i]-'a'].size()>1) {
            final_pos[poss[s[i]-'a'][tracker[s[i]-'a']]]=j;
            tracker[s[i]-'a']++;
        }
        else {
            final_pos[i]=j;
        }
        j++;
    }

    cout<<merge_sort(final_pos, 0, n-1)<<endl;

    return 0;
}
