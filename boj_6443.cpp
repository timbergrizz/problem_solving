#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
string v;
//
//char res[20];
//bool visit[20];
//
//void dfs(int idx) {
//    if (idx == v.size()) {
//        cout << res << "\n";
//        res[idx - 1] = 0;
//        return;
//    }
//
//    for (int i = 0; i < v.size(); ++i) {
//        if (!visit[i] && v[i] != res[idx]) {
//            visit[i] = true, res[idx] = v[i];
//            dfs(idx + 1);
//            visit[i] = false;
//        }
//    }
//}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    while (n--) {
        cin >> v;
        sort(v.begin(), v.end());

        do {
            cout << v << "\n";
        } while (next_permutation(v.begin(), v.end()));
    }
}