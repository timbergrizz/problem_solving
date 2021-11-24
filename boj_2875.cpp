#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    int teams = min(N / 2, M / 1);
    int bufK{(N - teams * 2) + (M - teams)};

    while(bufK < K){
        teams -= 1;
        bufK += 3;
    }

    cout << teams;
}
