#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> v(N + 1);
    int buf;
    for (int i = 1; i <= N; ++i) {
        cin >> buf;
        v[i] = buf + v[i - 1];
    }

    auto l = v.begin();
    auto r = v.begin();
    int answer{0};

    while (r != v.end()) {
        if(*r - *l >= M) ++l;
        else ++r ;
        if (*r - *l == M) ++answer;
    }

    cout << answer << "\n";
}