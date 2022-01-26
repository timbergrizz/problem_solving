#include <iostream>
#include <memory.h>
#define MOD 1000000000
using namespace std;

int N, K;
long long v[500][500];

int main() {
    memset(v, 0, sizeof v);
    cin >> N >> K;
    K = K + N - 1;

    v[0][0] = 1;
    for (int i = 1; i <= K; ++i) {
        v[i][0] = 1, v[i][i] = 1;
        for (int j = 1; j < i; ++j) v[i][j] = (v[i-1][j] + v[i-1][j-1]) % MOD;
    }
    cout << v[K][N] << "\n";
}