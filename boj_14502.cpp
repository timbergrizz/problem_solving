#include <iostream>
#include <vector>
#include <memory.h>
#include <queue>

using namespace std;

struct pos {
    int x, y;
};

int N, M, answer{0};
int v[8][8], dx[4]{1, -1, 0, 0}, dy[4]{0, 0, 1, -1};
bool spread[8][8];

vector<pos> virus;

void dfs() {
    queue<pos> q;
    for (pos i: virus){
        q.push(i);
        spread[i.x][i.y] = true;
    }

    while (!q.empty()) {
        pos f = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int bufX = f.x + dx[i], bufY = f.y + dy[i];
            if(bufX < 0 || bufX >= N || bufY < 0 || bufY >= M) continue;
            if(v[bufX][bufY] == 1) continue;
            if(spread[bufX][bufY]) continue;

            spread[bufX][bufY] = true;
            q.push({bufX, bufY});
        }
    }
}

void setWalls(int n) {
    if (n == 3) {
        memset(spread, 0, sizeof spread);
        dfs();

        int cnt{0};
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
//                cout << v[i][j] << " ";
                if (!spread[i][j] && !v[i][j]) cnt += 1;
            }
//            cout << "\n";
        }

//        cout << cnt << "\n\n";

        answer = max(cnt, answer);
        return;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (v[i][j] != 0) continue;
            v[i][j] = 1;
            setWalls(n + 1);
            v[i][j] = 0;
        }
    }
}

int main() {
    cin >> N >> M;
    for(int i=0; i < N; ++i){
        for(int j=0; j < M; ++j){
            cin >> v[i][j];
            if(v[i][j] == 2) virus.push_back({i, j});
        }
    }
    setWalls(0);
    cout << answer << "\n";
}