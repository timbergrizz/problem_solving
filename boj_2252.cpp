#include <bits/stdc++.h>

#define FOR(i, N) for(int i=1; i <= N; ++i)
using namespace std;

typedef vector<int> vi;

void topology_sort(const vector<vi> &v, vi &inDegree, int N) {
    queue<int> q;
    FOR(i, N){
        if(inDegree[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i : v[cur]){
            if(--inDegree[i] == 0)  q.push(i);
        }
        cout << cur << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<vi> v(N + 1);
    vi inDegree(N + 1);

    int fir, sec;
    FOR(i, M) {
        cin >> fir >> sec;
        v[fir].push_back(sec);
        inDegree[sec]++;
    }

    topology_sort(v, inDegree, N);
}