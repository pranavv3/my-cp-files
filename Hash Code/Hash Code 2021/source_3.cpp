#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long

using namespace std;
int32_t main() {

    freopen("d.txt", "r", stdin);
    freopen("dout.txt", "w", stdout);

    int D, I, S, V, F; cin>>D>>I>>S>>V>>F;
    //D: Duration
    //I: ingredients
    //S: Num Streets
    //V: Num Cars
    //F: Bonus Points

    map<string, vector<int>>times;
    //times at which end of road is reached, for each string. (assuming no waiting time?)
    //based on this, find optimal timing.

    map<string, int>time_to_cross;
    vector<string>intersection[I];
    for (int i=0; i<S; i++) {
        int B, E; cin>>B>>E;
        string name; cin>>name;
        intersection[E].push_back(name);
        int L; cin>>L;
        time_to_cross[name]=L;
    }

    //time visited, assuming nothing stopping us.
    for (int i=0; i<V; i++) {
        int P; cin>>P; //num. paths.
        int curr_time=0;
        for (int j=0; j<P; j++) {
            string x; cin>>x;
            if (j>0) {
                curr_time+=time_to_cross[x];
            }
            times[x].push_back(curr_time);
        }


    }

    cout<<I<<endl;
    for (int i=0; i<I; i++) {
        cout<<i<<endl;
        cout<<intersection[i].size()<<endl;

        //need to decide order of oscillation, for all strings in intersection[i];
        //I have store time at which end of x is reached, for each car.
        set<string>left;
        for (auto x: intersection[i]) {
            left.insert(x);
        }
        vector<string>positions(intersection[i].size(), "-1");
        for (auto x: intersection[i]) {
            vector<int>remainders(intersection[i].size(), 0);
            for (auto y: times[x]) {
                remainders[y%intersection[i].size()]++;
            }

            int mx=0, mx_rem=-1;
            for (int k=0; k<intersection[i].size(); k++) {
                if (remainders[k]>=mx) {
                    mx=remainders[k];
                    mx_rem=k;
                }
            }
            if (positions[mx_rem]=="-1") {
                positions[mx_rem]=x;
                left.erase(left.find(x));
            }

        }
        /*for (auto x: intersection[i]) {
            cout<<x<<" "<<1<<endl;
        }*/
        for (int g=0; g<intersection[i].size(); g++) {
            if (positions[g]=="-1") {
                cout<<*left.begin()<<" "<<1<<endl;
                left.erase(left.begin());
            }
            else {
                cout<<positions[g]<<" "<<1<<endl;
            }
        }
    }



    return 0;
}


