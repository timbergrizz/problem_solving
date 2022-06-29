#include <bits/stdc++.h>

#define FOR(i, N) for(int i=1; i <=N; ++i)
using namespace std;

int a[101][101]{0,};

int main() {
    int N, M, c1;
    cin >> M >> N;

    FOR(k, M) {
        FOR(i, N) cin >> a[k][i];
    }
    FOR(k, M){
        FOR(i, N) {
            cin >> c1;
            a[k][i] += c1;
        }
    }

    FOR(k, M){
        FOR(i, N) cout << a[k][i] << " ";
        cout << "\n";
    }
}