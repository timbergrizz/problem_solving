#include <iostream>
#include <queue>

using namespace std;

int K;
int v[100001];
bool visit[100001];

void bfs(int n) {
    queue<int> q;
    q.push(n);

    while (!q.empty()) {
        int X = q.front();
        q.pop();

        int pos[2]{X + 1, X - 1};
        for (int p: pos) {
            if (p < 0 || p > 100000) continue;
            if (visit[p] && v[p] <= v[X] + 1) continue;
            visit[p] = true, v[p] = v[X] + 1;
            q.push(p);
        }

        if(X * 2 > 100000 || X * 2 < 0)  continue;
        if (visit[X * 2] && v[X * 2] <= v[X]) continue;
        visit[X * 2] = true, v[X * 2] = v[X];
        q.push(X * 2);
    }
}

int main() {
    int N; cin >> N >> K;
    visit[N] = true;
    bfs(N);
    cout << v[K] << "\n";
}