#include <bits/stdc++.h>
#define loop(i, n) for(int i=0; i < n; ++i)
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<ll> v(N);

    int buf;
    loop(i, N) cin >> v[i];

    sort(v.begin(), v.end());

    ll answer{0};
    if(N % 2){
        answer = max(answer, v.back()), N--;
        v.pop_back();
    }

    loop(i, N / 2) answer = max(v[i] + v[N - 1 - i], answer);

    cout << answer << "\n";
}