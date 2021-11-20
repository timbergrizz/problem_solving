#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

vector<vector<int>> v;
int N, M;

const int pX[4] {1, -1, 0, 0};
const int pY[4] {0, 0, 1, -1};

bool check(int a, int b){
    return (a >= 0 && a < N && b >= 0 && b < M) ;
}

void bfs(vector<pair<int, int>> p, int counter){
    vector<pair<int, int>> n;
    for(int i=0; i < p.size(); ++i){
        for(int j=0; j<4; ++j){
            pair<int, int> c = p[i];
            c.first += pX[j], c.second += pY[j];

            if(check(c.first, c.second)){
                if(v[c.first][c.second] == 1){
                    v[c.first][c.second] = counter + 1;
                    n.push_back(c);
                }
            }
        }
    }

    if(!n.empty()) bfs(n, counter + 1);
}

int main(){
    cin >> N >> M;
    for(int i=0; i<N; ++i){
        v.push_back(vector<int>(M));
        string buf; cin >> buf;

        for(int k=0; k<M; ++k){
            v[i][k] = buf[k] - '0';
        }
    }
    v[0][0] = -1;
    bfs({{0, 0}}, 1);

    cout << v[N-1][M-1] << endl;
}