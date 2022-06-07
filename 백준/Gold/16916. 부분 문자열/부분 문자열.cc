#include <bits/stdc++.h>

#define FOR(i, init, N) for(int i=init; i < N; ++i)
using namespace std;

typedef string str;
typedef vector<int> vi;

void failure_function(str &p, vi &f, int m) {
    int cmp = 0;
    FOR(i, 1, m) {
        while (cmp > 0 && p[i] != p[cmp]) cmp = f[cmp - 1];
        if (p[i] == p[cmp]) f[i] = ++cmp;
    }
}

int kmp(str &t, str &p) {
    int cmp{0}, n{(int) t.size()}, m{(int) p.size()};
    vi f(m);

    failure_function(p, f, m);

    FOR(i, 0, n) {
        while (cmp > 0 && t[i] != p[cmp]) cmp = f[cmp - 1];
        if (t[i] == p[cmp]) {
            if (cmp == m - 1) return 1;
            else cmp++;
        }
    }
    return 0;
}

int main() {
    string s, p;
    cin >> s >> p;
    cout << kmp(s, p);
}