#include <bits/stdc++.h>
#define FOR(i, END) for(int i=1; i <= END; ++i)
using namespace std;

int main(){
    int t, f, s, p, c;
    int cnt{2};
    while(cnt--){
        cin >> t >> f >> s >> p >> c;
        cout << t*6 + f*3 + s*2 + p + c*2 << " ";
    }
}