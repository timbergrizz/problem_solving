#include <iostream>

using namespace std;

int v[1001][1001]{0, 0, };

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        for(int j=1; j <= M; ++j) cin >> v[i][j];
    }

    for(int i=1; i<=N; ++i){
        for(int j=1; j<=M; ++j){
            v[i][j] = max(max(v[i-1][j-1] , v[i-1][j]), v[i][j-1]) + v[i][j];
        }
    }
    cout << v[N][M] << "\n";
}