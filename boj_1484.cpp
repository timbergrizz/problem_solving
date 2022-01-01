#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
ll dp[100001];

int main() {
    ll G;
    cin >> G;
    ll l{1}, r{1};
    for(long long i=0; i<=100000; ++i) dp[i] = i * i;

    vector<long long> result;
    while(true){
        if(dp[r] - dp[l] <= G) ++r;
        else ++l;

        if(r > 100000) break;
        if(dp[r] - dp[l] == G) result.push_back(r);
    }

    if(result.empty()) cout << -1 << "\n";
    else for(ll i : result) cout << i << "\n";
}
