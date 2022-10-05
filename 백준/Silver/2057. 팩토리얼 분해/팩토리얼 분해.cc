#include <bits/stdc++.h>

#define FOR(i, N) for(int i=1; i<=N; ++i)
using namespace std;

typedef long long ll;
ll fact[21]{1,};

bool check(ll N, ll idx) {
    if (N == 0) return true;
    if (fact[idx] > N || idx > 20) return false;

    if(check(N - fact[idx], idx + 1)) return true;
    if(check(N, idx + 1)) return true;

    return false;
}

int main() {
    FOR(i, 20) fact[i] = i * fact[i - 1];
    ll N;
    cin >> N;

    cout << (check(N, 0) && N != 0 ? "YES" : "NO");
}