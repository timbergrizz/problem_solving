#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void decrease(vector<ll> &v, ll n, int len) {
    //이건 없어도 되지 않나?
//    cout << n << " " << len << "\n";

    v.push_back(n);
    // 끝값보다 작은 값부터 시작해서, 0까지 계단 수를 만들어 나간다.
    for (int i = (int) (n % 10) - 1; i >= 0; --i) {
        decrease(v, n * 10 + i, len + 1);
    }
}

int main() {
    int N;
    cin >> N;
    //9876543210은 확실히 int 범위보다 크다. 당연히 long long
    vector<ll> v{0,};

    // 꼭 순서대로 생각할 필요는 없다. 인티저는 서 나중에 정리해도 상관없다.
    // 시작점을 입력값을 통해 잡아준다. 한자리수로 결정해두면 된다.
    for (int i = 0; i < 10; ++i) decrease(v, i, 1);
    sort(v.begin(), v.end());

    if (N >= v.size()) cout << -1 << "\n";
    else cout << v[N] << "\n";
}