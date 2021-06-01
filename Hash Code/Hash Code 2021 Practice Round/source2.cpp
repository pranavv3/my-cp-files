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
        int cur_siz=0;
        set<int>curr;
        for (auto x: ingredients[v[i].second]) {
            curr.insert(x);
        }
        for (auto x: ingredients[v[i+1].second]) {
            curr.insert(x);
        }
        for (auto x: ingredients[v[i+2].second]) {
            curr.insert(x);
        }
        int mx=curr.size();
        int st[3]={i, i+1, i+2};
        for (int j=i; j<i+40; j++) {
            for (int k=j+1; k<i+40; k++) {
                for (int l=k+1; l<min(i+40, M); l++) {
                    set<int>temp;
                    for (auto x: ingredients[v[j].second]) {
                        temp.insert(x);
                    }
                    for (auto x: ingredients[v[k].second]) {
                        temp.insert(x);
                    }
                    for (auto x: ingredients[v[l].second]) {
                        temp.insert(x);
                    }
                    if (temp.size()>mx) {
                        mx=temp.size();
                        st[0]=j, st[1]=k, st[2]=l;
                    }
                }
            }
        }
        swap(v[i], v[st[0]]);
        swap(v[i+1], v[st[1]]);
        swap(v[i+2], v[st[2]]);
        curr.clear();
        for (auto x: ingredients[v[i].second]) {
            curr.insert(x);
        }
        for (auto x: ingredients[v[i+1].second]) {
            curr.insert(x);
        }
        for (auto x: ingredients[v[i+2].second]) {
            curr.insert(x);
        }
        for (int m=i+4; m<min(i+125, M); m++) {
            set<int>temp=curr;
            set<int>temp1=curr;
            for (auto x: ingredients[v[i+3].second]) {
                temp.insert(x);
            }
            for (auto x: ingredients[v[m].second]) {
                temp1.insert(x);
            }
            if (temp1.size()>temp.size()) {
                swap(v[i+3], v[m]);
            }
        }

    }

    for (int i=T4*4; i<min(M, T4*4+T3*3); i+=3) {
        int cur_siz=0;
        set<int>curr;
        for (auto x: ingredients[v[i].second]) {
            curr.insert(x);
        }
        for (auto x: ingredients[v[i+1].second]) {
            curr.insert(x);
        }
        int mx=curr.size();
        int st[2]={i, i+1};
        for (int j=i; j<i+64; j++) {
            for (int k=j+1; k<i+64; k++) {
                    set<int>temp;
                    for (auto x: ingredients[v[j].second]) {
                        temp.insert(x);
                    }
                    for (auto x: ingredients[v[k].second]) {
                        temp.insert(x);
                    }
                    if (temp.size()>mx) {
                        mx=temp.size();
                        st[0]=j, st[1]=k;
                    }
                }
        }
        swap(v[i], v[st[0]]);
        swap(v[i+1], v[st[1]]);
        curr.clear();
        for (auto x: ingredients[v[i].second]) {
            curr.insert(x);
        }
        for (auto x: ingredients[v[i+1].second]) {
            curr.insert(x);
        }
        for (int m=i+3; m<min(i+125, M); m++) {
            set<int>temp=curr;
            set<int>temp1=curr;
            for (auto x: ingredients[v[i+2].second]) {
                temp.insert(x);
            }
            for (auto x: ingredients[v[m].second]) {
                temp1.insert(x);
            }
            if (temp1.size()>temp.size()) {
                swap(v[i+2], v[m]);
            }
        }

    }

    for (int i=T4*4+T3*3; i<min(M, T4*4+T3*3+T2*2); i+=2) {

        int mx=ingredients[v[i].second].size();
        int st=i;
        for (int j=i+1; j<min(i+150, M); j++) {
            if (ingredients[v[j].second].size()>mx) {
                mx=ingredients[v[j].second].size();
                st=j;
            }
        }
        swap(v[i], v[st]);
        set<int>curr;
        for (auto x: ingredients[v[i].second]) {
            curr.insert(x);
        }
        for (int m=i+2; m<min(i+125, M); m++) {
            set<int>temp=curr;
            set<int>temp1=curr;
            for (auto x: ingredients[v[i+1].second]) {
                temp.insert(x);
            }
            for (auto x: ingredients[v[m].second]) {
                temp1.insert(x);
            }
            if (temp1.size()>temp.size()) {
                swap(v[i+1], v[m]);
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
