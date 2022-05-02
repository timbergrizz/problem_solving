#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

int update(vi &tree, int s, int e, int n, int i) {
    if (i < s || e < i) return tree[n];
    if (s == e) return tree[n] = 1;

    int m = (s + e) / 2;
    return tree[n] = update(tree, s, m, n * 2, i) + update(tree, m + 1, e, n * 2 + 1, i);
}

ll getSum(vi &tree, int s, int e, int n, int l, int r) {
    if (r < s || e < l) return 0;
    if (l <= s && e <= r) return tree[n];

    int m = (s + e) / 2;
    return getSum(tree, s, m, n * 2, l, r) + getSum(tree, m + 1, e, n * 2 + 1, l, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map<string, int> m;
    vi v(100001), tree(400001);
    string temp;
    while (true) {
        m.clear();
        for(int &i : v) i = 0;
        for(int &i : tree) i = 0;

        int N;
        cin >> N;
        if (N == 0) break;


        for (int i = 1; i <= N; ++i) {
            cin >> temp;
            m[temp] = i;
        }

        for (int i = 1; i <= N; ++i) {
            cin >> temp;
            v[m[temp]] = i;
        }

        long long result{0};
        for (int i = 1; i <= N; ++i) {
            result += getSum(tree, 1, N, 1, v[i], N);
            update(tree, 1, N, 1, v[i]);
        }
        cout << result << "\n";
    }
}