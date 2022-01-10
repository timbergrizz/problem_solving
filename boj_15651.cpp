#include <iostream>
using namespace std;

int N, M;
int v[7];
void dfs(int idx){
    if(idx == M){
        for(int i=0; i<M; ++i) cout << v[i] << " ";
        cout << "\n";
        return;
    }

    for(int i=1; i<= N; ++i){
        v[idx] = i;
        dfs(idx + 1);
    }
}

int main(){
    cin >> N >> M;
    dfs(0);
}