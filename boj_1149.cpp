#include <iostream>
using namespace std;

int v[1001][4] {0, };
int dp[1001][3] {0, };

int main(){
    int n; cin >> n;
    for(int i=1; i<=n; ++i) cin >> v[i][0] >> v[i][1] >> v[i][2];
    dp[1][0] = v[1][0], dp[1][1] =v[1][1], dp[1][2] = v[1][2];

    for(int i=2; i<=n; ++i){
        for(int j=0; j<3; ++j){
            int minVal = 10000001;
            for(int k=0; k<3; ++k){
                if(k != j && minVal > dp[i-1][k]) minVal = dp[i-1][k];
            }
            dp[i][j] = minVal + v[i][j];
        }
    }

    int result{10000001};
    for(int i=0; i<3; ++i){
        if(result > dp[n][i]) result = dp[n][i];
    }
    cout << result << "\n";
}