#include <bits/stdc++.h>

#define FOR(i, N) for(int i=1; i<=N; ++i)
using namespace std;

typedef long long ll;

int main() {
    vector<int> v(3);
    for(int &i : v)  cin >> i;
    sort(v.begin(), v.end());
    for(int i : v) cout << i << " ";
}