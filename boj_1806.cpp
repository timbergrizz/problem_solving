#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long v[100001]{0, };
    long long N, S;
    cin >> N >> S;
    long long buf;

    for (int i = 1; i <= N; ++i) {
        cin >> buf;
        v[i] = buf + v[i - 1];
    }

    long long minLen{N + 1};
    int l{0}, r{1};

    while (l <= r && r <= N) {
        if (v[r] - v[l] < S) r++;
        else {
            if (minLen > r - l) minLen = r - l;
            ++l;
        }
    }

    if (minLen == N + 1) minLen = 0;
    cout << minLen << "\n";
}