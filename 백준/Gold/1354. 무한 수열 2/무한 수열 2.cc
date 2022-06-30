#include <bits/stdc++.h>

using namespace std;

long long A[4000000]{1,};
long long P, Q, X, Y;

long long getAN(long long N){
    if(N <= 0) return 1;
    if(N < 4000000) return A[N];

    long long fir = (N / P) - X, sec = (N / Q) - Y;
    return getAN(fir) + getAN(sec);
}

int main() {
    long long N;
    cin >> N >> P >> Q >> X >> Y;
    long long fir{0}, sec{0};

    for (int i = 1; i < 4000000; ++i) {
        fir = (i / P) - X, sec = (i / Q) - Y;
        if(fir <= 0) fir = 0;
        if(sec <= 0) sec = 0;
        A[i] = A[fir] + A[sec];
    }

    cout << getAN(N) << '\n';
}