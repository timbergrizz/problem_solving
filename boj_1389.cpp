#include <iostream>
#include <vector>
using namespace std;

class Graph{
public:
    vector<vector<int>> v;
    int N;
    Graph(int _N){
        N = _N;
        for(int i=0; i<N; ++i){
            v.push_back(vector<int>(N));
            v[i][i] = -1;
        }
    }

    void connect(int a, int b){
        v[a][b] = v[b][a] = 1;
    }

    int dist_calc(){
        int min = 0, minIdx = 0;
        for(int i=0; i<N; ++i){
            for(int i=0; i<N; ++i){
                v[i][i] = -1;
            }
            vector<int> p{i};
            v[i][i] = 0;
            bfs(p, 0);

            int sum = 0;
            for(int i=0; i<N; ++i){
                //                cout << v[i][i] << " ";
                sum += v[i][i];
            }
            //            cout << sum << endl << endl;
            if(min == 0) min = sum, minIdx = i;
            else if(min > sum) min = sum, minIdx = i;
        }

        return minIdx;
    }

    void bfs(vector<int> p, int counter){
        vector<int> n;
        for(int i=0; i<p.size(); ++i){
            for(int j=0; j<N; ++j){
                if(v[p[i]][j] == 1 && v[j][j] == -1){
                    //                    cout << p[i] << j << endl;
                    v[j][j] = counter + 1;
                    n.push_back(j);
                }
            }
        }
        if(!n.empty()) bfs(n, counter + 1);
    }
};

int main(){
    int N, M; cin >> N >> M;
    Graph g{N};

    for(int i=0; i<M; ++i){
        int fir, sec; cin >> fir >> sec;
        g.connect(fir - 1, sec - 1);
    }
    cout << g.dist_calc() + 1 << endl;
}