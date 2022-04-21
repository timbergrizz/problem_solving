#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

ll update(vi &tree, ll start, ll end, ll node, ll idx) {
    if (idx < start || end < idx) return tree[node];
    if (start == end) return tree[node] = 1;

    ll mid = (start + end) / 2;
    return tree[node] = update(tree, start, mid, node * 2, idx) + update(tree, mid + 1, end, node * 2 + 1, idx);
}

ll sum(vi &tree, ll start, ll end, ll node, ll l, ll r) {
    if (r < start || end < l) return 0;
    if (l <= start && end <= r) return tree[node];

    ll mid = (start + end) / 2;
    return sum(tree, start, mid, node * 2, l, r) + sum(tree, mid + 1, end, node * 2 + 1, l, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    int treeSize = 1 << ((int) ceil(log2(N)) + 1);
    vi order(1000001), order2(1000001);
    vi tree(treeSize);


    ll c1;
    for (int i = 0; i < N; ++i) {
        cin >> c1;
        order[c1] = i;
    }
    for(int i=0; i< N; ++i){
        cin >> c1;
        order2[i] = order[c1];
    }

    long long result{0};
    for (int i=0; i < N; ++i) {
        result += sum(tree, 0, N - 1, 1, order2[i] + 1, N - 1);
        update(tree, 0, N - 1, 1, order2[i]);
    }
    cout << result << endl;
}