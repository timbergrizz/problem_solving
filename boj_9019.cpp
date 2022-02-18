#include <bits/stdc++.h>

#define MOD 10000
using namespace std;

int B;
bool visited[MOD]{false,};
const string v = "DSLR";

void bfs(int N) {
    queue<pair<int, string>> q;
    q.push({N, ""});

    while (!q.empty()) {
        auto f = q.front();
        q.pop();
        int val = f.first;

        if (val == B){
            cout << f.second << "\n";
            return;
        }

        int pn[4]{(val * 2) % MOD, (val == 0 ? 9999 : val - 1), (val % 1000) * 10 + val / 1000,
                  (val % 10) * 1000 + (val / 10)};

        for (int i = 0; i < 4; ++i) {
            if (visited[pn[i]]) continue;
            visited[pn[i]] = true;
            q.push({pn[i], f.second + v[i]});
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        memset(visited, false, sizeof visited);
        int A;
        cin >> A >> B;
        bfs(A);
    }
}