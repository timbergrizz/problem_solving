#include <iostream>

using namespace std;

int v[1001][1001]{0,};

int main() {
    string fir, sec;
    getline(cin, fir);
    getline(cin, sec);

    int maxLen{0};
    for (int i = 1; i <= fir.length(); ++i) {
        for (int j = 1; j <= sec.length(); ++j) {
            if (fir[i - 1] == sec[j - 1]) v[i][j] = v[i - 1][j - 1] + 1;
            else v[i][j] = max(v[i - 1][j], v[i][j - 1]);
        }
    }

    cout << v[fir.length()][sec.length()] << "\n";
}
