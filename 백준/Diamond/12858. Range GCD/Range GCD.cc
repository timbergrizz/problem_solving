#include <bits/stdc++.h>

#define FOR(i, N) for(int i=0; i< N; ++i)
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ADDER(a, b, c) a += c, b += c
using namespace std;

typedef long long ll;
typedef vector<ll> vl;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

class LazySeg {
public:
    vl tree, lazy;
    ll N;

    LazySeg(ll _N) {
        this->N = _N;

        tree = vl(N * 4 + 5);
        lazy = vl(N * 4 + 5);
    }

    void pro(ll start, ll end, ll node) {
        if (!lazy[node]) return;
        tree[node] += (end - start + 1) * lazy[node];

        if (start != end) ADDER(lazy[node * 2], lazy[node * 2 + 1], lazy[node]);
        lazy[node] = 0;
    }

    void update(ll start, ll end, ll node, ll l, ll r, ll val) {
        pro(start, end, node);
        if (end < l || r < start) return;
        if (l <= start && end <= r) {
            lazy[node] += val;
            pro(start, end, node);
            return;
        }

        ll mid = (start + end) >> 1;
        update(start, mid, node * 2, l, r, val);
        update(mid + 1, end, node * 2 + 1, l, r, val);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    ll query(ll start, ll end, ll node, ll l, ll r) {
        pro(start, end, node);
        if (end < l || r < start) return 0;
        if (l <= start && end <= r) return tree[node];

        ll mid = (start + end) / 2;
        return query(start, mid, node * 2, l, r) + query(mid + 1, end, node * 2 + 1, l, r);
    }
};

class Seg {
public:
    vl tree;
    ll N;

    Seg(ll _N) {
        this->N = _N;
        tree = vl(N * 4 + 5);
    }

    ll update(ll start, ll end, ll node, ll pos, ll val) {

        if (pos < start || pos > end) return tree[node];
//        cout << start << end << endl;
        if (pos == start && end == pos) return tree[node] += val;

        ll mid = (start + end) >> 1;
        return tree[node] = gcd(update(start, mid, node * 2, pos, val), update(mid + 1, end, node * 2 + 1, pos, val));
    }

    ll getGCD(ll start, ll end, ll node, ll l, ll r) {
        if (l > r) return 0;
        if (l == start && end == r) return tree[node];

        ll mid = (start + end) >> 1;
        return gcd(getGCD(start, mid, node * 2, l, min(r, mid)), getGCD(mid + 1, end, node * 2 + 1, max(mid + 1, l), r));
    }
};


int main() {
    FASTIO;
    ll N;
    cin >> N;

    LazySeg summ(N * 4);
    Seg gcdd(N * 4);
    vl v(N + 1);

    FOR(i, N) {
        cin >> v[i];
        summ.update(0, N - 1, 1, i, i, v[i]);
    }

    for(int i = 1; i < N; ++i) gcdd.update(0, N - 1, 1, i, v[i] - v[i - 1]);

    int Q;
    cin >> Q;

    int c1, c2, c3;
    while (Q--) {
//        for(ll i : gcdd.tree) cout << i << " ";
//        cout << endl;
//        for(ll i : summ.tree) cout << i << " ";
//        cout << endl;

        cin >> c1 >> c2 >> c3;
        c2 -= 1, c3 -= 1;

        if (!c1) {
            ll sum = summ.query(0, N - 1, 1, c2, c2);
            if(c2 == c3) cout << abs(sum) << "\n";
            else {
                ll g = gcdd.getGCD(0, N - 1, 1, c2 + 1, c3);
//                cout << c2 + 1 << c3 << " " << g << " " << sum << endl;
                cout << abs(gcd(sum, g)) <<"\n";
            }
        } else {
//            cout << c2 << " " << c3 << endl;
            summ.update(0, N - 1, 1, c2, c3, c1);
            gcdd.update(0, N - 1, 1, c2, c1);
            gcdd.update(0, N - 1, 1, c3 + 1, -c1);
        }
    }
}