#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define FOR(i, N) for(int i=1; i <= N; ++i)
using namespace std;

const int inf = 100001;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef pair<ll, pll> ppl;
typedef vector<ppl> vppl;

ll N;
ll v[inf], tree[inf * 4];

struct Q2{
    ll k, i, j, index;
    Q2(ll c1, ll c2, ll c3, ll c4) : k{c1}, i{c2}, j{c3}, index(c4){}
};

bool comp(Q2 a, Q2 b) {
    if (a.k == b.k) return a.index < b.index;
    return a.k < b.k;
}

ll update(ll index, ll value, ll node = 1, ll start = 1, ll end = N) {
    if (end < index || index < start) return tree[node];
    if (start == end) return tree[node] = value;

    ll mid = (start + end) >> 1;
    return tree[node] = update(index, value, node << 1, start, mid)
                        + update(index, value, node << 1 | 1, mid + 1, end);
}

ll get_val(ll l, ll r, ll node = 1, ll start = 1, ll end = N) {
    if (end < l || r < start) return 0;
    if (l <= start && end <= r) return tree[node];

    ll mid = (start + end) >> 1;
    return get_val(l, r, node << 1, start, mid)
           + get_val(l, r, node << 1 | 1, mid + 1, end);
}

int main() {
    FASTIO
    cin >> N;
    ll M, c1, c2, c3, c4, cnt{0}, K{0};

    FOR(i, N){
        cin >> c1;
        update(i, c1);
    }

    cin >> M;

    vpll q1;
    vector<Q2> q2;

    FOR(i, M) {
        cin >> c1;
        if (c1 == 1) {
            cin >> c2 >> c3;
            q1.push_back({c2, c3});
        } else {
            cin >> c4 >> c2 >> c3;
            q2.push_back({c4, c2, c3, cnt++});
        }
    }

    sort(q2.begin(), q2.end(), comp);
    vl result(q2.size());

    for(auto it : q2){
        while(it.k > K) {
            update(q1[K].first, q1[K].second);
            ++K;
        }

        result[it.index] = get_val(it.i, it.j);
    }
//    cout << endl;

    for(auto it : result) cout << it << "\n";
}