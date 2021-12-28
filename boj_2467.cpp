#include <iostream>
#include <algorithm>
#include <stdlib.h>

using namespace std;

long long v[100000];

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> v[i];
    sort(v, v + N);
    int l{0}, r{N - 1};
    int minl{0}, minr{N - 1};

    while (l < r) {
        if (abs(v[l] + v[r]) < abs(v[minl] + v[minr]))
            minl = l, minr = r;

        if (v[l] + v[r] < 0) ++l;
        else --r;
    }
    cout << v[minl] << " " << v[minr] << "\n";
}