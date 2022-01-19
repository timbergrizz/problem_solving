#include <iostream>
#include <map>

using namespace std;

int main() {
    map<string, float> m;
    string str;
    float N{0};

    while (getline(cin, str)) {
        m[str] += 1, N++;
    }

    cout.setf(ios::fixed);
    cout.precision(4);
    for(auto it : m) cout << it.first << " " << it.second / N * 100 << "\n";
}