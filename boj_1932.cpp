#include <iostream>
#include <utility>
using namespace std;

int v[500][500];

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= i; ++j) cin >> v[i][j];
    }

    for (int i = N - 2; i >= 0; --i) {
        for(int j=0; j<=i; ++j){
            v[i][j] += max(v[i+1][j], v[i+1][j+1]);
        }
    }
    cout << v[0][0] <<"\n";
}