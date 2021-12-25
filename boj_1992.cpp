#include <iostream>
#include <string>
#include <vector>

using namespace std;

char v[64][64];

string dnc(int x, int y, int n) {
    if (n == 1) return {v[x][y]};

    vector<string> b;
    int counter[2]{0, 0};
    int bufN{n / 2};

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            string buf = dnc(x + bufN * i, y + bufN * j, bufN);
            b.push_back({buf});

            if (buf == "1") counter[1]++;
            else if (buf == "0") counter[0]++;
        }
    }

    if (counter[1] == 4) return "1";
    else if (counter[0] == 4) return "0";
    else {
        string r = "(";
        for (int i = 0; i < 4; ++i) r += b[i];
        r += ")";
        return r;
    }
}

int main() {
    int N; cin >> N;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j) cin >> v[i][j];
    }
    string res = dnc(0, 0, N);
    cout << res << "\n";
}