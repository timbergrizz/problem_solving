//baekjun_1260
#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> & graph, int num){
    if(graph[num][num] == 0){
        return;
    }

    graph[num][num] = 0;

    cout << num + 1 << " ";

    for(int i=0; i< graph.size(); ++i){
        if(graph[num][i] != 0 && i != num) {
            graph[num][i] = graph[i][num] = 0;
            dfs(graph, i);
        }
    }
}

void bfs(vector<vector<int>> & graph, vector<int> num){
    vector<int> nextNum;
    //    cout << "test" << endl;

    for(int i=0; i<num.size(); ++i){
        int currentNum = num[i];
        if(graph[currentNum][currentNum] == 0) continue;

        graph[currentNum][currentNum] = 0;
        cout << currentNum + 1 << " ";

        for(int j=0; j < graph.size(); ++j){
            if(graph[j][currentNum] == 1 && graph[j][j] != 0){
                //                cout << j << endl;
                graph[j][currentNum] = graph[currentNum][j] = 0;
                nextNum.push_back(j);
            }
        }
    }

    if(!nextNum.empty()) bfs(graph, nextNum);
}


int main(){
    int N, M, V; cin >> N >> M >> V;
    vector<vector<int>> dfsGraph(N, vector<int>(N, 0 ));
    vector<vector<int>> bfsGraph(N, vector<int>(N, 0 ));


    for(int i=0; i<N; ++i){
        dfsGraph[i][i] = 1;
        bfsGraph[i][i] = 1;
    }
    for (int i=0; i<M; ++i) {
        int fir, sec; cin >> fir >> sec;
        dfsGraph[fir - 1][sec - 1] = dfsGraph[sec - 1][fir - 1] = 1;
        bfsGraph[fir - 1][sec - 1] = bfsGraph[sec - 1][fir - 1] = 1;
    }

    dfs(dfsGraph, V - 1);
    cout << endl;
    vector<int> test{V-1};
    bfs(bfsGraph, test);
}