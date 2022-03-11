#include <bits/stdc++.h>

using namespace std;

bool v[101][101]{0,};
int dist[101] {0,};
int N;

int bfs(int n, int target) {
    queue<int> q;
    q.push(n);
    while (!q.empty()) {
        int f = q.front();
        q.pop();

        if(f == target) return dist[target] - 1;

        for(int i=1; i <= N; ++i){
            if(!v[f][i] || dist[i]) continue;

            dist[i] = dist[f] + 1;
            q.push(i);
        }
    }
    return -1;
}

int main() {
    cin >> N;

    pair<int, int> calc;
    cin >> calc.first >> calc.second;

    int m;
    cin >> m;

    int fir, sec;
    while (m--) {
        cin >> fir >> sec;
        v[fir][sec] = v[sec][fir] = true;
    }

    dist[calc.first] = 1;
    cout << bfs(calc.first, calc.second) << "\n";
}