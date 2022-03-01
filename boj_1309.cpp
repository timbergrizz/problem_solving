#include <iostream>
using namespace std;

int dp[100001]{1, 3, };

int main(){
    int N; cin >> N;
    for(int i=2; i<=N; ++i) dp[i] = (dp[i - 2] + 2 * dp[i-1]) % 9901;
    cout << dp[N] << endl;
}