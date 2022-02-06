#include <bits/stdc++.h>
#define loop(i, n) for(int i=0; i < n; ++i)
using namespace std;

typedef pair<int, int> pii;

bool comp(pii a, pii b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second ;
}

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> v(N);

    loop(i, N) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end(), comp);
    int startTime{0}, cnt{0};
    loop(i, N) {
        if(v[i].first >= startTime){
            startTime = v[i].second, cnt++;
        }
    }
    cout << cnt << "\n";
}