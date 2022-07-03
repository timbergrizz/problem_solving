#include <bits/stdc++.h>

using namespace std;

int main() {
    int c1, c2;
    while (true) {
        cin >> c1 >> c2;
        if (c1 == 0 && c2 == 0) break;
        cout << (c1 > c2 ? "Yes" : "No") << "\n";
    }
}