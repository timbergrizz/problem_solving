#include <bits/stdc++.h>

#define INF 200002
#define MOD 1000000007
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<ll> vl;

pll operator+=(pll A, pll B) {
    return {A.first + B.first, A.second + B.second};
}

pll operator+(pll A, pll B) {
    return {A.first + B.first, A.second + B.second};
}

pll update(vpll &tree, ll start, ll end, ll node, ll pos) {
    if (pos < start || end < pos) return tree[node];
//    cout << start << end << pos << endl;
//    cout << start << " " << end << " " << pos << " " << node << endl;
    if (start == end) {
        tree[node] = tree[node] + pll(pos, 1);
        return tree[node];
    }

    ll mid = (start + end) / 2;
    return tree[node] = update(tree, start, mid, node * 2, pos) + update(tree, mid + 1, end, node * 2 + 1, pos);
}

pll getSum(vpll &tree, ll start, ll end, ll node, ll l, ll r) {
    if (end < l || r < start) return {0, 0};
    if (l <= start && end <= r) return tree[node];

    ll mid = (start + end) / 2;
    return getSum(tree, start, mid, node * 2, l, r) + getSum(tree, mid + 1, end, node * 2 + 1, l, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    ll result = 1, c1, q;
    vpll tree(INF * 4);

    cin >> c1;
    update(tree, 0, INF, 1, c1);

    for (int i = 2; i <= N; ++i) {
        cin >> c1;
        pll left = getSum(tree, 0, INF, 1, 0, (c1 - 1 < 0 ? 0 : c1));
        pll right = getSum(tree, 0, INF, 1, (c1 + 1 > INF ? INF : c1), INF);
//        cout << left.first << left.second << right.first << right.second << endl;
//        cout << c1 << endl;
        q = (c1 * left.second - left.first + right.first - c1 * right.second) % MOD;
//        cout << q << endl;
        result = (result * q) % MOD;
        update(tree, 0, INF, 1, c1);
    }
    cout << result << "\n";
}