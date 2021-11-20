//boj_11724
#include <iostream>
#include <vector>
using namespace std;

class Graph{
    vector<vector<int>> v;
    int N;
    int result;
public:
    Graph(int _N){
        N = _N, result = 0;
        for(int i=0; i<N; ++i) {
            v.push_back(vector<int>(N));
            v[i][i] = 1;
        }
    }

    void connect(int fir, int sec) {
        v[fir][sec] = v[sec][fir] = 1;
    }

    int find(){
        for(int i=0; i<N; ++i){
            if(v[i][i] == 1){
                ++result;
                dfs(i);
            }
        }
        return result;
    }

    void dfs(int i){
        v[i][i] = 0;
        for(int j=0; j<N; ++j){
            if(v[i][j] == 1 && i != j){
                v[i][j] = v[j][i] = 0;

                if(v[j][j] != 0){
                    dfs(j);
                }
            }
        }
    }
};
int main(){
    int N, M; cin >> N >> M;
    Graph gp{N};
    for(int i=0; i<M; ++i){
        int fir, sec; cin >> fir >> sec;
        gp.connect(fir - 1, sec - 1);
    }

    cout << gp.find() << endl;
}