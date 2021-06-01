#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long

//PRANAV VINCHURKAR
using namespace std;

int32_t main() {
    //freopen("d.txt", "r", stdin);



    for (int i=0; i<3; i++) {
        //freopen(filename, "w", stdout);
        char title[8];
        sprintf(title, "e%d.txt", i);
        FILE* img = fopen(title, "a");
        char* data = "XYZ \n";
        char* data2 = "ABC";
        fwrite(data, 1, strlen(data), img);
        fwrite(data2, 1, strlen(data), img);
        fclose(img);
    }

    return 0;
}

