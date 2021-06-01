#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define int long long

using namespace std;
using namespace __gnu_pbds;

int32_t main()
{
    IOS;

    //it's called policy based DS.

    //Normal: Used for CSES Josephus II.
    //Multiset implementation: for CSES Nested Range Count.

    tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> s1;

    //IF WANT TO USE AS MULTISET:: SOME WEIRD BEHAVIORS::
    //if want to use as multiset:: replace less<int> with less_equal int. However lower bound and upper bound will have weird behaviors in this case.
    //if as multiset:: lower bound works as upper bound and vice versa. VVI. (interchange two lol).
    //also, when I use as a multiset, erase does not work.
    //Suppose I want to erase 2. s.erase(2) won't work. Do s.erase(s.upper_bound(2)); hmmm... (upper_bound as ub and lb interchanged).

    //just be careful when multiset.


    tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> s;

    s.insert(0);
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(3);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(6);
    s.insert(7);
    if (s.find(8)==s.end()) {
        cout<<"YES"<<endl;
    }
    cout<<*s.lower_bound(0)<<endl;
    cout<<*s.upper_bound(2)<<endl;
    cout<<*s.find_by_order(3)<<endl; //4th element from left. Stats from 0.
    cout<<*s.begin()<<endl;
    cout<<s.order_of_key(4)<<endl; //number of elements <x.
    s.erase(s.upper_bound(3));
    s.erase(s.upper_bound(3));
    cout<<s.order_of_key(4)<<endl;
    //if greater<int>, will give number >x.




	return 0;
}
