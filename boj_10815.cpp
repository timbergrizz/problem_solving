#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int v[500001];
int N;

bool check(int n) {
    int l = 0, r = N;
    int m;

    while (l < r) {
        m = (l + r) / 2;

        if (v[m] == n) return true;
        else if (v[m] > n) r = m;
        else l = m + 1;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> v[i];
    sort(v, v + N);

    int M;
    cin >> M;
    while (M--) {
        int b;
        cin >> b;
        cout << check(b) << " ";
    }

    cout << endl;
}
