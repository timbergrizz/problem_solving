#include <bits/stdc++.h>

#define FOR(i, init, N) for(int i=init; i<= N; ++i)
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

typedef vector<int> vi;

int kmp(string &P, int m) {
    vi f(m + 1);
    int cnt{0}, result{0};
    FOR(i, 1, m - 1) {
        while (cnt > 0 && P[i] != P[cnt]) cnt = f[cnt - 1];
        if (P[i] == P[cnt]) f[i] = ++cnt;
        result = max(result, f[i]);
    }
    return result;
}

int main() {
    FASTIO
    string P;
    cin >> P;
    int N = (int) P.size();

    int result{0};
    FOR(i, 0, N){
        string temp = P.substr(i, N);
        int s = (int)temp.size();
        result = max(kmp(temp, s), result);
    }
    cout << result << endl;
}