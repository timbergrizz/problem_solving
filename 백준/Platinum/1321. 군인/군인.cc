#include <bits/stdc++.h>

#define MOD 1000000007LL
using namespace std;

typedef long long ll;
typedef vector<ll> vl;

ll update(vl &tree, ll start, ll end, ll node, ll idx, ll val) {
    if (idx < start || end < idx) return tree[node];
    if (start == end) return tree[node] += val;

    ll mid = (start + end) / 2;
    return tree[node] = update(tree, start, mid, node * 2, idx, val) + update(tree, mid + 1, end, node * 2 + 1, idx, val);
}

ll getSum(vl &tree, ll start, ll end, ll node, ll k) {
    if (start == end) return start;

    ll mid = (start + end) / 2, diff = tree[node * 2];

    if(k <= diff) return getSum(tree, start, mid, node * 2, k);
    else return getSum(tree, mid + 1, end, node * 2 + 1, k - diff);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M; cin >> N;
    vl tree(N * 4);

    ll c1, c2, c3;
    for(int i=1; i<= N; ++i){
        cin >> c1;
        update(tree, 1, N, 1, i, c1);
    }

    cin >> M;
    while(M--){
        cin >> c1 >> c2;
        if(c1 == 1){
            cin >> c3;
            update(tree, 1, N, 1, c2, c3);
        }
        else cout << getSum(tree, 1, N, 1, c2) << "\n";
    }


}