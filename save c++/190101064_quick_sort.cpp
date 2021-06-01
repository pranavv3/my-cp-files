#include<bits/stdc++.h>

using namespace std;

void swap(int *a, int* b) {
    int t=*a;
    *a=*b;
    *b=t;
}

//pass array by reference.
int part(int *a, int st, int e) {
    //partitions to 2 parts, lesser and greater than pivot.
    int pivot=a[e];
    int ptr=st-1;
    for (int i=st; i<e; i++) {
        if (a[i]<=pivot) {
            ptr++;
            swap(&a[ptr], &a[i]);
        }
    }
    swap(&a[ptr+1], &a[e]);
    return ptr+1;
}

void qs(int *a, int st, int e) {
    if (st>=e) { //st<e.
        return;
    }
    int mid=(st+e)/2; //floor,
    swap(&a[mid], &a[e]);
    int q = part(a, st, e);
    //partitions to 2 parts, lesser and greater than pivot.
    //The quick sort on 2 partitions, recursively.

    qs(a, st, q-1); //quick sort on 2 divided subarrays.
    qs(a, q+1, e);
}
int main()
{
    int n; cin>>n;
    int a[n];
    for (int i=0; i<n; i++) {
        cin>>a[i];
    }
    qs(a, 0, n-1);
    for (int i=0; i<n; i++) {
        cout<<a[i]<<" ";
    }
    return 0;
}
