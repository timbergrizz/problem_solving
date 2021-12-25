#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;

    while (N--) {
        int buf;
        cin >> buf;
        pq.push(buf);
    }

    int maxWeight{0};
    while (!pq.empty()) {
        int buf = pq.size() * pq.top();
        maxWeight = max(maxWeight, buf);
        pq.pop();
    }

    cout << maxWeight << "\n";
}