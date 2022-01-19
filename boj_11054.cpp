#include <iostream>
#include <memory.h>
using namespace std;

int N;
int A[1001], dp[1001][2];

void dp1(){
    for(int i=2; i <=N ; ++i){
        for(int j=1; j < i; ++j){
            if(A[i] > A[j] && dp[i][0] < dp[j][0] + 1)  dp[i][0] = dp[j][0] + 1;
        }
    }

    for(int i=N - 1; i >= 1 ; --i){
        for(int j=N; j > i; --j){
            if(A[i] > A[j] && dp[i][1] < dp[j][1] + 1) dp[i][1] = dp[j][1] + 1;
        }
    }
}

int getResult() {
    int ret{0};
    for (int i = 1; i <= N; ++i) {
        if(ret < dp[i][0] + dp[i][1] - 1) ret = dp[i][0] + dp[i][1] - 1;
    }
    return ret;
}

int main() {
    memset(A, 0, sizeof A);

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        dp[i][0] = dp[i][1] = 1;
    }

    dp1();
    cout << getResult() << "\n";
}