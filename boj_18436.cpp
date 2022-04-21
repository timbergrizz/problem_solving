#include <bits/stdc++.h>

#define FOR(i, N) for(int i=0; i < N; ++i)
using namespace std;

typedef vector<int> vi;

int u(vi &t, int s, int e, int n, int i, int v) {
    if (i < s || i > e) return t[n];
    if (s == e) return t[n] = v;

    int mid = (s + e) / 2;
    return t[n] = u(t, s, mid, n * 2, i, v) + u(t, mid + 1, e, n * 2 + 1, i, v);
}

int m(vi &t, int s, int e, int n, int l, int r) {
    if (r < s || l > e) return 0;
    if (l <= s && e <= r) return t[n];

    int mid = (s + e) / 2;
    return m(t, s, mid, n * 2, l, r) + m(t, mid + 1, e, n * 2 + 1, l, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    int treeSize = 1 << ((int) ceil(log2(N)) + 1);
    vector<int> treeOdd(treeSize);
    vector<int> treeEven(treeSize);

    int c1, c2, c3;
    FOR(i, N) {
        cin >> c1;
        u(treeOdd, 0, N - 1, 1, i, c1 % 2);
        u(treeEven, 0, N - 1, 1, i, (c1 % 2 ? 0 : 1));
    }

    int M;
    cin >> M;

    FOR(i, M) {
//        for(int i : treeOdd) cout << i << " ";
//        cout << endl;
//        for(int i : treeEven) cout << i << " ";
//        cout << endl;
        cin >> c1 >> c2 >> c3;
        if(c1 == 1){
            u(treeOdd, 0, N - 1, 1, c2 - 1, c3 % 2);
            u(treeEven, 0, N - 1, 1, c2 - 1, (c3 % 2 ? 0 : 1));
        }
        else{
            int res = (c1 == 2 ? m(treeEven, 0, N - 1, 1, c2 - 1, c3 - 1) : m(treeOdd, 0, N -1, 1, c2 - 1, c3 - 1));
            cout << res << "\n";
        }

    }
}