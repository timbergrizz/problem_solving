#include <bits/stdc++.h>

#define FOR(i, N) for(int i=1; i <= N; ++i)
using namespace std;

int v[1000001]{1, };
int p, q;
typedef long long ll;

ll getAi(ll i){
    if(i <= 1000000) return v[i];
    ll fir = getAi(i / p), sec = getAi(i / q);
    return fir + sec;
}

int main() {
    ll N;
    cin >> N >> p >> q;
    FOR(i, 1000000) v[i] = v[i / p] + v[i / q];
    cout << getAi(N) << "\n";
}