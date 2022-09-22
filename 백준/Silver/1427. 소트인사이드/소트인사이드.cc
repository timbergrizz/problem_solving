#include <bits/stdc++.h>

#define FOR(i, n) for(int i=2; i <= n; ++i)
using namespace std;

int prime[101010]{0,};

int main() {
    string buf; cin >> buf;
    vector<int> v;
    for(auto it : buf) v.push_back(it - '0');
    sort(v.rbegin(), v.rend());
    for(auto it : v) cout << it;
}