#include <bits/stdc++.h>

#define FOR(i, N) for(int i=1; i <= N; ++i)
using namespace std;

int dice[7]{0,};

int main() {
    int c1;
    FOR(i, 3) {
        cin >> c1;
        dice[c1]++;
    }

    int maxIdx{0}, maxVal{0};
    FOR(i, 6) {
        if (dice[i] >= maxVal) maxIdx = i, maxVal = dice[i];
    }

    int result{0};
    if (maxVal == 3) result = 10000 + maxIdx * 1000;
    else if (maxVal == 2) result = 1000 + maxIdx * 100;
    else result = maxIdx * 100;
    cout << result;
}