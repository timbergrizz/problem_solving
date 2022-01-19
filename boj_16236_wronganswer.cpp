#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <memory.h>

using namespace std;
typedef pair<int, int> pii;

vector<vector<pii>> pos;
int v[20][20];
int distt[20][20];
int sharksize{2}, cnt{0}, dist{0}, N{0};
int px[4]{1, -1, 0, 0}, py[4]{0, 0, 1, -1};

void bfs(pii p) {
    queue<pii> q;
    q.push(p);

    while (!q.empty()) {
        pii top = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int bufX = top.first + px[i], bufY = top.second + py[i];
            if (bufX < 0 || bufX >= N || bufY < 0 || bufY >= N) continue;
            if ((v[bufX][bufY] > sharksize && v[bufX][bufY] != 9)|| distt[bufX][bufY] != 0) continue;

            distt[bufX][bufY] = distt[top.first][top.second] + 1;
            q.push({bufX, bufY});
        }
    }
}

bool min(pii a, pii b) {
    if (b.first == 50) return true;
    int posA{distt[a.first][a.second]}, posB{distt[b.first][b.second]};

    if (posA == posB) {
        if (a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    }

    return posA < posB;
}

void dfs(pii p) {
//    cout << p.first << " " << p.second << " || \n";

    pii minV{50, 50};

    int minX, minY;

    memset(distt, 0, sizeof(distt));
    distt[p.first][p.second] = 1;
    bfs(p);

    for (int i = 1; i < std::min(7, sharksize); ++i) {
        for (int j = 0; j < pos[i].size(); ++j) {
//            cout << distt[pos[i][j].first][pos[i][j].second] << " : " << i << " (" << pos[i][j].first << ", "
//                 << pos[i][j].second
//                 << ")  \n";

            if (pos[i][j] != pii(-1, -1) && min(pos[i][j], minV)) {
                minV = pos[i][j], minX = i, minY = j;
            }
        }
    }

    if (minV == pii(50, 50)) return;
    pos[minX].erase(pos[minX].begin() + minY);
    dist += (distt[minV.first][minV.second] - 1);
//    cout << distt[minV.first][minV.second] - 1 << " ";
    if (++cnt == sharksize) cnt = 0, ++sharksize;
//    cout << size << " " << cnt << endl;

    dfs(minV);
}

int main() {
    cin >> N;
    pos.resize(10);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> v[i][j];
            if (v[i][j]) pos[v[i][j]].push_back({i, j});
        }
    }

    dfs(pos[9][0]);
    cout << dist << "\n";
}