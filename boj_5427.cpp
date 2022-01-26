#include <iostream>
#include <queue>
#include <utility>
#include <memory.h>

using namespace std;

typedef pair<int, int> pii;

char v[1010][1010];
int visit[1010][1010], dx[4]{1, -1, 0, 0}, dy[4]{0, 0, 1, -1};
int w, h;

int bfs(pii s, queue<pii> &f) {
    queue<pii> sg;
    sg.push(s);

    while (!sg.empty()) {

        auto fsize{f.size()};

        while(fsize--){
            pii pos = f.front();
            f.pop();
            for (int i = 0; i < 4; ++i) {
                int bufx = pos.first + dx[i], bufy = pos.second + dy[i];
                if (v[bufx][bufy] == '#' || v[bufx][bufy] == '*') continue;
                if (bufx <= 0 || bufx >= h + 1 || bufy <= 0 || bufy >= w + 1) continue;
                v[bufx][bufy] = '*';
                f.push({bufx, bufy});
            }
        }

        auto possize {sg.size()};
        while(possize--){
            pii t = sg.front();
            sg.pop();

            if (t.first == 0 || t.first == h + 1 || t.second == 0 || t.second == w + 1) return visit[t.first][t.second];

            for (int i = 0; i < 4; ++i) {
                int bufx = t.first + dx[i], bufy = t.second + dy[i];
                if (bufx < 0 || bufx > h + 1 || bufy < 0 || bufy > w + 1) continue;
                if (v[bufx][bufy] == '*' || v[bufx][bufy] == '#' || visit[bufx][bufy]) continue;

                visit[bufx][bufy] = visit[t.first][t.second] + 1;
                sg.push({bufx, bufy});
            }
        }
    }
    return -1;
}


int main() {
    int T;
    cin >> T;
    while (T--) {
        memset(v, '.', sizeof v);
        memset(visit, 0, sizeof visit);

        cin >> w >> h;
        pii pos;
        queue<pii> fire;

        for (int i = 1; i <= h; ++i) {
            for (int j = 1; j <= w; ++j) {
                cin >> v[i][j];
                if (v[i][j] == '@') pos = {i, j};
                else if (v[i][j] == '*') fire.push({i, j});
            }
        }
        visit[pos.first][pos.second] = 1;
        int res = bfs(pos, fire);

        if(res == -1)  cout << "IMPOSSIBLE\n";
        else cout << res - 1 << "\n";
    }
}