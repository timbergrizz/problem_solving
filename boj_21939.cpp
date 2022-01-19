#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;
    int P, L;
    map<int, int> p;
    map<int, set<int>> ps;

    while (N--) {
        cin >> P >> L;
        p[P] = L;
        ps[L].insert(P);
    }

    int M;
    cin >> M;
    string operation;

    while (M--) {
        cin >> operation;
        if (operation == "add") {
            cin >> P >> L;
            p[P] = L;
            ps[L].insert(P);
        } else if (operation == "recommend") {
            cin >> N;
            if (N == 1) cout << *ps.rbegin()->second.rbegin() << "\n";
            else if (N == -1) cout << *ps.begin()->second.begin() << "\n";
        } else if (operation == "solved") {
            cin >> P;
            L = p[P];
            p.erase(P);
            ps[L].erase(P);
            if (ps[L].empty()) ps.erase(L);
        }
    }
}
