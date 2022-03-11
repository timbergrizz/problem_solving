#include <bits/stdc++.h>

#define FOR(i, N) for(int i=1; i <= N; ++i)

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v(N);

    for (int &i: v) cin >> i;
    vector<int> lis(1);

    for (int i: v) {
        if (i > lis.back()) lis.push_back(i);
        else{
            auto it = lower_bound(lis.begin(), lis.end(), i);
            *it = i;
        }
    }
    cout << lis.size() - 1 << "\n";
}