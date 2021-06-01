#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long

using namespace std;
int32_t main() {

    freopen("inputd.txt", "r", stdin);
    //freopen("outputd.txt", "w", stdout);

    int B, L, D; cin>>B>>L>>D;
    //B: num books, L: num libaries, D: num days.
    int score[B];
    for (int i=0; i<B; i++) {
        cin>>score[i];
    }
    vector<vector<pair<int, int>>>books(L);
    vector<int>signup_time(L);
    vector<int>scanned_per_day(L);
    for (int i=0; i<L; i++) {
        int N; cin>>N; //num. books.
        int T; cin>>T; //num. days to sign up.
        int M; cin>>M; //num. books scanned per day.
        for (int j=0; j<N; j++) {
            int book_id; cin>>book_id;
            books[i].push_back({score[book_id], book_id});
        }
        sort(books[i].rbegin(), books[i].rend());
        signup_time[i]=T;
        scanned_per_day[i]=M;

    }
    set<int>taken_books; //books already done.

    int curr_time=0;
    int lib_left=L;
    vector<bool>lib_done(L, false); //which all libraries have already been picked.
    vector<pair<int, vector<int>>>ans;

    cout<<"Total time is "<<D<<endl;
    //assign score to each library at each step.
    while (curr_time<D-1 && lib_left>0) {
        cout<<curr_time<<endl;
        //assign score to each library
        int max_score=-1; int lib_taken=-1;
        vector<int>taken;
        for (int i=0; i<L; i++) {
            if (lib_done[i]==false) {
                int time_left=max(0, D-curr_time-signup_time[i]);
                int num_scanned=time_left*scanned_per_day[i];
                int num_taken=0;
                int score=0;
                vector<int>temp;
                for (auto x: books[i]) {
                    if (num_taken>=num_scanned) {
                        break;
                    }
                    if (taken_books.find(x.second)==taken_books.end()) {
                        score+=x.first;
                        num_taken++;
                        temp.pb(x.second);
                    }
                }
                if (score>max_score) {
                    max_score=score;
                    lib_taken=i;
                    taken=temp;
                }

            }
        }
        lib_done[lib_taken]=true;
        curr_time+=signup_time[lib_taken];
        lib_left--;
        for (auto k: taken) {
            taken_books.insert(k);
        }
        ans.pb({lib_taken, taken});



    }

    cout<<ans.size()<<endl;
    for (auto x: ans) {
        cout<<x.first<<" "<<x.second.size()<<endl;
        for (auto y: x.second) {
            cout<<y<<" ";
        }
        cout<<endl;
    }

    return 0;
}
