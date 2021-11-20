//baekjun_1003
#include <iostream>
using namespace std;

int dp[41][2]{1, 0, 0, 1, 1, 1};
int main(){
    for(int i=3; i<=40; ++i){
        dp[i][0] = dp[i-1][0] + dp[i - 2][0];
        dp[i][1] = dp[i-1][1] + dp[i - 2][1];
    }
    int count; cin >> count;

    for(int i=0; i<count; ++i){
        int find; cin >> find;
        cout << dp[find][0] << " " << dp[find][1] << "\n";
    }
}
