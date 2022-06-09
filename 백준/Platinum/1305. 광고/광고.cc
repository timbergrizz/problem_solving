#include <bits/stdc++.h>

#define FOR(i, init, N) for(int i=init; i<= N; ++i)
using namespace std;

typedef vector<int> vi;

int kmp(string &P, int m) {
    vi f(m + 1);
    int cnt{0};
    FOR(i, 1, m - 1) {
        while (cnt > 0 && P[i] != P[cnt]) cnt = f[cnt - 1];
        if (P[i] == P[cnt]) f[i] = ++cnt;
    }
    return m - f[m - 1];
}

int main() {
    int N;
    cin >> N;
    string P;
    cin >> P;

    cout << kmp(P, N);
}