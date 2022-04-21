#include <bits/stdc++.h>
#define FOR(i, N) for(int i=0; i < N; ++i)
using namespace std;

int tree[400010], v[100010], idx[100010];

int update(int start, int end, int node, int index){
    if(index < start || end < index) return tree[node];
    if(start == end) return tree[node] = 1;

    int mid = (start + end) / 2;
    return tree[node] = update(start, mid, node * 2, index) + update(mid + 1, end, node * 2 + 1, index);
}

int sum(int start, int end, int node, int l, int r){
    if(r < start || end < l) return 0;
    if(l <= start && end <= r) return tree[node];

    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, l, r) + sum(mid + 1, end, node * 2 + 1, l, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    while(T--){
        FOR(i, 100010) v[i] = idx[i] = 0;
        for(int &i : tree) i = 0;

        int N; cin >> N;
        int c1;
        FOR(i, N){
            cin >> c1;
            v[c1] = i;
        }
        FOR(i, N){
            cin >> c1;
            idx[i] = v[c1];
        }

        long long result{0};
        FOR(i, N){
            result += sum(0, N - 1, 1, idx[i] + 1, N - 1);
            update(0, N - 1, 1, idx[i]);
        }
        cout << result << "\n";
    }
}