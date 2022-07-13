#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define FOR(i, N) for(int i = 1; i <= N; ++i)
#define INF 1000000000

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

int main() {
    ll N, c1, c2;

    cin >> N;
    vpll v(N);
    for (pll &it: v) cin >> it.first >> it.second;
    sort(v.begin(), v.end());

    set<ll, greater<ll>> S;

    for (pll it: v) {
        int t = it.second;
        auto iter = S.upper_bound(t);
        if (iter != S.end()) S.erase(iter);
        S.insert(t);
    }

    cout << S.size() << "\n";
}