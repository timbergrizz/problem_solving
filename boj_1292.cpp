// boj_1292
#include <iostream>
using namespace std;

int main(){
    int A, B; cin >> A >> B;
    int pos{0}, counter{1};
    int dp[1001] {0,};

    while(pos < 1000){
        for(int i=0; i<counter; ++i){
            if(pos >= 1000) break;

            dp[pos + 1] = dp[pos] + counter;
            pos += 1;
        }
        ++counter;
    }

    cout << dp[B] - dp[A - 1] << endl;
}