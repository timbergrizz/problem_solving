#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define FOR(i, END) for(int i=0; i < END; ++i)
#define MAX 1000000000
using namespace std;

typedef vector<int> vi;

int dp[1010101]{0, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 6, 2};

void get_hex(int val, vi& v) {
    int n = 1, cur = 0, prev = 0;
    while (cur < val) {
        cur = n * (2 * n - 1);
        v.push_back(cur);
        n += 1;
    }
}

int get_answer(int N) {
    if (N < 13) return dp[N];
    vi hex;
    get_hex(N, hex);

    for(int i{13}; i <= N; ++i){
        int min_val = MAX;
        for(int it : hex) {
            if(it > i) break;
            min_val = min(min_val, dp[i - it]);
        }
        dp[i] = min_val + 1;
    }
    return dp[N];
}

int main() {
    int N;
    cin >> N;

    cout << get_answer(N);
}