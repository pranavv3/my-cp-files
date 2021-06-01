#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define MOD 1000000007
#define MOD2 998244353
#define pb push_back
#define pf push_front
#define mp make_pair
#define mt make_tuple
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define int long long
#define sz(a) (int)((a).size()) //always use.
using namespace std;
using namespace __gnu_pbds;
ll inverse(ll i){ //pass value <MOD LOL.
    if(i==1) return 1;
    return (MOD - ((MOD/i)*inverse(MOD%i))%MOD+MOD)%MOD;
}
ll POW(ll a,ll b)
{
    if(b==0) return 1;
    if(b==1) return a%MOD;
    ll temp=POW(a,b/2);
    if(b%2==0) return (temp*temp)%MOD;
    else return (((temp*temp)%MOD)*a)%MOD;
}
ll fact[300001];
ll f() //call if needed.
{
    fact[0]=1;
    fact[1]=1;
    for(int i=2;i<=300000;i++)
    {
        fact[i]=(fact[i-1]*i)%MOD;
    }
}
ll ncr(ll n,ll r)
{
    ll aa=1;
    aa*=fact[n];
    aa%=MOD;
    aa*=inverse(fact[r]);
    aa%=MOD;
    aa*=inverse(fact[n-r]);
    aa%=MOD;
    return aa;
}

int32_t main()
{
    IOS;
    f();
    int t; cin>>t;
    while (t--) {
        int n, k; cin>>n>>k;
        int ans=0;
        for (int i=1; n-(k-1)*(i-1)>=i; i++) {
            int temp=ncr(n-(k-1)*(i-1), i)*inverse(ncr(n, i));
            temp%=MOD;
            ans+=temp;
            ans%=MOD;
        }
        cout<<(ans+1)%MOD<<endl;
    }

	return 0;
}


//long long overflow.
