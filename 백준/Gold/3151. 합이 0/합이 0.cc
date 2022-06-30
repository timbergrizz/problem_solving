#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
int v[10000];

int main() {
    int N;
    cin >> N;

    for(int i=0; i < N; ++i) cin >> v[i];
    sort(v, v + N);
    long long result{0};

    for(int i=0; i < N - 2; ++i){
        for(int j = i + 1; j < N - 1; ++j){
            int cur{v[i] + v[j]};
            auto lo = lower_bound(v + j + 1, v + N, -cur) - v;
            auto hi = upper_bound(v + j + 1, v + N, -cur) - v;
//            cout << cur << " " << *lo << " " << *hi << "\n";
            result += (int)(hi - lo);
        }
    }

    cout << result << "\n";
}