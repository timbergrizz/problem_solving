#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    if(b > a) swap(a, b);
    if (b == 1 || b == 0) return a;

    ll buf = a % b;
    return gcd(b, buf);
}

int main() {
    int N;
    cin >> N;
    ll v[100];
    for (int i = 0; i < N; ++i) cin >> v[i];
    sort(v, v + N);
    ll g{v[1] - v[0]};

    for (int i = 0; i < N - 1; ++i) {
        g = gcd(v[i + 1] - v[i], g);
//        cout << g << endl;
    }

    vector<ll> ans;
    ans.push_back(g);

    for(int i=2; i * i <= g; ++i){
        if(!(g % i)){
            ans.push_back(g / i);
            if(i * i == g) continue;
            ans.push_back(i);
        }
    }

    sort(ans.begin(), ans.end());
    for(int it : ans) cout << it << " ";
    cout << "\n";
}