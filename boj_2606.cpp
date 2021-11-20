#include <iostream>
#include <vector>
using namespace std;

class Graph{
public:
    vector<vector<int>> v;
    int N;
    int counter;

    Graph(int _N){
        N = _N;
        for(int i=0; i<N; ++i){
            v.push_back(vector<int> (N));
            v[i][i] = 1;
        }
    }

    void connect(int f, int s){
        v[f][s] = v[s][f] = 1;
    }

    void dfs(int n){
        for(int i=0; i<N; ++i){
            if(v[n][i] != 0 && v[i][i] != 0){
                v[n][i] = v[i][n] = 0;
                dfs(i);
            }
        }
    }

    int getResult(){
        int counter{0};
        for(int i=0; i<N; ++i){
            if(v[i][i] == 0) ++counter;
        }
        return counter - 1;
    }
};

int main(){
    int T; cin >> T;
    Graph g{T};
    int C; cin >> C;

    while(C--){
        int fir, sec; cin >> fir >> sec;
        g.connect(fir - 1, sec - 1);
    }

    g.dfs(0);
    cout << g.getResult() << endl;
}