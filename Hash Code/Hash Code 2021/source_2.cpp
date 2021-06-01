#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mt make_tuple
#define mp make_pair

using namespace std;
int randomfunc(int x) {
    return rand()%x;
}
int main()
{
    freopen("e.txt", "r", stdin);

    ll d, i, s, v, f; cin >> d >> i >> s >> v >> f;
    tuple <ll, ll, string, ll> st[s];
    vector <string> intersection[i];

    for(ll j=0; j<s; j++){
        ll a, b, d;
        string c;
        cin >> a >> b >> c >> d;
        st[j] = mt(a,b,c,d);
        intersection[b].pb(c);
    }

    unordered_map <string, ll> st_fr;


    for(ll j=0; j<v; j++){
        ll p; cin >> p;
        string s;
        for(ll k=0; k<p; k++){cin >> s; st_fr[s]++;}
    }

    for (int q=0; q<100; q++) {
        char title[8];
        sprintf(title, "e%d.txt", q);
        freopen(title, "w", stdout);
        cout << i <<"\n";
        for(ll j=0; j<i; j++){
            //cout << j <<"\n";
            //cout << intersection[j].size() <<"\n";
            vector <pair<ll, string>> v;

            for(ll k=0; k<intersection[j].size(); k++){if(st_fr[intersection[j][k]]>0)v.pb(mp(st_fr[intersection[j][k]], intersection[j][k] ));}
            sort(v.begin(), v.end());
            if(v.size()>0)cout << j << "\n" << v.size() <<"\n";

            vector<pair<string, int>>xx;
            for(ll k=0; k<v.size();k++){if(2*k<v.size()){xx.pb({v[v.size()-k-1].second, 2});/*cout << v[v.size()-k-1].second << " " << 2 <<"\n";*/}
            else {xx.pb({v[v.size()-k-1].second, 1});/*cout << v[v.size()-k-1].second << " " << 1 <<"\n";*/}
            }
            random_shuffle(xx.begin(), xx.end(), randomfunc);
            for (auto k: xx) {
                cout<<k.first<<" "<<k.second<<endl;
            }
        }
    }
    return 0;
}



