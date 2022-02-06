#include <bits/stdc++.h>

using namespace std;

int main() {
    priority_queue<double, vector<double>, less<double>> pq;
    int N;
    cin >> N;
    double buf;

    while (N--) {
        cin >> buf;
        pq.push(buf);
    }

    while (pq.size() > 1) {
        double a = pq.top();
        pq.pop();
        double b = pq.top();
        pq.pop();

        a += (b / 2);
        pq.push(a);
    }

    cout << pq.top() << "\n";
}