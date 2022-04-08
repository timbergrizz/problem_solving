#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// 세그먼트 트리는 부분적인 연산을 바이너리 트리로 처리하는 것.
// 이때 분할정복으로 처리한다고 생각하면 좋을 것.
ll init(ll start, ll end, ll node, vector<ll> &a, vector<ll> &tree) {
    //시작값과 끝값이 같으면 그 노드가 위치하는 곳이 될 것.
    if (start == end) return tree[node] = a[start];
    //분할정복의 느낌으로 중앙을 기준으로 트리를 계속 쪼개준다.
    ll mid = (start + end) / 2;
    // 풀 바이너리 트리에서 왼쪽 자식은 n*2, 오른쪽 자식은 n*2 + 1로 처리한다.
    return tree[node] = init(start, mid, node * 2, a, tree) + init(mid + 1, end, node * 2 + 1, a, tree);
}

// 업데이트도 동일하게 처리한다.
void update(ll start, ll end, ll node, ll index, ll diff, vector<ll> &tree) {
//    범위를 벗어나면 함수를 반한하고, 범위 안이면 차이를 반영해준다.
    if (index < start || index > end) return;
    tree[node] = tree[node] + diff;

    // 차이를 반영한 후 모든 자식들에게도 동일하게 수행한다.
    if (start != end) {
        ll mid = (start + end) / 2;

        update(start, mid, node * 2, index, diff, tree);
        update(mid + 1, end, node * 2 + 1, index, diff, tree);
    }
}

ll sum(ll start, ll end, ll node, ll l, ll r, vector<ll> &tree) {
    if (l > end || r < start) return 0;
    if (l <= start && end <= r) return tree[node];
    ll mid = (start + end) / 2;

    return sum(start, mid, node * 2, l, r, tree) + sum(mid + 1, end, node * 2 + 1, l, r, tree);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    ll height = (int) ceil(log2(n));
    ll tree_size = (1 << (height + 1));
    vector<ll> a(n);
    vector<ll> tree(tree_size);
    m += k;

    for (ll &i: a) cin >> i;
    init(0, n - 1, 1, a, tree);

    while (m--) {
        ll fir, sec, val;
        cin >> fir >> sec >> val;

        if (fir == 1) {
            sec -= 1;
            ll diff = val - a[sec];
            a[sec] = val;
            update(0, n - 1, 1, sec, diff, tree);
        } else {
            cout << sum(0, n - 1, 1, sec - 1, val - 1, tree) << "\n";
        }
    }
}