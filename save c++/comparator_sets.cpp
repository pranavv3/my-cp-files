#include<bits/stdc++.h>
#define ll long long
#define l long
#define m9 1000000007
#define pb push_back
#define mp make_pair
#define f first
#define ss second
const ll N = 10e5 + 5;
ll inf=10e5;
using namespace std;

//WRITING COMPARATORS FOR SET.
//With this, can do ascending, descending, etc whatever you want.
//No need to use prev(s.end()), etc. Always just use s.begin() to access top priority element. Then pop s.begin() if needed.

//Case 1: Sort, ascending order based on parameter 1, descending order based on parameter 2.
//eg: (1, 3), (1, 2), (3, 4), (3, 2), (5, 7);

//ALSO VERY VERY IMPORTANT:: IF U ARE USING A COMPARATOR FOR SORTING VECTORS::
//you can't directly to sort(v.begin(), v.end(), cmp).
//you have to created an instance of the struct first.
//struct cmp var
//then call sort(v.begin(), v.end(), var);
struct cmp {
    bool operator() (const pair<int, int>&a, const pair<int, int>&b) const {
        if (a.first==b.first) {
            //if true, a first. if false, b first.
            return a.second>b.second;
        }
        //if true, a first. if false, b first.
        return a.first<b.first;
    }
};
//Case 2: Have set with intervals. {start, end}. sort based on size, then start value.
struct cmp1 {
	bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
		int lena = a.second - a.first + 1;
		int lenb = b.second - b.first + 1;
		if (lena == lenb) return a.first < b.first;
		return lena > lenb;
	}
};
int main() {

        set<pair<int, int>, cmp>inter; .


        inter.insert({5, 0});

    return 0;
}
