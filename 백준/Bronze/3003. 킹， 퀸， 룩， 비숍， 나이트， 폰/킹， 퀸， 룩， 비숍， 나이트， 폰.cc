#include <bits/stdc++.h>
#define FOR(i, n) for(int i=0; i<n; ++i)
using namespace std;

int main() {
    int v[6]{0, }, chess[6]{1, 1, 2, 2, 2, 8};
    
    FOR(i, 6) cin >> v[i];
    FOR(i, 6) cout << chess[i] - v[i] << " ";
    cout << "\n";
}