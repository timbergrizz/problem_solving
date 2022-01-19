#include <iostream>
#include <memory.h>
#include <queue>

using namespace std;

class pos {
public:
    int lay, row, col;

    pos(int x, int y, int z) {
        lay = x, row = y, col = z;
    }

    pos() {
        lay = 0, row = 0, col = 0;
    }
};

int l{1}, r{1}, c{1};

int v[30][30][30];
int pl[6]{1, -1, 0, 0, 0, 0}, pr[6]{0, 0, 1, -1, 0, 0}, pc[6]{0, 0, 0, 0, 1, -1};

void bfs(pos s) {
    queue<pos> q;
    q.push(s);

    while (!q.empty()) {
        pos f = q.front();
        q.pop();

        for (int i = 0; i < 6; ++i) {
            int bufL = f.lay + pl[i], bufR = f.row + pr[i], bufC = f.col + pc[i];
            if (bufL < 0 || bufL >= l) continue;
            if (bufR < 0 || bufR >= r) continue;
            if (bufC < 0 || bufC >= c) continue;
            if (v[bufL][bufR][bufC] != 0) continue;

            v[bufL][bufR][bufC] = v[f.lay][f.row][f.col] + 1;
            q.push({bufL, bufR, bufC});
        }
    }
}

int main() {
    while (true) {
        memset(v, 0, sizeof v);

        cin >> l >> r >> c;
        if (!l && !r && !c) break;

        string buf;
        pos start;
        pos ep;

        for (int i = 0; i < l; ++i) {
            for (int j = 0; j < r; ++j) {
                cin >> buf;
                for (int k = 0; k < c; ++k) {
                    if (buf[k] == '#') v[i][j][k] = -1;
                    if (buf[k] == 'S') start = pos(i, j, k);
                    if (buf[k] == 'E') ep = pos(i, j, k);
                }
            }
        }
        v[start.lay][start.row][start.col] = 1;
        bfs(start);

        if(v[ep.lay][ep.row][ep.col] > 0)
            cout << "Escaped in " << v[ep.lay][ep.row][ep.col] - 1 << " minute(s).\n";
        else cout << "Trapped!\n";
    }
}