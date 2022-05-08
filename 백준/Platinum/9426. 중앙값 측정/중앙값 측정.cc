#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll tree[300000];

void update(ll start, ll end, ll node, ll key) {
    if (start == end) {
        tree[node] += 1;
        return;
    }

    ll mid = (start + end) / 2;
    if (key <= mid) update(start, mid, node * 2, key);
    else update(mid + 1, end, node * 2 + 1, key);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void update_reduce(ll start, ll end, ll node, ll key) {
    if (start == end) {
        tree[node] -= 1;
        return;
    }

    ll mid = (start + end) / 2;
    if (key <= mid) update_reduce(start, mid, node * 2, key);
    else update_reduce(mid + 1, end, node * 2 + 1, key);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll getKey(ll start, ll end, ll node, ll k) {
    if (start == end) return start;

    ll mid = (start + end) / 2, diff = tree[node * 2];
//    cout << start << end << endl;

    if (k - diff <= 0) return getKey(start, mid, node * 2, k);
    else return getKey(mid + 1, end, node * 2 + 1, k - diff);
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> v(N + 1);
    ll result{0};

    for (int i = 1; i <= N; ++i) {
        cin >> v[i];
        update(0, 65536, 1, v[i]);

        if (i >= K) {
            result += getKey(0, 65536, 1, (K + 1)/ 2);
            update_reduce(0, 65536, 1, v[i - K + 1]);
        }
//        cout << result << endl;
    }
    cout << result << "\n";
}