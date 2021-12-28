#include <iostream>
#include <memory.h>
using namespace std;

typedef long long ll;

ll dp[10000001];
ll N, P, Q;

ll calc(ll n) {
    if(n == 0) return 1;

    if(n <= 10000000) return dp[n];
    else return calc(n / P) + calc(n / Q);
}

int main() {
    cin >> N >> P >> Q;
    memset(dp, 0, sizeof(dp));

    dp[0] = 1;
    // N이 10^12까지 가능하고, 메모리도 제한이 있기 때문에 시간 제한이 2초기 때문에 모든 수를 dp로 처리하는 것은 불가능
    // 일정 정도까지 dp로 값을 저장한 후, 더 큰 수에 대해서는 재귀 점화식을 이용하여 문제를 해결할 수 있다.
    // dp와 재귀의 적절한 조합을 이용한 문제.
    for (ll i = 1; i <= 10000000; ++i) {
        dp[i] = dp[i / P] + dp[i / Q];
    }

    cout << calc(N) << "\n";
}