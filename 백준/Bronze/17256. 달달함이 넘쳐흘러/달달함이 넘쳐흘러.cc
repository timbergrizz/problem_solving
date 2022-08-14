#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define FOR(i, n) for(int i=1; i <= n; ++i)
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<pll> vl;

int main() {
    int ax, ay, az, cx, cy, cz;
    cin >> ax >> ay >> az >> cx >> cy >> cz;
    cout << cx - az << " " << cy / ay << " " << cz - ax;
}