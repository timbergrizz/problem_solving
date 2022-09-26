#include <bits/stdc++.h>

using namespace std;

int main() {
    string c1;
    int age, weight;
    bool status{false};

    while (true) {
        cin >> c1 >> age >> weight;
        if (c1 == "#") break;
        status = (age > 17 || weight >= 80);
        cout << c1 << " " << (!status ? "Junior" : "Senior") << "\n";
    }
}