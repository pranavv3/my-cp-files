#include <bits/stdc++.h>
#define ll long long
#define lll long long
#define mp make_pair
#define pb push_back
ll inf = 1000000000000000000;
#define deci(n) fixed << setprecision(n)
#define vll vector<ll>
#define vpll vector<pair<ll, ll>>
#define umll unordered_map<ll, ll>
#define mll map<ll, ll>
//#define f first
//#define s second
#define mt make_tuple

using namespace std;

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

struct hash_pair
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

ll p = 1e9 + 7;

//*****************CODE STARTS **************************************

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n, m, p; cin >> n >> m >> p;
    ll mx = 0;
    ll msk=-1;
    ll xmsk=-1;

    string s[n];

    for(ll i=0; i<n; i++)cin >> s[i];

    ll e = pow(2, p);
    ll bits[e];
    for(ll i=0; i<e; i++){
        bits[i]=0;
        if(i%2==1)bits[i]++;
        bits[i]+=bits[i/2];
        //cout << bits[i] <<"\n";
    }

   srand(time(0));
   for(ll u=0; u<50; u++){
       ll x=uniform_int_distribution<int>(0, n-1)(rng);
       ll cnt[e], cnd[e];
       for(ll i=0; i<e; i++){cnt[i]=0; cnd[i]=0;}
       for(ll i=0; i<n; i++){
           ll y = 0;
           ll z = 1;
           for(ll j=0; j<m; j++){
               if(s[i][j]=='1' && s[x][j]=='1')y+=z;
               if(s[x][j]=='1')z*=2;
           }
           cnt[y]++;
           //cout << y <<"\n";
       }
        //cout << "masks\n";
       for (int mask = e-1; mask > 0; mask--){

            for(int i = mask; i > 0; i = (i-1) & mask){
    	        cnd[i] += cnt[mask];
            }

            //cout <<mask << " " << cnd[mask] <<"\n";
            if(cnd[mask] >= (n+1)/2){
               if(bits[mask]>=mx){mx=bits[mask]; msk=mask; xmsk=x;}
            }
        }
   }

   //cout << msk << " " << xmsk <<"\n";//
    if(xmsk==-1){
        for(ll i=0; i<m; i++)cout << 0;
    }
   else for(ll i=0; i<m; i++){
       if(s[xmsk][i]=='0')cout << 0;
       else if(msk%2==1){cout << 1; msk/=2;}
       else {cout << 0; msk/=2;}
   }
}

