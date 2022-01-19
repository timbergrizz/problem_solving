#include <iostream>
#include <memory.h>
#include <vector>

using namespace std;

vector<vector<int>> v;
bool visit[10001];
int P[10001];
int N, res;

int dfs(int p) {
    visit[p] = true;
    int cnt{0};

    for (int i = 0; i < v[p].size(); ++i) {
        int next = v[p][i];
        if(!visit[v[p][i]]) cnt += dfs(next);
    }
//    cout << p << " : " << 1 + cnt << endl;
    return 1 + cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int M;
    cin >> N >> M;
    int f, s;
    v = vector<vector<int>>(N + 1);

    while (M--) {
        cin >> f >> s;
        v[s].push_back(f);
    }


    for (int i = 1; i <= N; ++i) {
        memset(visit, false, sizeof visit);
        P[i] = dfs(i);
        if (res < P[i]) res = P[i];
//        cout << P[i] << " ";
    }

    for (int i = 1; i <= N; ++i) {
        if (res == P[i]) cout << i << " ";
    }

    cout << '\n';
}