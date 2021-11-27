#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> v(N);
    for (int i = 0; i < N; ++i) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end(), comp);

    int counter{1}, startTime{v[0].second};

    for (int i = 1; i < N; ++i) {
        if (startTime <= v[i].first) {
            startTime = v[i].second, counter++;
        }
    }

    cout << counter << "\n";
}