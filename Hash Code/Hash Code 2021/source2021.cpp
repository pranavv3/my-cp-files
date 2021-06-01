#include<bits/stdc++.h>
#include <chrono>
#include <thread>
#define pb push_back
#define mp make_pair
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long

//PRANAV VINCHURKAR
using namespace std;
int randomfunc(int x) {
    return rand()%x;
}
int32_t main() {
    using namespace std::this_thread; // sleep_for, sleep_until
    using namespace std::chrono; // nanoseconds, system_clock, seconds
    freopen("d.txt", "r", stdin);


    int D, I, S, V, F; cin>>D>>I>>S>>V>>F;
    //D: Duration
    //I: ingredients
    //S: Num Streets
    //V: Num Cars
    //F: Bonus Points

    vector<string>intersection[I];
    for (int i=0; i<S; i++) {
        int B, E; cin>>B>>E;
        string name; cin>>name;
        intersection[E].push_back(name);
        int L; cin>>L;
    }

    map<string, int>cnt; //number of times each street is visited.
    for (int i=0; i<V; i++) {
        int P; cin>>P; //num. paths.
        for (int j=0; j<P; j++) {
            string x; cin>>x;
            cnt[x]++;
        }
    }

    vector<pair<int, vector<string>>>ans;
    for (int i=0; i<I; i++) {
        int siz=0;
        vector<string>strs;
        for (auto y: intersection[i]) {
            if (cnt[y]>0) {
                siz++;
                strs.pb(y);
            }
        }
        if (siz!=0) {
            ans.pb({i, strs});
        }
    }
    for (int i=0; i<1000; i++) { //number of files...
        char title[8];
        sprintf(title, "d%d.txt", i);
        freopen(title, "w", stdout);
        cout<<ans.size()<<endl;
        for (auto x: ans) {
            cout<<x.first<<endl;
            cout<<x.second.size()<<endl;
            vector<pair<string, int>>xx;
            for (auto y: x.second) {
                //cout<<y<<" "<<1+(cnt[y]/40)<<endl;
                xx.pb({y, 1});
            }
            mt19937 g(static_cast<uint32_t>(time(0)));
            random_shuffle(xx.begin(), xx.end(), randomfunc);
            for (auto k: xx) {
                cout<<k.first<<" "<<k.second<<endl;
            }
        }
    }

    return 0;
}

