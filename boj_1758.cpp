#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int N;
    cin >> N;
    priority_queue<ll> pq;
    int buf;

    for (int i = 1; i <= N; ++i) {
        cin >> buf;
        pq.push(buf);
    }

    ll result{0};
    for (int i = 1; i <= N; ++i) {
        ll front = pq.top();
        pq.pop();

        ll tip = front - (i - 1);
        if (tip < 0) continue;
        else result += tip;
    }
    cout << result << "\n";
}