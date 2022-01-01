#include <iostream>

using namespace std;

typedef long long ll;
ll dp[10000000];

long long N, P, Q, X, Y;

ll calc(ll n) {
    if(n <= 0) return 1;
    if(n < 10000000) return dp[n];

    ll fir = (n / P) - X, sec = (n / Q) - Y;
    return calc(fir) + calc(sec);
}

int main() {
    cin >> N >> P >> Q >> X >> Y;

    dp[0] = 1;

    for (ll i = 1; i < 10000000; ++i) {
        ll fir = (i / P) - X, sec = (i / Q) - Y;
        if (fir <= 0) fir = 0;
        if (sec <= 0) sec = 0;
        dp[i] = dp[fir] + dp[sec];
    }

    cout << calc(N) << "\n";
}