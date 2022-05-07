#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll tree[300000];

void update(ll key, ll start, ll end, ll node) {
    if (start == end) {
        tree[node] += 1;
        return;
    }

    ll mid = (start + end) / 2;

    if (key <= mid) update(key, start, mid, node * 2);
    else update(key, mid + 1, end, node * 2 + 1);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void update_reduce(ll key, ll start, ll end, ll node) {
    if (start == end) {
        tree[node] -= 1;
        return;
    }

    ll mid = (start + end) / 2;

    if (key <= mid) update_reduce(key, start, mid, node * 2);
    else update_reduce(key, mid + 1, end, node * 2 + 1);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll getMidVal(ll k, ll start, ll end, ll node) {
    if(start == end) return start;

    ll mid = (start + end) / 2, diff = tree[node * 2];
    if(k <= diff) return getMidVal(k, start, mid, node * 2);
    else return getMidVal(k- diff, mid + 1, end, node * 2 + 1);
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, K;
    cin >> N >> K;

    ll result{0};
    vector<int> v(N + 1);
    for(int i=1; i <= N; ++i){
        cin >> v[i];
        update(v[i], 0, 65536, 1);
//        cout << v[i] << endl;

        if(i >= K){
            result += getMidVal((K + 1) / 2, 0, 65536, 1);
//            cout << v[i - K + 1] << " " << result << endl;
            update_reduce(v[i - K + 1], 0, 65536, 1);
        }
    }
    cout << result << "\n";
}