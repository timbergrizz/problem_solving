#include <bits/stdc++.h>
#define FOR(i, N) for(int i=1; i<=N; ++i)
using namespace std;

int v1[101][101]{0, }, v2[101][101]{0, }, v[101][101]{0, };

int main(){
    int N, M, K;
    cin >> N >> M;
    FOR(i,  N) FOR(j, M) cin >> v1[i][j];

    cin >> M >> K;
    FOR(i, M) FOR(j, K) cin >> v2[i][j];

    FOR(i, N){
        FOR(j, K) {
            FOR(k, M) v[i][j] += v1[i][k] * v2[k][j];
        }
    }

    FOR(i, N){
        FOR(j, K) cout << v[i][j] << " ";
        cout << "\n";
    }
}