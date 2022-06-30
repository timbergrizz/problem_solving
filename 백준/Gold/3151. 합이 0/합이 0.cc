#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
vi v;

int main() {
    int N;
    cin >> N;

    v.resize(N);
    for (int &i: v) cin >> i;
    sort(v.begin(), v.end());
    long long result{0};

    for(int i=0; i < N - 2; ++i){
        for(int j = i + 1; j < N - 1; ++j){
            int cur{v[i] + v[j]};
            auto lo = lower_bound(v.begin() + j + 1, v.end(), -cur);
            auto hi = upper_bound(v.begin() + j + 1, v.end(), -cur);
//            cout << cur << " " << *lo << " " << *hi << "\n";
            result += (int)(hi - lo);
        }
    }

    cout << result << "\n";
}