#include <iostream>
#include <algorithm>
using namespace std;
int inp[6], v[14], visit[14];
int N{0};

void dfs(int idx, int n){
    if(n == 6){
        for(int i=0; i<6; ++i) cout << inp[i] << " ";
        cout << "\n";
        return;
    }

    for(int i = idx + 1; i <= N; ++i){
//        cout << i << v[i] << endl;
        inp[n] = v[i];
        dfs(i, n + 1);
    }
}

int main() {
    cin >> N;
    while(N){
        for(int i=1; i<=N; ++i) cin >> v[i];
        dfs(0, 0);
        cin >> N;
        cout << "\n";
    }
}