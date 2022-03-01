#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cout.tie(NULL);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int N, buf;
        cin >> N;
        vector<int> v(N);
        for (int &i: v) cin >> i;

        sort(v.begin(), v.end());

        int M;
        cin >> M;
        while (M--) {
            cin >> buf;
            //이진탐색 함수들끼리도 작동시간 다르다.
            //iterator 반환하는것보다 bool 반환하는게 작동시간 더 빠르다.
            auto it = binary_search(v.begin(), v.end(), buf);
            cout << it << "\n";
        }
    }
}