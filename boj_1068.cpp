#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < N; ++i)
using namespace std;

bool v[51][51]{false,};
bool visited[51]{false,};
int parent[51]{0,};

int bfs(int N, int root) {
    queue<int> q;
    q.push(root);
    int result{0};

    while (!q.empty()) {
        int f = q.front();
        bool flag{false};
        q.pop();

        for (int i = 0; i < N; ++i) {
            if (!v[f][i] || visited[i]) continue;
            visited[i] = flag = true;
            q.push(i);
        }
        if (!flag) result++;
    }
    return result;
}

int main() {
    int N;
    cin >> N;
    int par, root;

    FOR(i, N) {
        cin >> par;
        (par == -1 ? root = i : v[par][i] = true, parent[i] = par);
    }

    int er;
    cin >> er;
    if (er == root) cout << 0 << "\n";
    else {
        visited[er] = true;
        cout << bfs(N, root) << "\n";
    }
}