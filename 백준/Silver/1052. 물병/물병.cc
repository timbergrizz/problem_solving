#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define FOR(i, END) for(int i=1; i <= END; ++i)
using namespace std;

int main() {
    FASTIO
    int N, K, result{0};
    cin >> N >> K;

    if (N > K) {
        while(true){
            int cnt = 0, t = N;
            while(t){
                if (t % 2) ++cnt;
                t >>= 1;
            }
            if(cnt <= K) {
                break;
            }
            ++N, ++result;
        }
    }
    cout << result;
}