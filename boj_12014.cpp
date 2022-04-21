#include <bits/stdc++.h>

#define FOR(i, N) for(int i=1; i <= N; ++i)
using namespace std;

typedef vector<int> vi;

int main() {
    int T, N, M;
    cin >> T;

    vi v(10001);
    FOR(cases, T) {
        cin >> N >> M;
        FOR(i, N) cin >> v[i];
        vi lis(1);
        FOR(i, N){
            if(lis.back() < v[i]) lis.push_back(v[i]);
            else{
                auto it = lower_bound(lis.begin(), lis.end(), v[i]);
                *it = v[i];
            }
        }

        cout << "Case #" << cases << "\n" << (lis.size() - 1 >= M ? 1 : 0) << "\n";
    }
}