#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> inp(N);
    map<long long, long long> v;
    vector<long long> sorted(N);

    for (int i = 0; i < N; ++i) {
        cin >> inp[i];
        if (v.find(inp[i]) == v.end()) v[inp[i]] = 1;
    }

    sort(sorted.begin(), sorted.end());

    for (int i = 0; i < N; ++i) {
        cout << lower_bound(sorted.begin(), sorted.end(), inp[i]) - sorted.begin() << " ";
    }
    cout << '\n';
}