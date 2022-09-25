#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;

int main() {
    int N, result{0}, price{10101};
    cin >> N;
    vpii v(N);

    for (auto &it: v) cin >> it.first >> it.second;
    sort(v.begin(), v.end());

    for (const auto it: v) {
        if (it.second < price) price = it.second, ++result;
    }
    cout << result;
}