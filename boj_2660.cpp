#include <bits/stdc++.h>
#define INF 1e9
#define FOR(i, n) for(int i=1; i <= n ; ++i)
using namespace std;

void floyd_warshall(vector<vector<int>> &result, int N){
    FOR(k, N){
        FOR(i, N){
            FOR(j, N) result[i][j] = min(result[i][j], result[i][k] + result[k][j]);
        }
    }
}

int main() {
    int N;
    cin >> N;
    int fir, sec;

    vector<vector<int>> result(N + 1, vector<int>(N + 1, INF));
    while (true) {
        cin >> fir >> sec;
        if (fir == -1 && sec == -1) break;

        result[fir][sec] = result[sec][fir] = 1;
    }
    for(int i=1; i < N; ++i) result[i][i] = 0;

    floyd_warshall(result, N);

    vector<int> score(N + 1);
    int minScore{(int) N + 10};

    FOR(i, N){
        FOR(j, N) {
            if(i == j) continue;
            score[i] = max(score[i], result[i][j]);
        }
        minScore = min(score[i], minScore);
    }
    if(minScore == N + 10) minScore = 0;

    queue<int> q;
    FOR(i, N) if(minScore == score[i]) q.push(i);

    cout << minScore << " " << q.size() << "\n";
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";
}