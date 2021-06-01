#include<iostream>

//MERGE SORT.

//DON'T use if not neccessary... sometimes we can find inversions in O(n) too.
//eg: array only has 0's and 1's. Got TLE due to merge sort LOL.
using namespace std;

int inf = 10e5; //greater than largest element.

int cnt=0; //number of times merge function is called.
//pass by reference
void merge1(int* a, int p, int q, int r) {
    //merge sorted arrays a[p:q-1] and a[q:r] which are both already sorted.
    cnt++;

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
        }
    }
}
void merge_sort(int* a, int p, int r) {
    if (p>=r) {
        return;
    }

    int q=(p+r)/2;

    merge_sort(a, p, q);
    merge_sort(a, q+1, r);

    merge1(a, p, q+1, r);
}


int main() {
    int n; cin>>n;
    int a[n];
    for (int i=0; i<n; i++) {
        cin>>a[i];
    }
    merge_sort(a, 0, n-1);
    cout<<cnt<<endl;
    for (int i=0; i<n; i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
