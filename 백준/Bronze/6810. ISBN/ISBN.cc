#include <bits/stdc++.h>

#define FOR(i, N) for(int i=1; i <= N; ++i)
using namespace std;

int v[4]{0, 1, 3, 1};

int main() {
    int c1, sum = 91;
    FOR(i, 3) {
        cin >> c1;
        sum += c1 * v[i];
    }
    cout << "The 1-3-sum is " << sum;
}