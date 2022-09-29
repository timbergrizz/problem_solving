#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M, c1;
    cin >> N >> M;
    int answer{1}, remain{M};

    for (int i{0}; i < N; ++i) {
        cin >> c1;

        if (remain < c1) answer++, remain = M - c1;
        else remain -= c1;
//        cout << remain << endl;
    }

    cout << (!N ? 0 : answer);
}