#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> v(N);

    for (int &i: v) cin >> i;

    auto start = v.begin();
    auto end = v.begin();
    long long sum{0};
    int bufK = K;
    while(bufK--) sum += *end++;

    long long result{sum};

    while(end != v.end()){
        sum = sum - *start + *end;
        start++, end++;
        result = max(sum, result);
    }

    cout << result << "\n";
}