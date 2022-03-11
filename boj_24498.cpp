#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<ll> v(N);

    for (ll &i: v) cin >> i;
    ll maxHeight{0};

    maxHeight = max(v[0], v[N-1]);
    for (int i = 1; i < N - 1; ++i) maxHeight = max(maxHeight, v[i] + min(v[i-1], v[i+1]));

    cout << maxHeight << "\n";
}