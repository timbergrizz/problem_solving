#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL);
#define FOR(i, init, N) for(int i=init; i < N; ++i)
using namespace std;

typedef string str;
typedef vector<int> vi;

void last_occur(str &p, vi &v, int m) {
    FOR(i, 0, m) v[p[i] - 'a'] = i;
}

int boyer_moore(str &t, str &p) {
    vi v(27);
    int n{(int) t.size()}, m{(int) p.size()};
    int i{m - 1}, cnt{m - 1};
    last_occur(p, v, m);

    while (i <= n - 1) {
        if (t[i] == p[cnt]) {
            if (!cnt) return i;
            else --i, --cnt;
        } else {
            int l = v[t[i] - 'a'];
            i = i + m - min(cnt, 1 + l);
            cnt = m - 1;
        }
    }
    return -1;
}

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
            if (cmp == m - 1) return i;
            else cmp++;
        }
    }
    return -1;
}

int main() {
    FASTIO
    string s, p;
    cin >> s >> p;
    cout << (kmp(s, p) != -1);
}