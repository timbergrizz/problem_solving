#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; cin >> T;
    while(T--){
        int N;
        cin >> N;

        vector<int> v(N);
        for (int i = 0; i < N; ++i) cin >> v[i];

        vector<int> lis(1, 0);
        int maxSize{0};

        for (int i = 0; i < N; ++i) {
            if (lis.back() < v[i])  lis.push_back(v[i]);
            else{
                auto it = lower_bound(lis.begin(), lis.end(), v[i]);
                *it = v[i];
            }
        }
        cout << lis.size() - 1 << endl;
    }
}