#include <iostream>
#include <queue>
#include <utility>
#include <memory.h>
using namespace std;

int v[300][300];
int I;
int px[8]{1, 2, 2, 1, -1, -2, -2, -1};
int py[8]{2, 1, -1, -2, 2, 1, -1, -2};

pair<int, int> target;

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});

    while (!q.empty()) {
        pair<int, int> t = q.front();
        q.pop();

        if(t == target) return;
        for(int i=0; i<8; ++i){
            int bufX = t.first + px[i], bufY = t.second + py[i];
            if(bufX < 0 || bufX >= I || bufY < 0 || bufY >= I) continue;
            if(v[bufX][bufY] != 0) continue;

            v[bufX][bufY] = v[t.first][t.second] + 1;
            q.push({bufX, bufY});
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        memset(v, 0, sizeof(v));
        cin >> I;
        int x, y; cin >> x >> y >> target.first >> target.second;
        v[x][y] = 1;
        bfs(x, y);
        cout << v[target.first][target.second] - 1 << endl;
    }
}