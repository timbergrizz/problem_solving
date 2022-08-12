#include <bits/stdc++.h>

#define FOR(i, END) for(int i=1; i <= END; ++i)
#define INF 1e9 + 1
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef pair<int, int> pii;

int main() {
    FASTIO
    int N, L, c1;
    cin >> N >> L;
    deque<pii> deq;

    FOR(i, N) {
        cin >> c1;
        if (!deq.empty() && deq.front().second <= i - L) deq.pop_front();
        while (!deq.empty() && deq.back().first > c1) deq.pop_back();

        deq.push_back({c1, i});
        cout << deq.front().first << " ";
    }
}