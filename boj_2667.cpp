#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int v[25][25];
int N;
int dX[4]{1, -1, 0, 0};
int dY[4]{0, 0, -1, 1};

int counter{0};
void bfs(int x, int y){
    queue<pair<int, int>> n;
    n.push({x, y});
    v[x][y] = counter * (-1);

    while(!n.empty()){
        pair<int, int> buf = n.front();
        n.pop();

        for(int j=0; j<4; ++j){
            int bX = buf.first + dX[j], bY = buf.second + dY[j];
            if(bX >= 0 && bX < N && bY >= 0 && bY < N){
                if(v[bX][bY] == 1){
                    v[bX][bY] = counter * (-1);
                    n.push({bX, bY});
                }
            }
        }
    }

    //    for(int i=0; i<p.size(); ++i){
    //        for(int j=0; j<4; ++j){
    //            int bX = p[i].first + dX[j], bY = p[i].second + dY[j];
    //            if(bX >= 0 && bX < N && bY >= 0 && bY < N){
    //                if(v[bX][bY] == 1){
    //                    v[bX][bY] = counter * (-1);
    //                    n.push_back({bX, bY});
    //                }
    //            }
    //        }
    //    }

}

int main(){
    cin >> N;

    string buf;
    for(int i=0; i<N; ++i){
        cin >> buf;
        for(int j=0; j<N; ++j) v[i][j] = buf[j] - '0';
    }

    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            if(v[i][j] == 1) {
                ++counter;
                bfs(i, j);
            }
        }
    }

    vector<int> b(counter);
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            if(v[i][j] != 0) b[v[i][j] * (-1) -1] += 1;
        }
    }
    sort(b.begin(), b.end());
    cout << counter << '\n';

    for(int i=0; i<counter; ++i){
        cout << b[i] << '\n';
    }
}