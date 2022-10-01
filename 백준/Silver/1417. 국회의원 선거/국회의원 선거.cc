#include <bits/stdc++.h>

#define FOR(i, N) for(int i=1; i<=N; ++i)
using namespace std;

int main() {
    int N, d, c1, cnt{0};
    cin >> N >> d;

    priority_queue<int> pq;
    FOR(i, N - 1) {
        cin >> c1;
        pq.push(c1);
    }

    while (pq.size() && pq.top() >= d) {
        int t = pq.top();
        pq.pop();
        d++, cnt++;
        pq.push(--t);
    }
    cout << cnt;

}