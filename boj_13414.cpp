#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<string, int> a, pair<string, int> b) {
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int K, L;
    cin >> K >> L;

    map<string, int> m;
    for (int i = 0; i < L; ++i) {
        string stdNum; cin >> stdNum;
        m[stdNum] = i;
    }

    vector<pair<string, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), comp);

    int idx;
    (v.size() > K ? idx = K : idx = v.size());

    for (int i = 0; i < idx; ++i){
        cout << v[i].first << "\n";
    }
}