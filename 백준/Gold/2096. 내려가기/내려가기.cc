#include <bits/stdc++.h>

#define FOR(i, n) for(int i=1; i <= n; ++i)
using namespace std;

int v[10]{0, }, dp_min[10]{0, }, dp_max[10]{0, }, next_min[10]{0, }, next_max[10]{0, };

int main() {
    int N;
    cin >> N;

    FOR(i, N) {
        FOR(j, 3) cin >> v[j];
        next_max[1] = max(dp_max[1], dp_max[2]) + v[1];
        next_max[2] = max({dp_max[1], dp_max[2], dp_max[3]}) + v[2];
        next_max[3] = max(dp_max[2], dp_max[3]) + v[3];

        next_min[1] = min(dp_min[1], dp_min[2]) + v[1];
        next_min[2] = min(dp_min[1], min(dp_min[2], dp_min[3])) + v[2];
        next_min[3] = min(dp_min[2], dp_min[3]) + v[3];

        FOR(j, 3) dp_min[j] = next_min[j], dp_max[j] = next_max[j];
    }

    int min_res = 1e9, max_res{0};
    FOR(i, 3) {
        min_res = min(min_res, dp_min[i]);
        max_res = max(max_res, dp_max[i]);
    }

    cout << max_res << " " << min_res << "\n";
}