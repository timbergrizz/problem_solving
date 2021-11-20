#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;

vector<vector<pair<int, int>>> v(100001);
bool visit[100001];
int result{0};

int dfs(int n){
    int Max{0}, secMax{0}, buf{0};

    for(int i=0; i<v[n].size(); ++i){
        pair<int, int> bb = v[n][i];
        if(!visit[bb.first]){
            visit[bb.first] = true;

            buf = dfs(bb.first) + bb.second;
            if(buf > Max) swap(buf, Max);
            if(buf > secMax) swap(buf, secMax);
        }
    }

    result = max(result, Max + secMax);
    return Max;
}

int main(){
    int N; cin >> N;
    memset(visit, false, 10001);

    int V;
    for(int i=0; i<N; ++i){
        cin >> V;
        int inp1{0}, inp2{0};
        while(true){
            cin >> inp1;
            if(inp1 == -1) break;
            cin >> inp2;
            v[V].push_back({inp1, inp2});
            v[inp1].push_back({V, inp2});
        }
    }

    visit[1] = true;
    dfs(1);

    cout << result << "\n";
}