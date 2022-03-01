#include <bits/stdc++.h>

#define FOR(i, N) for(int i=1; i <= N; ++i)
#define INF 501
using namespace std;

int N;
bool v[501][501]{false,};
int res[501][501]{0,}, isConnected[501];

int floyd_warshall() {
    FOR(i, N) {
        FOR(j, N) {
            if (i == j) res[i][j] = 0;
            else if (!v[i][j]) res[i][j] = INF;
            else res[i][j] = 1;
        }
    }

    FOR(k, N) {
        FOR(i, N) {
            FOR(j, N) {
                res[i][j] = min(res[i][j], res[i][k] + res[k][j]);
//                cout << i << " " << k << " "<< j << " " << res[i][k] << " " << res[k][j] << endl;
            }
        }
    }

    int answer{0};
    FOR(i, N) {
        FOR(j, N) {
            // 모든 위치 관계가 파악된 사람을 센다
            // 한 노드에 대해 다른 노드와 모두 연결되어있는지 확인하고,
            if (res[i][j] != INF) {
                if (i == j) continue;
                isConnected[i]++, isConnected[j]++;
                if (isConnected[i] == N - 1) answer++;
                if (isConnected[j] == N - 1) answer++;
            }
        }
    }
    return answer;
}

int main() {
    int M;
    cin >> N >> M;

    int fir, sec, dist;
    while (M--) {
        cin >> fir >> sec;
        v[fir][sec] = true;
    }

    cout << floyd_warshall() << '\n';
}