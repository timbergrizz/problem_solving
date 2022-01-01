#include <iostream>
#include <memory.h>
#include <queue>
#include <utility>
using namespace std;

int v[100][100];
bool visit[100][100];
int N, M;

typedef pair<int, int> pii;
int px[4] {1, -1, 0, 0};
int py[4] {0, 0, 1, -1};

int bfs(int x, int y){
    int counter{0};
    queue<pair<int, int>> q;
    visit[y][x] = true;
    q.push({x, y});

    while(!q.empty()){
        pii p = q.front();
        q.pop();
        ++counter;

        for(int i=0; i<4; ++i){
            int bufX = p.first + px[i], bufY = p.second + py[i];
            if(bufX < 0 || bufX >= N || bufY < 0 || bufY >= M) continue;
            //오타씨발
            if(visit[bufY][bufX] || v[bufY][bufX] != v[p.second][p.first]) continue;

            visit[bufY][bufX] = true;
            q.push({bufX, bufY});
        }
    }
    return counter * counter;
}


int main() {
    memset(v, 0, sizeof(v));
    memset(visit, 0, sizeof(visit));

    cin >> N >> M;
    char buf;

    for(int i=0; i<M; ++i){
        for(int j=0; j<N; ++j)
            cin >> buf, (buf == 'W' ? v[i][j] = 1: v[i][j] = 2);
    }

    int counter[3]{0, 0, 0};

    for(int i=0; i<M; ++i){
        for(int j=0; j< N; ++j){
            if(!visit[i][j])
                counter[v[i][j]] += bfs(j, i);
        }
    }
    cout << counter[1] << " " << counter[2] << "\n";
}