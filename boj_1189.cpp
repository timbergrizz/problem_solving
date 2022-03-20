#include <bits/stdc++.h>

using namespace std;

bool v[5][5]{false, };
int dx[4]{1, -1, 0, 0}, dy[4]{0, 0, 1, -1};
bool visited[5][5]{false, };
int R, C, K, answer{0};

void dfs(int y, int x, int dist){
//    cout << y << " " << x<< "\n";
    if(y == 0 && x == C - 1){
//        cout << dist << endl;
        if(dist == K) answer++;
        return;
    }

    for(int i=0; i < 4; ++i) {
        int px = x + dx[i], py = y + dy[i];
        if(px < 0 || px >= C || py < 0 || py >= R) continue;
        if(!v[py][px] || visited[py][px]) continue;

        visited[py][px] = true;
        dfs(py, px, dist + 1);
        visited[py][px] = false;
    }
}

int main() {
    cin >> R >> C >> K;
    string str;
    for(int i=0; i < R; ++i){
        cin >> str;
        for(int j=0; j < C; ++j) (str[j] == '.' ? v[i][j] = true : v[i][j] = false);
    }
    visited[R-1][0] = true;
    dfs(R-1, 0, 1);
    cout << answer << "\n";
}