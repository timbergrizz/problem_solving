#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define FOR(i, n) for(int i=1; i <= n; ++i)
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<pll> vl;

int main() {
    int N;
    cin >> N;
    vl v(N + 1);
    FOR(i, N) {
        cin >> v[i].first;
        v[i].second = 1;
    }

    stack<pll> s;
    ll i{0}, result{0};
    while (i <= N) {
        if (s.empty()) s.push(v[i++]);
        else {
            if (s.top().first > v[i].first) {
                s.push(v[i]);
                ++result, ++i;
            } else if (s.top().first == v[i].first) {
                v[i].second += s.top().second, result += s.top().second;
                s.pop();
            } else {
                result += s.top().second;
                s.pop();
            }
        }
    }
    cout << result << "\n";
}