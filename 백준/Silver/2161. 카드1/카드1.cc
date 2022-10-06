#include <bits/stdc++.h>

#define FOR(i, N) for(int i=1; i<=N; ++i)
using namespace std;

typedef long long ll;

int main() {
    int N; cin >> N;
    deque<int> dq;
    FOR(i, N) dq.push_back(i);
    while(dq.size()){
        cout << dq.front() << " ";
        dq.pop_front();
//        if(dq.empty()) break;
        dq.push_back(dq.front());
        dq.pop_front();
    }
}