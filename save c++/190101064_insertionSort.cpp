#include<iostream>

//Refer class notes.
using namespace std;

int main() {
    int n; cin>>n;
    int a[n];
    for (int i=0; i<n; i++) {
        cin>>a[i];
    }

    for (int i=1; i<n; i++) {
        int temp=a[i];
        for (int j=i-1; j>=0; j--) {
            if (a[j]<=temp) {
                a[j+1]=temp;

                break;
            }
            else {
                a[j+1]=a[j];
                if (j==0) {
                    a[0]=temp;
                }
            }
        }



    }
    for (int k=0; k<n; k++) {
            cout<<a[k]<<" ";
        }
    cout<<endl;
    return 0;
}

