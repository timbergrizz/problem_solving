#include <iostream>
#include <queue>
#include <memory.h>
#include <vector>

using namespace std;

bool meet[51][51];
bool visit[51];
vector<int> know;
int N, M;

void bfs() {
    queue<int> q;
    for (int i: know) q.push(i);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int i = 1; i <= N; ++i) {
            if (meet[v][i] && !visit[i]) {
                visit[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int buf;
        cin >> buf;
        know.push_back(buf);
        visit[buf] = true;
    }

    vector<vector<int>> party(M, vector<int>());
    for (int i = 0; i < M; ++i) {
        int s;
        cin >> s;
        int buf;

        for (int j = 0; j < s; ++j) {
            cin >> buf;
            party[i].push_back(buf);
        }

        for (int j = 0; j < s; ++j) {
            for (int k = j; k < s; ++k) {
                meet[party[i][j]][party[i][k]] = meet[party[i][k]][party[i][j]] = true;
            }
        }
    }

    bfs();

    int res{M};
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < party[i].size(); ++j) {
            if (visit[party[i][j]]) {
                --res;
                break;
            }
        }
    }
    cout << res << "\n";
}