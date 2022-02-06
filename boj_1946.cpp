#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        vector<pii> v(N);

        for(int i=0; i < N; ++i) cin >> v[i].first >> v[i].second;
        sort(v.begin(), v.end());

        int minRank {v[0].second}, cnt{1};
        for(int i=1; i < N ;++i){
            if(minRank > v[i].second){
                minRank = v[i].second, cnt++;
            }
        }
        cout << cnt << "\n";
    }
}