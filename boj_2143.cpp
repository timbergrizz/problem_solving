#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void getSubset(const vector<int> &v, vector<ll> &result, int size) {
    for (int i = 0; i < size; ++i) {
        ll sum{0};
        for (int j = i; j < size; ++j) {
            sum += v[j];
            result.push_back(sum);
        }
    }
    sort(result.begin(), result.end());
}

int main() {
    ll T;
    cin >> T;
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &i: a) cin >> i;

    vector<ll> subsetA;
    getSubset(a, subsetA, n);

    int m;
    cin >> m;
    vector<int> b(m);
    for (int &i: b) cin >> i;

    vector<ll> subsetB;
    getSubset(b, subsetB, m);

    ll result{0};
    for(ll i : subsetA){
        long long lower = lower_bound(subsetB.begin(), subsetB.end(), T - i) - subsetB.begin();
        long long upper = upper_bound(subsetB.begin(), subsetB.end(), T - i) - subsetB.begin();
        result += upper - lower;
    }
    cout << result << "\n";
}
