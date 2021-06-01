#include<bits/stdc++.h>
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
//#define int long long

using namespace std;
int32_t main()
{
    int t; cin>>t;
    while (t--) {

        //COORDINATE COMPRESSION. IN THIS CASE, SEGMENTS.
        int n; cin>>n;
        vector<int>l(n), r(n);
        vector<int>val;
        for (int i=0; i<n; i++) {
            cin>>l[i]>>r[i];
            val.pb(l[i]);
            val.pb(r[i]);
        }
        sort(val.begin(), val.end());
        val.resize(unique(val.begin(), val.end()) - val.begin()); //remove duplicates.
        int siz=val.size();

        vector<vector<int>>endd(siz); //ending point of all segments starting at particular index.
        for (int i=0; i<n; i++) {
            l[i]=lower_bound(val.begin(), val.end(), l[i])-val.begin();
            r[i]=lower_bound(val.begin(), val.end(), r[i])-val.begin();
            endd[l[i]].pb(r[i]);
        }

        vector<vector<int>>dp(siz, vector<int>(siz, 0)); //2D siz * siz. all initialized to 0.

        for (int right=0; right<siz; right++) {
            for (int left=right; left>=0; left--) {
                bool found=false;
                for (int i=0; i<endd[left].size(); i++) {
                    if (endd[left][i]==right) {
                        found=true;
                    }
                }
                if (left!=right) {
                    dp[left][right]=dp[left+1][right];
                }
                else {
                    dp[left][right]=0;
                }
                if (found) {
                    dp[left][right]++;
                }

                for (int i=0; i<endd[left].size(); i++) {
                    int index=endd[left][i];
                    if (index<right) {
                        dp[left][right]=max(dp[left][right], found+dp[left][index]+dp[index+1][right]);
                    }
                }
            }
        }

        cout<<dp[0][siz-1]<<endl;
    }


	return 0;
}
