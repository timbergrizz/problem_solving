#include <bits/stdc++.h>

#define FOR(i, END) for(int i=1; i <= END; ++i)
#define INF 1e9 + 1
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
int failure[1010101];

void kmp(string &s) {
    int k{0};
    FOR(i, s.size() - 1) {
        while (k > 0 && s[i] != s[k]) k = failure[k - 1];
        if (s[i] == s[k]) failure[i] = ++k;
    }
}

int main() {
    FASTIO

    string s;
    while (true) {
        memset(failure, 0, sizeof failure);
        cin >> s;
        if (s == ".") break;

        kmp(s);
        int size = (int)s.size(), f = failure[s.size() - 1];

        if (size % (size - f)) cout << 1;
        else cout << size / (size - f);
        cout << "\n";
    }
}