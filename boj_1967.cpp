#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;

vector<vector<pair<int, int>>> v(10001);
bool visit[10001];
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

    for(int i=1; i<N; ++i){
        int f, s, d; cin >> f >> s >> d;
        v[f].push_back({s, d});
        v[s].push_back({f, d});
    };

    visit[1] = true;
    dfs(1);
    cout << result << "\n";
}