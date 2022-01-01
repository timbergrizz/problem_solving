#include <iostream>
#include <map>

using namespace std;

int main() {
    //0에 대해 예외처리와 중복 처리를 어떻게 할 것인가가 문제.
    //수의 배열은
    //처음 접근했을 때, 같은 수를 다 같은수로 제껴버렸는데, "위치가 다르면 같은 값이라도 다른 수가 된다"는 조건에 따라 이렇게 하면 안된다.
    //그렇기 때문에 map을 이용해 같은 수의 개수를 저장한 후, 0과 자기 자신으로 이루어진 수를 제외해 문제를 해결할 수 있다.
    int v[2000], cnt{0}, z{0}, n;
    map<int, int> m;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if (v[i] == 0) ++z;
        // 수열에 있는 0의 개수를 기록한다
    }

    int s;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            s = v[i] + v[j];
            if (s <= 1000000000 && s >= -1000000000) m[s]++;
        }
    }
    //map에 기록되는 것까지 동일.

    for (int i = 0; i < n; ++i) {
        if (m.find(v[i]) == m.end()) continue;
        //자기 자신과 0으로 카운트 된 수는 제거해야 한다. 이때 자기 자신이 0인 경우에는 하나 추가해준다.
        s = m[v[i]] - z + (v[i] == 0);
        if (s) ++cnt;
    }

    cout << cnt << "\n";
}