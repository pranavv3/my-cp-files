#include<bits/stdc++.h>
#define ll long long
#define l long
#define m9 1000000009
#define pb push_back
using namespace std;

int main()
{
    freopen("C:\\Users\\Pranav\\Desktop\\input.txt","r",stdin);
    freopen("C:\\Users\\Pranav\\Desktop\\output.txt","w",stdout);
    int t; cin>>t;
    int x=1;
    while (t--) {
        long n; cin>>n;
        string s; cin>>s;
        long a=0, b=0;
        for (long i=0; i<n; i++) {
            if (s[i]=='A') {
                a++;
            }
            else {
                b++;
            }
        }
        if (a-b==1 || b-a==1) {
            cout<<"Case #"<<x<<": "<<"Y"<<endl;
        }
        else {
            cout<<"Case #"<<x<<": "<<"N"<<endl;
        }

        x++;
    }

    return 0;
}
