#include <bits/stdc++.h>

using namespace std;

int result{0};
int v[41]{0,};
long long cnt{0};

// 가장 큰 아이디어는 배열을 두개로 나누어 처리한다는 것이다.
// 한번에 모든 부분수열을 체크하는 경우 약 2^40회의 연산을 수행하지만
// 배열을 두개로 나누어 수행하면 2^20 * 2회 수행하게 되어 얀산의 수가 줄어든다.
// 배열을 두개로 나눈 후, 두 배열에서 나온 부분수열의 합을 모두 벡터에 저장한다.
// 이후 두 배열에 저장된 부분수열의 합들을 조합하여 가능한 값들을 구한다.
void checkSum(int idx, int N, int S, int sum, vector<int> &a) {
    sum += v[idx];
    if (idx == N) return;
    if (sum == S) cnt++;

    a.push_back(sum);
    checkSum(idx + 1, N, S, sum - v[idx], a);
    checkSum(idx + 1, N, S, sum, a);
}

int main() {
    int N, S;
    cin >> N >> S;
    for (int i = 0; i < N; ++i) cin >> v[i];

    vector<int> A, B;
    checkSum(0, N / 2, S, 0, A);
    checkSum(N / 2, N, S, 0, B);

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for (int a: A) {
        int temp = S - a;
        int lower = lower_bound(B.begin(), B.end(), temp) - B.begin();
        int upper = upper_bound(B.begin(), B.end(), temp) - B.begin();
        cnt += (upper - lower);
    }
    cout << cnt << "\n";
}