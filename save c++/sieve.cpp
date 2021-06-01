#include<bits/stdc++.h>
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define N 20000005
#define int long long
using namespace std;

//IMP:: No using sieve for no reason!
//eg:: 1334E:: D, D<=10^15. Only 1 test case.
//need primes, <=sqrt(10^15), which are divisors of 10^15.
//Problem was O(n*num_primes) with sieve method:: means something is wrong.
//just to loop 2 to sqrt(D) and find prime divisors one by one simple. Atmost 55 of them, so complexity greatly reduced.
vector<int>primes;
void sieve(int n) { //COMMON MISTAKE:: Pass sqrt(MAXN), not MAXN.
    vector<bool>prime(n);
    for (int i=0; i<n; i++) {
        prime[i]=true;
        if (i>2 && !(i%2)) {
            prime[i]=false;
        }
    }
    for (int p=3; p<=sqrt(n); p+=2) {
        if (prime[p] == true) {
            for (int i=p*p; i<n; i += p)
                prime[i] = false;
        }
    }
    prime[0]=false; prime[1]=false;
    for (int i=2; i<n; i++) {
        if (prime[i]) {
            primes.pb(i);
        }
    }
}

//Linear sieve uses too much memory though. (array of ints not bools).
//SPF is amazing!!! can check if number prime/composite, can calculate greatest divisor and lot of other stuff.
int spf[N]; //smallest prime factor.
int numpf[N];
//USE LINEAR SIEVE IF OF ORDER 10e7. 10e7 ---> reminded of this.
vector<int>pr;
void linear_sieve(int n) {//1499D in 700ms. (N=2*10e7). Also used in 1512G.
    for (int i=2; i<=n; i++) {
        if (spf[i]==0) {
            spf[i]=i;
            pr.pb(i);
        }
        for (int j=0; j<pr.size() && pr[j]<=spf[i] && i*pr[j]<=N; j++) {
            spf[i*pr[j]]=pr[j];
        }
    }
}

//below is alternative to numpf array. it's slower, so I didn't use it for 1499D.
/*int primeFactor(int n){ //tweak as needed.
    int val=0;
    while(n>1){
        int x = spf[n];
        int c=0;
        while(n%x==0){
            c++;
            n/=x;
        }
        val++;
    }
    return val; //num. unique PF.
}*/

//For DP problems, where subproblems involve divisors. Can be done in O(N*logN).
//first precompute all divisors of all numbers.
 /* for (int i=2; i<MAX; i++) {
        for (int x=2*i; x<MAX; x+=i) {
            divisors[x].push_back(i);
        }
    }*/ //then dp[i]=dp[(i/div)+k]+xxyy , etc.
int32_t main()
{
    linear_sieve(N);
    numpf[1]=0; //not always needed. Got AC without too. (1499D).
    for (int i=2; i<N; i++) {
        numpf[i]=numpf[i/spf[i]];
        if (spf[i]!=spf[i/spf[i]]) {
            numpf[i]++;
        }
    }
    sieve(sqrt(N));
    for (int v: primes) {
        cout<<v<<" ";
    }
	return 0;
}

//MADE A MISTAKE IN CONTEST 680 DIV 2C.
//Had to find prime factorization of a number <=10^9.
//Approach:

//sqrt(10^9) approx 32000.
//Find all primes till 32000.
//Keep dividing number by primes till 32000 after factor.
//I forgot to consider what's left. Whats left will either be 1 or a prime greater than 32000
