#include <iostream>

using namespace std;

bool visit[27];
bool visited[20][20];
int v[20][20];
int maxCnt{1};
int cnt{1};
int R, C;
int posX[4] {1, -1, 0, 0}, posY[4]{0, 0, 1, -1};

void dfs(int x, int y) {
    for(int i=0; i<4; ++i){
        int bufX = x + posX[i], bufY = y + posY[i];
        if(bufX >= 0 && bufX < C && bufY >= 0 && bufY < R){
            if(!visited[bufY][bufX] && !visit[v[bufY][bufX]]) {
                visited[bufY][bufX] = visit[v[bufY][bufX]] = true, cnt++;
                if(cnt > maxCnt) maxCnt = cnt;
                dfs(bufX, bufY);
                cnt--, visited[bufY][bufX] = visit[v[bufY][bufX]] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C;
    string buf;
    for (int i = 0; i < R; ++i) {
        cin >> buf;
        for (int j = 0; j < C; ++j) v[i][j] = buf[j] - 'A' + 1;
    }
    visited[0][0] = visit[v[0][0]] = true;
    dfs(0, 0);
    cout << maxCnt << "\n";
}