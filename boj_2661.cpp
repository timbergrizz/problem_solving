#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n ; ++i)
using namespace std;

int v[81], n;

bool check(int target) {
    for(int i=1; i <= target / 2; ++i){
        string s1 = "", s2 = "";
        FOR(j, i){
            s1 += to_string(v[target - 2 * i + j]), s2 += to_string(v[target -i + j]);
//            cout << "comparison  : "<< s1 << " "<< s2 ;
        }
        if(s1 == s2) return false;
    }
    return true;
}

bool dfs(int s) {
//    cout << s << endl;

    if (s == n) {
        for (int i = 0; i < n; ++i) cout << v[i];
        cout << "\n";
        return true;
    }

    for (int i = 1; i <= 3; ++i) {
        v[s] = i;
        if (check(s + 1)) {
            bool result = dfs(s + 1);
            if (result) return true;
        }
    }
    return false;
}

int main() {
    cin >> n;
    dfs(0);
}