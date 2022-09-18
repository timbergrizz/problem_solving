#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define FOR(i, END) for(int i=1; i <= END; ++i)
using namespace std;

int arr[28]{};


int main() {
    FASTIO
    int N, result{0};
    cin >> N;
    while (N) {
        if(N % 2)  result++;
        N >>= 1;
    }
    cout << result << "\n";
}