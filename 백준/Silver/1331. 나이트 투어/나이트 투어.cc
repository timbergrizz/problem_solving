#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define FOR(i, END) for(int i=1; i <= END; ++i)
using namespace std;

int size;
string answer;

bool check(string c1, string c2){
    int diffX = c1[0] - c2[0], diffY = c1[1] - c2[1];
    diffX = abs(diffX), diffY = abs(diffY);

    if (diffX == 2 && diffY == 1 || diffX == 1 && diffY == 2) return true;
    return false;
}
bool result() {
    string c1, c2, prev;
    map<string, int> m;

    cin >> c1;
    m[c1] = true, prev = c1;

    FOR(i, 35) {
        cin >> c2;
        if(m[c2]) {
            return false;
        }
        if (!check(prev, c2)) {
            return false;
        }
        m[c2] = true, prev = c2;
    }

    return check(c1, c2);
}

int main() {
    cout << (result() ? "V" : "Inv") << "alid";
}