#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> dp(50001, 6);
    for(int i=1; i * i <= 50000; ++i){
        dp[i * i] = 1;
    }

    int N; cin >> N;


    for(int i=1; i<= N; ++i){
        for(int j=1; j * j <= i; ++j){
            dp[i] = min(dp[i], dp[j * j] + dp[i - j * j]);
        }
    }
    cout << dp[N] << endl;
}