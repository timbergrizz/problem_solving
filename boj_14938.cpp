#include <bits/stdc++.h>

#define FOR(i, N) for(int i=1; i <= N; ++i)
#define INF 1e9
using namespace std;

void floyd_warshall(vector<vector<int>> &v, int N) {
    FOR(k, N) {
        FOR(i, N) {
            FOR(j, N) {
                v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
            }
        }
    }
}

int main() {
    int n, m, r;
    cin >> n >> m >> r;
    vector<int> items(n);

    for (int &i: items) cin >> i;

    int fir, sec, len;
    vector<vector<int>> v(n + 1, vector<int>(n + 1, INF));
    FOR(i, n) v[i][i] = 0;


    FOR(i, r) {
        cin >> fir >> sec >> len;
        v[fir][sec] = v[sec][fir] = len;
    }

    floyd_warshall(v, n);
    int itemMax{0};

    FOR(i, n) {
        int itemVal{0};
        FOR(j, n) {
            if (v[i][j] < m) itemVal += items[j-1];
        }
        itemMax = max(itemMax, itemVal);
    }
    cout << itemMax << "\n";
}