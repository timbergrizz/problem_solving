#include <iostream>

using namespace std;

typedef long long ll;

int v[10001];
int N, M;

bool check(int m) {
    int r{0};

    for (int i = 1; i <= N; ++i) {
        if (m < v[i]) r += m;
        else r += v[i];
    }

    if (M >= r) return true;
    return false;
}

int binary_search(int l, int r) {
    if (l == r) return l;
    if (l + 1 == r) {
        if (check(r)) return r;
        else return l;
    }

    int m = (l + r) / 2;
    if (!check(m)) return binary_search(l, m);
    return binary_search(m, r);
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> v[i];
    cin >> M;

    int res = binary_search(0, M);
    if (res == M) {
        int m= 0;
        for (int i = 1; i <= N; ++i) m = max(m, v[i]);
        res = m;
    }

    cout << res << "\n";
}