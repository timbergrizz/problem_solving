#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <iostream>
using namespace std;

vector<vector<int>> v(100001);
int parents[100001];
bool visit[100001];

void dfs(int n){
    for(int i=0; i<v[n].size(); ++i){
        int now = v[n][i];
        if(!visit[now]) {
            visit[now] = true, parents[now] = n;
            dfs(now);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;
    memset(visit, false, 100001);
    memset(parents, 0, 100001);

    for(int i=1; i<N; ++i){
        int n, c; cin >> n >> c;
        v[n].push_back(c);
        v[c].push_back(n);
    }

    dfs(1);
    for(int i=2; i<=N; ++i){
        cout << parents[i] << '\n';
    }
}