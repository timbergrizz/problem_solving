#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

int possible[10010];
int p[8], v[8];
int N, M, cnt{0};

void dfs(int n) {
    if (n == M) {
        for (int i = 0; i < M; ++i) {
            cout << p[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < N; ++i) {
        if(!possible[v[i]]) continue;

        p[n] = v[i], possible[v[i]]--;
        dfs(n + 1);
        possible[v[i]]++;
    }
}

int main() {
    memset(p, 0, sizeof(p));
    memset(v, 0, sizeof v);
    memset(possible, 0, sizeof possible);

    cin >> N >> M;
    int buf, n{0};

    for (int i = 0; i < N; ++i){
        cin >> buf;
        if(possible[buf] == 0) v[n++] = buf;
        possible[buf] += 1;
    }

    N = n;
    sort(v, v + n);

    dfs(0);
}