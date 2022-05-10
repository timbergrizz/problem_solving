#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vl;

void update(vl &tree, ll start, ll end, ll node, ll k) {
//    cout << start << end << endl;
    if (start == end) {
        tree[node] += 1;
        return;
    }

    ll mid = (start + end) / 2;
    if (k <= mid) update(tree, start, mid, node * 2, k);
    else update(tree, mid + 1, end, node * 2 + 1, k);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll reduce(vl &tree, ll start, ll end, ll node, ll k) {
    if (start == end) {
        tree[node] -= 1;
        return start;
    }

    ll mid = (start + end) / 2, diff = tree[node * 2], result;
//    cout << start << end << diff << endl;

    if (k <= diff) result = reduce(tree, start, mid, node * 2, k);
    else result = reduce(tree, mid + 1, end, node * 2 + 1, k - diff);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
    return result;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;

    vl tree(8000000);
    ll c1, c2;
    while(N--){
        cin >> c1 >> c2;
        if(c1 == 1) update(tree, 1, 2000000, 1, c2);
        else cout << reduce(tree, 1, 2000000, 1, c2) << "\n";
//        cout << endl;
    }
}