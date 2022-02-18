#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    vector<int> lis(1);
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
        if (v[i] > lis.back()) lis.push_back(v[i]);
        else{
            auto it = lower_bound(lis.begin(), lis.end(), v[i]);
            *it = v[i];
        }
    }
    cout << N - (int)(lis.size() - 1) << "\n";
}