#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int v[51][51]{0};
int dx[8] {1, -1, 0, 0, 1, -1, 1, -1};
int dy[8] {0, 0, 1, -1, 1, 1, -1, -1};
int w, h;

void bfs(int x, int y){
    queue<pair<int, int>> n;
    n.push({x, y});
    v[x][y] = 0;

    while(!n.empty()){
        pair<int, int> b = n.front();
        n.pop();

        for(int i=0; i<8; ++i){
            int bx = b.first + dx[i], by = b.second + dy[i];
            if(bx >= 0 && bx < w && by >= 0 && by < h){
                if(v[bx][by] == 1) {
                    n.push({bx, by});
                    v[bx][by] = 0;
                }
            }
        }
    }
}

int main(){
    while(true){
        cin >> h >> w;
        if(w == 0 && h == 0) break;

        for(int i{0}; i < w; ++i){
            for(int j{0}; j < h; ++j) cin >> v[i][j];
        }

        int counter{0};
        for(int i{0}; i < w; ++i){
            for(int j{0}; j<h; ++j){
                if(v[i][j] == 1){
                    bfs(i, j);
                    ++counter;
                }
            }
        }
        cout << counter << "\n";
    }
}