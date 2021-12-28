#include <iostream>
#include <vector>

using namespace std;

int v[4000000];

int main() {
    int N;
    cin >> N;
    bool flag = true;
    int cnt{0};
    for (int i = 2; i <= N; ++i) {
        flag = true;
        for (int j = 2; j * j <= i; ++j) {
            if (!(i % j)) {
                flag = false;
                break;
            }
        }
        if (flag) v[cnt++] = i;
    }

    int l = 0, r = 0;
    long long sum{}, counter{0};

    while (r <= cnt) {
        if (sum >= N) {
            if (sum == N) ++counter;
            sum -= v[l];
            l++;
        }
        else {
            sum += v[r];
            ++r;
        }
    }
    cout << counter << "\n";
}