#include <bits/stdc++.h>

using namespace std;

bool v[501][501]{false,};
int visited[501]{0, 1,};
int N;

int bfs() {
    queue<int> q;
    q.push(1);

    int counter{0};
    while (!q.empty()) {
        int f = q.front();
        if (visited[f] > 3) break;
        counter++;
        q.pop();

        for (int i = 1; i <= N; ++i) {
            if (!v[f][i] || !v[i][f]) continue;
            if (visited[i]) continue;

            visited[i] = visited[f] + 1;
            q.push(i);
        }
    }
    return counter - 1;
}


int main() {
    cin >> N;
    int M;
    cin >> M;

    int fir, sec;
    while (M--) {
        cin >> fir >> sec;
        v[fir][sec] = v[sec][fir] = true;
    }

    int answer = bfs();
    cout << answer << endl;
}