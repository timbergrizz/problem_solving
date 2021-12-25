#include <iostream>
#include <memory.h>
using namespace std;

int c[8];
int N, M;
int cnt{0};
bool visit[9];

void dfs(int n){
    if(cnt == M){
        for(int i=0 ; i < M; ++i) cout << c[i] << " ";
        cout << endl;
        return;
    }

    for(int i = n + 1; i <= N; ++i){
        if(!visit[i]){
            visit[i] = true, c[cnt++] = i;
            dfs(i);
            visit[i] = false, cnt--;
        }
    }
}
int main(){
    memset(c, 0, sizeof(c));
    memset(visit, false, sizeof(c));
    cin >> N >> M;
    dfs(0);
}