#include <bits/stdc++.h>

#define FOR(i, N) for(int i=1; i <= N; ++i)
using namespace std;


int N;

int v[501][501]{0,}, res[501][501]{0,};
int px[5]{0, 1, -1, 0, 0}, py[5]{0, 0, 0, 1, -1};

// 연산 때려맞출때 1억번이 1초다. 10억 아님.
// 모든 경우에 대해 DFS를 수행하면 시간 초과. 그리고 이 경우는 방향이 일정하게 정해질 수 있다. 더 큰 방향으로만 이동할 수 있기 때문.
// 그렇게 때문에 메모리제이션을 통해 이미 방문한 길에 대해서는 다시 조사를 하지 않고 처리한다.
int dfs(int i, int j) {
    if (res[i][j]) return res[i][j];

    // 배열에 경로 길이의 최댓값을 저장한 후, 다시 노드를 방문시 이를 확인하지 않고 저장한다.
    // dfs를 이용한 dp라고 생각하면 좋을 듯. 더이상 이동할 수 업는 노드까지 방문한 후, 그 위치부터 방문할 수 있는 경로의 최댓값을 갱신한다.
    res[i][j] = 1;
    FOR(n, 4) {
        int dx = i + px[n], dy = j + py[n];

        if (dx > N || dy > N || dx <= 0 || dy <= 0) continue;
        if (v[i][j] >= v[dx][dy]) continue;

//        cout << i << " " << j << " " << dx << " " << dy << "\n";
        //dp를
        res[i][j] = max(res[i][j], dfs(dx, dy) + 1);
    }

//    cout << i << " " << j << " " << res[i][j] << "\n";
    return res[i][j];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    FOR(i, N) {
        FOR(j, N) cin >> v[i][j];
    }

    int answer{0};
    FOR(i, N) {
        FOR(j, N) answer = max(dfs(i, j), answer);
    }
    cout << answer << "\n";
}