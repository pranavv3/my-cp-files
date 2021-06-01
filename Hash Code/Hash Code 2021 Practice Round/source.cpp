#include<bits/stdc++.h>
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long

using namespace std;

/*void smallshuffle(vector<pair<int, int>>&a){
    int batch_size = rand()%10+5;
    int n = a.size(),prev{};
    while(prev+batch_size<n){
        random_shuffle(a.begin()+prev,a.begin()+prev+batch_size);
        prev+=batch_size;
    }
}*/

int32_t main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int M, T2, T3, T4;
    cin>>M; //no. of pizzas.
    cin>>T2>>T3>>T4; //num teams size 2, 3, 4.
    int cnt=0;
    map<string, int>m;

    vector<pair<int, int>>v; //<num. ingredients, index of pizza>.
    vector<vector<int>>ingredients(M);
    for (int i=0; i<M; i++) {
        int I; cin>>I;
        for (int j=0; j<I; j++) {
            string s; cin>>s;
            if (m.find(s)==m.end()) {
                cnt++;
                m[s]=cnt;
            }
            ingredients[i].push_back(m[s]);
        }
        v.push_back({I, i});
    }
    sort(v.rbegin(), v.rend());
    for (int i=0; i<min(M, T4*4); i+=4) {
        set<int>s;
        for (auto x: ingredients[v[i].second]) {
            s.insert(x);
        }
        for (int j=0; j<110; j++) {
            if (i+2+j<M) {
                set<int>s1=s; set<int>s2=s;
                for (auto x: ingredients[v[i+1].second]) {
                    s1.insert(x);
                }
                for (auto x: ingredients[v[i+2+j].second]) {
                    s2.insert(x);
                }
                if (s2.size()>s1.size()) {
                    swap(v[i+1], v[i+2+j]);
                }
            }
            else {
                break;
            }
        }
        for (auto x: ingredients[v[i+1].second]) {
            s.insert(x);
        }
        for (int j=0; j<110; j++) {

            if (i+3+j<M) {
                set<int>s1=s; set<int>s2=s;
                for (auto x: ingredients[v[i+2].second]) {
                    s1.insert(x);
                }
                for (auto x: ingredients[v[i+3+j].second]) {
                    s2.insert(x);
                }
                if (s2.size()>s1.size()) {
                    swap(v[i+2], v[i+3+j]);
                }
            }
            else {
                break;
            }
        }
        for (auto x: ingredients[v[i+2].second]) {
            s.insert(x);
        }

        for (int j=0; j<110; j++) {
            if (i+4+j<M) {
                set<int>s1=s; set<int>s2=s;
                for (auto x: ingredients[v[i+3].second]) {
                    s1.insert(x);
                }
                for (auto x: ingredients[v[i+4+j].second]) {
                    s2.insert(x);
                }
                if (s2.size()>s1.size()) {
                    swap(v[i+3], v[i+4+j]);
                }
            }
            else {
                break;
            }
        }
    }

    for (int i=T4*4; i<min(M, T4*4+T3*3); i+=3) {
        set<int>s;
        for (auto x: ingredients[v[i].second]) {
            s.insert(x);
        }
        for (int j=0; j<110; j++) {
            if (i+2+j<M) {
                set<int>s1=s; set<int>s2=s;
                for (auto x: ingredients[v[i+1].second]) {
                    s1.insert(x);
                }
                for (auto x: ingredients[v[i+2+j].second]) {
                    s2.insert(x);
                }
                if (s2.size()>s1.size()) {
                    swap(v[i+1], v[i+2+j]);
                }
            }
            else {
                break;
            }
        }
        for (auto x: ingredients[v[i+1].second]) {
            s.insert(x);
        }
        for (int j=0; j<110; j++) {

            if (i+3+j<M) {
                set<int>s1=s; set<int>s2=s;
                for (auto x: ingredients[v[i+2].second]) {
                    s1.insert(x);
                }
                for (auto x: ingredients[v[i+3+j].second]) {
                    s2.insert(x);
                }
                if (s2.size()>s1.size()) {
                    swap(v[i+2], v[i+3+j]);
                }
            }
            else {
                break;
            }
        }
    }

    for (int i=T4*4+T3*3; i<min(M, T4*4+T3*3+T2*2); i+=2) {
        set<int>s;
        for (auto x: ingredients[v[i].second]) {
            s.insert(x);
        }
        for (int j=0; j<110; j++) {
            if (i+2+j<M) {
                set<int>s1=s; set<int>s2=s;
                for (auto x: ingredients[v[i+1].second]) {
                    s1.insert(x);
                }
                for (auto x: ingredients[v[i+2+j].second]) {
                    s2.insert(x);
                }
                if (s2.size()>s1.size()) {
                    swap(v[i+1], v[i+2+j]);
                }
            }
            else {
                break;
            }
        }

    }

    int done=0; //pizza's assigned
    //assign first to team's size 4 then size 3 then size 2.


    vector<vector<int>>ans;


    while (true) {
        if (T4>0 && M-done>=4) {
            vector<int>x;
            x={v[done].second, v[done+1].second, v[done+2].second, v[done+3].second};
            ans.push_back(x);
            done+=4;
            T4--;
            continue;
        }

        if (T3>0 && M-done>=3) {
            vector<int>x;
            x={v[done].second, v[done+1].second, v[done+2].second};
            ans.push_back(x);
            done+=3;
            T3--;
            continue;
        }

        if (T2>0 && M-done>=2) {
            vector<int>x;
            x={v[done].second, v[done+1].second};
            ans.push_back(x);
            done+=2;
            T2--;
            continue;
        }

        break;
    }
    cout<<ans.size()<<endl;
    for (auto x: ans) {
        cout<<x.size()<<" ";
        for (auto y: x) {
            cout<<y<<" ";
        }
        cout<<endl;
    }


	return 0;
}
