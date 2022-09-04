#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define FOR(i, END) for(int i=1; i <= END; ++i)
using namespace std;

int main() {
    FASTIO
    int N; cin >> N;
    vector<int> v(N);

    for(int &i : v) cin >> i;
    sort(v.rbegin(), v.rend());

    int endDate{0};
    FOR(i, N) endDate = max(endDate, (i + 1) + v[i - 1]);

    cout << endDate;
}