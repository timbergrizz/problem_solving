#include <bits/stdc++.h>

#define FOR(i, N) for(int i=1; i<=N; ++i)
using namespace std;

typedef pair<int, int> pii;

int main() {
    priority_queue<pii> pq;
    int c1, c2, tot{0};
    FOR(i, 8){
        cin >> c1;
        pq.push({c1, i});
    }

    priority_queue<int, vector<int>, greater<int>> idx;
    FOR(i, 5) {
        pii t = pq.top();
        pq.pop();

        tot += t.first;
        idx.push(t.second);
    }

    cout << tot << "\n";
    while(!idx.empty()){
        cout << idx.top() << " ";
        idx.pop();
    }
}