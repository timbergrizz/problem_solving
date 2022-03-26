#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

void topology(const vector<vi> &v, vi &inDegree, int N) {
    // 이 문제같은 경우, 쉬운 문제를 먼저 풀어야 하고, 값이 작을수록 쉬운 문제이기 때문에 우선순위 큐를 사용한다.
    priority_queue<int, vector<int>, greater<int>> pq;
    // inDegree값이 0인 지역부터 출발한다.
    // 따라서 이를 다 확인해주자.
    for (int i = 1; i <= N; ++i) {
        if (!inDegree[i]) pq.push(i);
    }

    // 이문제는 항상 정렬됨이 보장되기 때문에 priority queue로 구현되었다.
    while (!pq.empty()) {
        int cur = pq.top();
        pq.pop();

        for (int i: v[cur]) {
            // 현재 노드에서 방문할 수 있는 노드들을 다 방문한다. 방문은 inDegree값을 지워 이루어진다.
            // 이때 inDegree값이 0이면 pq에 삽입한다.
            if (--inDegree[i] == 0) {
                pq.push(i);
            }
        }

        cout << cur << " ";
    }
}

int main() {
    int N, K;
    cin >> N >> K;
    // 그래프를 바탕으로 정렬을 진행하는거다
    // 그래프의 연결을 바탕으로 정렬을 진행한다.
    vector<vi> v(N + 1);
    vi inDegree(N + 1);

    int fir, sec;
    for (int i = 0; i < K; ++i) {
        // 그래프 순회 문제와 동일하게 그래프의 연결을 입력받는다.
        // 이때 방향성이 있다.
        cin >> fir >> sec;
        v[fir].push_back(sec);
        // 또한 들어가는 경로의 수를 기록해두었다가 이를 사용한다.
        ++inDegree[sec];
    }
    topology(v, inDegree, N);
    cout << "\n";
}