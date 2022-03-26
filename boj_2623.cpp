#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

void topologySort(const vector<vi> &v, vi &inDegree, int N) {
    //위상 정렬은 큐든 우선순위 큐든 뭐든 하나씩 순서대로 정렬해나가면 오케이다.
    //시작점은 들어오는 vertex가 없는 노드들부터
    queue<int> q;
    for (int i = 1; i <= N; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    queue<int> result;
    while (!q.empty()) {
        //큐 제일 앞에 원소를 가져온다.
        int cur = q.front();
        q.pop();

        // 연결된 vertex들을 하나씩 지우고, 다 연결된걸 큐에 추가한다.
        for (int i: v[cur]) {
            if (--inDegree[i] == 0) q.push(i);
        }
        result.push(cur);
    }

    // N개의 노드를 방문했으면, 큐에 N개의 element가 있을 것이다.
    // 없으면 정렬이 불가능한것으로, 0을 출력하고 끝낸다.
    if (result.size() != N) {
        cout << 0 << "\n";
        return;
    }
    // 순서대로 출력
    while (!result.empty()) {
        cout << result.front() << "\n";
        result.pop();
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vi> v(N + 1);
    vi inDegree(N + 1);

    while (M--) {
        int cnt;
        cin >> cnt;

        vector<int> order(cnt);
        for (int &i: order) cin >> i;

        for (int i = 0; i < cnt - 1; ++i) {
            v[order[i]].push_back(order[i + 1]);
            inDegree[order[i + 1]]++;
        }
    }

    topologySort(v, inDegree, N);
}