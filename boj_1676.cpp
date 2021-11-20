//boj_1676
#include <iostream>
#include <algorithm>
using namespace std;

int dp[501][2]{0, 0};
int main(){
    int N; cin >> N;
    for(int i=1; i<=N; ++i){
        dp[i][0] = dp[i-1][0], dp[i][1] = dp[i-1][1];
        int buf = i;
        while(buf % 2 == 0 && buf > 0){
            buf /= 2;
            ++dp[i][0];
        }
        while(buf % 5 == 0 && buf > 0){
            buf /= 5;
            ++dp[i][1];
        }
    }
    cout << min(dp[N][0], dp[N][1]) << endl;
}