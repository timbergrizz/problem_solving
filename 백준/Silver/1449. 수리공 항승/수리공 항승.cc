#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define FOR(i, END) for(int i=1; i <= END; ++i)
using namespace std;

int arr[1001]{0};

int main() {
    int N, L, c1; cin >> N >> L;
    FOR(i, N){
        cin >> c1;
        arr[c1] = 1;
    }

    int answer{0};
    FOR(i, 1000){
        if(!arr[i]) continue;
        ++answer;
        FOR(j, L) arr[i + j - 1] = 0;
    }
    cout << answer;
}