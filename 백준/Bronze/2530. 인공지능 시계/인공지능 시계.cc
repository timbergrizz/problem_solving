#include <bits/stdc++.h>


#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define FOR(i, N) for(int i=1; i <= N; ++i)

using namespace std;

int main() {
    FASTIO
    int H, M, S, c1;
    cin >> H >> M >> S >> c1;

    int totalSec = H * 3600 + M * 60 + S + c1;
    totalSec %= 86400;

    cout << totalSec / 3600 << " " << (totalSec % 3600) / 60 << " " << (totalSec % 60);
}