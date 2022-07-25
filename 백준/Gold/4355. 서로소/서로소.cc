#include <bits/stdc++.h>

#define FOR(i, init, N) for(int i=init; i<= N; ++i)
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

typedef long long ll;
typedef vector<ll> vl;


int main() {
    FASTIO
    ll N; cin >> N;
    while(N != 0){
        ll answer {N};
        for (ll i = 2; i * i <= N; ++i) {
            if(!(N % i)) {
                 answer -= (answer / i);
                 while(N % i == 0) N /= i;
            }
        }
        if(N > 1) answer -= answer / N;
        cout << answer << "\n";
        cin >> N;
    }
}