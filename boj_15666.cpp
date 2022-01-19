#include <iostream>
#include <memory.h>

using namespace std;

bool m[10001];
int N, M, cnt{0};
int v[8], res[8];

void dfs(int n, int idx){
    if(n == M) {
        for(int i=0; i < M; ++i) cout << res[i] << " ";
        cout << "\n";
        return;
    }

    for(int i=idx; i < cnt; ++i){
        res[n] = v[i];
        dfs(n + 1, i);
    }
}

int main() {
    memset(v, 0, sizeof v);
    memset(m, 0, sizeof m);
    memset(res, 0, sizeof res);

    cin >> N >> M;
    int buf;

    for (int i = 0; i < N; ++i) {
        cin >> buf;
        m[buf] = true;
    }

    for(int i=1; i <= 10000; ++i)
        if(m[i]) v[cnt++] = i;

    dfs(0, 0);
}