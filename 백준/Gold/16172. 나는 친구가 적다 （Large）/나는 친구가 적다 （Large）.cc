#include <bits/stdc++.h>

using namespace std;

int dp[202020]{0,}, failure[200002]{0,};

int main() {
    string a, b, a_alp{""};
    cin >> a >> b;

    for (const char &it: a) {
        if (it >= '0' && it <= '9') continue;
        a_alp += it;
    }

    cout << (a_alp.find(b) != string::npos) << "\n";
}