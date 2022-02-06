#include <iostream>
#include <memory.h>

using namespace std;

int v[100001];
int N, M;

bool check(int n) {
    int count{0}, sum{0};

    for (int i = 0; i < N; ++i) {
        sum += v[i];
        if (sum > n)
            i--, sum = 0, count++;
    }

    if (count >= M) return false;
    return true;
}

int binary_search(int l, int r) {
    int left = l, right = r;
    int m;

    // 이분 탐색은 반복문으로 해결하는 편이 좋을 수 있다..
    // 조건에 대해 확실히 생각하고 작성할 필요가 있다.
    while (left <= right) {
        m = (left + right) / 2;
        // m에 중복을 발생시키지 않는 것이 좋다.
        // 어차피 m에 대해서 판단했기 때문에, m -1 과 m + 1으로 이동해서 작동시킬 수 있다.
        if (check(m)) right = m - 1;
        else left = m + 1;
    }

    return left;
}

int main() {
    memset(v, 0, sizeof(v));
    cin >> N >> M;

    int maxL{0};
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
        maxL = max(maxL, v[i]);
    }
    cout << binary_search(maxL, 1000000000) << "\n";
}
