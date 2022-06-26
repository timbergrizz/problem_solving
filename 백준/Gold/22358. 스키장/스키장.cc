#include <bits/stdc++.h>

using namespace std;
int N, M, K, S, T;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<pii> vp;

vi lift[101010];
vp course[101010];
ll dp[20][101010];

void dp_calc() {
    for (ll i = 0; i <= K; ++i) {
        for (ll j = 1; j <= N; ++j) {
            if (i != K) {
                for (ll k: lift[j]) dp[i + 1][k] = max(dp[i + 1][k], dp[i][j]);
            }

            if (dp[i][j] == 0) continue;
            for (pii k: course[j]) dp[i][k.first] = max(dp[i][k.first], dp[i][j] + k.second);
        }
    }
}

int main() {
    cin >> N >> M >> K >> S >> T;
    ll c1, c2, c3;

    dp[0][S] = 1;
    while (M--) {
        cin >> c1 >> c2 >> c3;
        lift[c2].push_back(c1), course[c1].push_back({c2, c3});
    }

//    for (int i{1}; i <= N; ++i) cout << dp[0][i];
//    cout << "\n";

    dp_calc();

//    for (int i = 0; i <= K; ++i) {
//        for (int j = 1; j <= N; ++j) cout << dp[i][j] << " ";
//        cout << endl;
//    }
    ll result{0};
    for(int i = 0; i <= K; ++i) result = max(result, dp[i][T]);
    cout << result - 1 << "\n";
}