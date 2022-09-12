#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define FOR(i, END) for(int i=0; i < END; ++i)
#define MAX 1000000000
#define NEXT i + 1
using namespace std;

typedef vector<int> vi;

int main() {
    int N;
    cin >> N;
    vi v(N);
    for (int &i: v) cin >> i;
    reverse(v.begin(), v.end());

    int answer{0};
    FOR(i, N - 1){
        if(v[i] > v[NEXT]) continue;
        answer += (v[NEXT] - (v[i] - 1)), v[NEXT] = v[i] - 1;
    }
    cout << answer;
}