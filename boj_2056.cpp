#include <bits/stdc++.h>
#define FOR(i, n) for(int i=1; i <= n; ++i)
using namespace std;

typedef vector<int> vi;

int topology_sort(const vector<vi> &v, vi &inDegree, vi &time, int N){
    queue<int> q;
    vi result(N + 1);
    int answer{0};

    FOR(i, N){
        if(inDegree[i] == 0) {
            q.push(i);
            result[i] = time[i];
        }
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        answer = max(answer, result[cur]);

        for(int i : v[cur]){
            result[i] = max(result[i], result[cur] + time[i]);
            if(--inDegree[i] == 0) q.push(i);
        }
    }
    return answer;
}

int main(){
    int N; cin >> N;
    int fir, sec, buf;
    vector<vi> v(N + 1);
    vi inDegree(N + 1);
    vi time(N + 1);

    FOR(i, N) {
        cin >> fir >> sec;
        time[i] = fir;
        FOR(j, sec){
            cin >> buf;
            inDegree[i]++, v[buf].push_back(i);
        }
    }

    cout << topology_sort(v, inDegree, time, N) << "\n";
}