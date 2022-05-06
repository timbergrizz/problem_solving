#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll tree[80000];

void update(ll key, ll start, ll end, ll node) {
//    cout << key << " "<< start << " " << end << " " << node << endl;
    if (start == end) {
        tree[node] += 1;
        return;
    }

    ll mid = start + ((end - start) / 2);

    if(key <= mid) update(key, start, mid, node * 2);
    else update(key, mid + 1, end, node * 2 + 1);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll getNum(ll k, ll start, ll end, ll node) {
//    cout << k << " " << start << " " << end << " " << tree[node] << endl;
    if (start == end) return start;
    ll mid = start + (end - start) / 2, diff = tree[node * 2];

    if (k <= diff) return getNum(k, start, mid, node * 2);
    else return getNum(k - diff, mid + 1, end, node * 2 + 1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;

    ll c1;
    for (int i = 1; i <= N; ++i) {
        cin >> c1;
        update(c1 + 10000, 0,  20000, 1);
        cout << getNum((i + 1) / 2, 0, 20000, 1) - 10000<< "\n";
    }
}