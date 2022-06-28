#include <bits/stdc++.h>

#define FOR(i, N) for(int i = 1; i <= N; ++i)
using namespace std;

int main() {
    int assign[31]{0,}, c1;
    FOR(i, 28) {
        cin >> c1;
        assign[c1] = 1;
    }
    FOR(i, 30) {
        if (!assign[i]) cout << i << "\n";
    }
}