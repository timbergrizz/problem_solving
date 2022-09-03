#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define FOR(i, END) for(int i=0; i < END; ++i)
using namespace std;

bool check(const string &c1, const string &c2, int idx) {
    FOR(j, c2.length()) {
        if (c1[idx + j] != c2[j]) return false;
    }
    return true;
}

int main() {
    FASTIO
    string c1, c2;
    getline(cin, c1);
    getline(cin, c2);
    int cnt{0}, answer{0};

    if (c1.size() >= c2.size()) {
        FOR(i, c1.size()) {
            if (check(c1, c2, i)) answer++, i += (int) c2.length() - 1;
        }
    }

    cout << answer << "\n";

}