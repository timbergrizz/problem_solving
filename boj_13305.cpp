#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll dist[100000], price[100001];

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N - 1; ++i) cin >> dist[i];
    for (int i = 0; i < N; ++i) cin >> price[i];

    ll minPrice{price[0]}, result{0};

    for (int i = 0; i < N; ++i) {
        minPrice = min(price[i], minPrice);
        result += minPrice * dist[i];
//        cout << minPrice << " " << dist[i] << " "<< result << endl;
    }
    cout << result << endl;
}
