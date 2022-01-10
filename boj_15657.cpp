#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int buf[8], v[8];

void dfs(int len, int idx) {
    if (len == M) {
        for (int i = 0; i < M; ++i) cout << buf[i] << " ";
        cout << "\n";
        return;
    }

    for(int i = idx; i < N; ++i){
        buf[len] = v[i];
        dfs(len + 1, i);
    }
}

int main() {
    cin >> N >> M;
    for(int i=0; i<N; ++i) cin >> v[i];
    sort(v, v + N);
    dfs(0, 0);
}