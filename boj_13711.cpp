#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int lis(const vi &v, int N) {
    vector<int> lis(1, -1);
    for (int i: v) {
        if (i > lis.back()) lis.push_back(i);
        else {
            auto it = lower_bound(lis.begin(), lis.end(), i);
            *it = i;
        }
    }

    return (int) lis.size() - 1;
}

int main() {
    int N;
    cin >> N;

    vector<int> fir(N);
    vector<int> temp(N);
    vector<int> sec(N);

    for (int &i: fir) cin >> i;

    int x;
    //우선 B의 값을 저장하는 것이 아닌 B의 인덱스를 저장한다.
    for (int i = 0; i < N; ++i) {
        cin >> x;
        temp[x - 1] = i;
    }

    // 그리고 이를 A의 값 순서대로 정리해준다.
    // 전선 연결 문제등의 문제와 크게 다르지 않다.
    for (int i = 0; i < N; ++i) sec[i] = temp[fir[i] - 1];

    cout << lis(sec, N) << "\n";
}