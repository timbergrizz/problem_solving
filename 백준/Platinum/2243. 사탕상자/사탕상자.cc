#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vl;

void update(vl &tree, ll start, ll end, ll node, ll key, ll cnt) {
    if (start == end) {
//        cout << start << endl;
        tree[node] += cnt;
        return;
    }

    ll mid = (start + end) / 2;
    if (key <= mid) update(tree, start, mid, node * 2, key, cnt);
    else update(tree, mid + 1, end, node * 2 + 1, key, cnt);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll getKey(vl &tree, ll start, ll end, ll node, ll k) {
    if (start == end) return start;
    ll mid = (start + end) / 2, diff = tree[node * 2];

    if (k <= diff) return getKey(tree, start, mid, node * 2, k);
    else return getKey(tree, mid + 1, end, node * 2 + 1, k - diff);
}

void reduce(vl &tree, ll start, ll end, ll node, ll k) {
    if (start == end) {
        tree[node] -= 1;
        return;
    }

    ll mid = (start + end) / 2, diff = tree[node * 2];

    if (k <= diff) reduce(tree, start, mid, node * 2, k);
    else reduce(tree, mid + 1, end, node * 2 + 1, k - diff);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    ll c1, c2, c3;
    vl tree(4000000);

    while (N--) {
        cin >> c1 >> c2;

        if (c1 == 1) {
            cout << getKey(tree, 0, 1000000, 1, c2) << "\n";
            reduce(tree, 0, 1000000, 1, c2);
        } else {
            cin >> c3;
            update(tree, 0, 1000000, 1, c2, c3);
        }

    }
}