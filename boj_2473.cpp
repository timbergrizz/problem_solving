#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;

    vector<ll> v(N);
    for (int i = 0; i < N; ++i) cin >> v[i];
    sort(v.begin(), v.end());

    ll minDiff{200000000001}, minVal[3]{0,};

    for (int i = 0; i < N; ++i) {
        ll l = i + 1, r = N - 1;
        while (l < r) {
            ll diff{v[i] + v[l] + v[r]};
            if (abs(diff) < minDiff) {
                minVal[0] = v[i], minVal[1] = v[l], minVal[2] = v[r], minDiff = abs(diff);
            }
            if (diff < 0) {
                l++;
            } else {
                r--;
            }
        }
    }

    for (int i = 0; i < 3; ++i) {
        cout << minVal[i] << " ";
    }
    cout << "\n";
}