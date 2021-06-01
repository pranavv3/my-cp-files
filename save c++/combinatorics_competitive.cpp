#include<bits/stdc++.h>
#define ll long long
#define l long
#define MOD 1000000007 //important
#define pb push_back
#define mp make_pair
#define f first
#define s second

//combinatorics and math.
using namespace std;
void gs() {
    cout<<"GREAT SUCCESS"<<endl;
}
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

//More Math::
ll modI(ll a, ll m) //mod inverse using Extended Euclidean Algorithm. O(log M).
{
    //if m prime: FLT.
    //if need to solve ax = b(mod m).
    //multiply both sides by a^-1, have found solution set (mod m).
    //if gcd(a, m)>1:: b must divide gcd(a, m) for solution. But ModI won't exist if not coprime.
    //so solve (a/d)x = (b/d) mod (m/d).

    //Complexity: O(log m).
    //Also, pre calculation for all a might help avoid complexity O(logn)^2 in some cases...

    ll m0=m,y=0,x=1;
    if(m==1) return 0;
    while(a>1)
    {
        ll q=a/m;
        ll t=m;
        m=a%m;
        a=t;
        t=y;
        y=x-q*y;
        x=t;
    }
    if(x<0) x+=m0;
    return x;
}
int gcd(int a, int b, int& x, int& y) { //returns one solution of ax+by=gcd(a, b).
    //refer cp-alrogithms article for much more depth, and other uses/templates.
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

//n'th fib in O(logn): refer CSES code.
//Matrix Exp::
int m; //dimension of matrix.
vector<vector<int>>mul(vector<vector<int>>x, vector<vector<int>>y) {
    vector<vector<int>>r(m, vector<int>(m, 0));
    for (int j=0; j<m; j++) {
        for (int k=0; k<m; k++) {
            for (int l=0; l<m; l++) {
                r[j][k]=(r[j][k]+(x[j][l]*y[l][k])%MOD)%MOD;
            }
        }
    }
    return r;
}
vector<vector<int>>modpow(vector<vector<int>>x, int n) {
    if (n==0) {
        vector<vector<int>>r(m, vector<int>(m, 0));
        for (int i=0; i<m; i++) r[i][i]=1;
        return r;
    }
    vector<vector<int>>u=modpow(x, n/2);
    u=mul(u, u);
    if (n%2==1) u=mul(u, x);
    return u;
}

//solving Ax=b.
//a: system matrix, last column of this matrix is vector b.
//Return 0: no solution, 1: one solution, 2: infinite solutions.
//If 1 solution, return it in ans vector.
//Time complexity:: O(n*m*min(n, m)). if n=m:: O(n^3).
//cp-algoirthm:: original was double not int. replace...
//Below code:: When system, with modulo. If don't want modulo or want double:: Copy from cp-algorithms.
ll inverse(ll i){ //pass value <MOD LOL.
    if(i==1) return 1;
    return (MOD - ((MOD/i)*inverse(MOD%i))%MOD+MOD)%MOD;
}
const double EPS = 1e-9;
int gauss (vector < vector<int> > a, vector<int> & ans) {
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;

    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i)
            if (abs (a[i][col]) > abs (a[sel][col]))
                sel = i;
        if (abs (a[sel][col]) < EPS)
            continue;
        for (int i=col; i<=m; ++i)
            swap (a[sel][i], a[row][i]);
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row) {
                int c = a[i][col]*inverse(a[row][col])%MOD;
                for (int j=col; j<=m; ++j) {
                    a[i][j] -= (a[row][j] * c %MOD);
                    if (a[i][j]<0) a[i][j]+=MOD;
                }
            }
        ++row;
    }

    ans.assign (m, 0);
    for (int i=0; i<m; ++i)
        if (where[i] != -1)
            ans[i]=a[where[i]][m] * inverse(a[where[i]][i]) %MOD;
    for (int i=0; i<n; ++i) {
        int sum = 0;
        for (int j=0; j<m; ++j)
            sum += ans[j] * a[i][j];
            sum%=MOD;
        if (abs (sum - a[i][m]) > EPS)
            return 0;
    }

    for (int i=0; i<m; ++i)
        if (where[i] == -1)
            return 2;
    return 1;
}



int main() {

    return 0;
}
