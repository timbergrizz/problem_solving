#include <iostream>
#include <vector>
#include <utility>
using namespace std;

const int px[4] {1, -1, 0, 0};
const int py[4] {0, 0, 1, -1};

class Graph{
public:
    vector<vector<int>> v;
    int M, N;
    int counter;

    Graph(int _M, int _N){
        N = _N, M = _M;
        for(int i=0; i<M; ++i){
            v.push_back(vector<int>(N));
        }
        counter = 0;
    }

    bool check(int x, int y){
        if((x >= 0 && x < M) && (y >= 0 && y < N)) return v[x][y] == 0;
        else return false;
    }

    void bfs(vector<pair<int, int>> p){
        vector<pair<int, int>> n;
        ++counter;

        for(int i=0; i<p.size(); ++i){
            for(int j=0; j<4; ++j){
                int bufX = p[i].first + px[j], bufY = p[i].second + py[j];
                if(check(bufX, bufY)) {
                    v[bufX][bufY] = counter;
                    n.push_back({bufX, bufY});
                }
            }
        }

        if(!n.empty()) bfs(n);
    }

    bool checkSuccess(){
        for(int i = 0; i< M; ++i){
            for(int j=0; j<N; ++j){
                if(v[i][j] == 0) return false;
            }
        }
        return true;
    }
};

int main(){
    int N, M; cin >> N >> M;
    Graph g{M, N};

    vector<pair<int, int>> t;

    for(int i=0; i<M; ++i){
        for(int j=0; j<N; ++j){
            int buf; cin >> buf;
            g.v[i][j] = buf;
            if(buf == 1) t.push_back({i, j});
        }
    }

    g.bfs(t);


    if(g.checkSuccess()) cout << g.counter - 1 << endl;
    else cout << -1 << endl;
}