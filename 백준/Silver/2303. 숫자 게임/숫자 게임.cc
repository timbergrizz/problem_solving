#include <bits/stdc++.h>

#define FOR(i, N) for(int i=1; i <= N; ++i)
using namespace std;

typedef long long ll;
int v[1010][6]{0,};

int cards_max(int cnt, int cur, int idx, int &max_val, int i) {
//    cout << cnt << " " << idx << endl;
    if (cnt == 3) {
        max_val = max(max_val, cur % 10);
        return max_val;
    }
    if (idx > 5) return 0;

    int res{0};
    res = max(cards_max(cnt + 1, (cur + v[i][idx]) % 10, idx + 1, max_val, i),
              cards_max(cnt, cur % 10, idx + 1, max_val, i));

    return res;
}

int main() {
    int N, result_idx, result_val{0}, cur{0};
    cin >> N;
    FOR(i, N) {
        FOR(j, 5) cin >> v[i][j];
        int max_val{0};

        cur = cards_max(0, 0, 1, max_val, i);
//        cout << cur << endl;
        if (result_val <= cur) result_idx = i, result_val = cur;
    }
    cout << result_idx;
}