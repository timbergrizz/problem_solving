#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int v[9][9];
vector<pair<int, int>> f;

bool check(int x, int y, int n) {
    for (int i = 0; i < 9; ++i) {
        if (v[x][i] == n || v[i][y] == n) return false;
    }

    for(int i =( x/ 3 ) * 3; i < (x / 3) * 3 + 3; ++i){
        for(int j =( y/ 3 ) * 3; j < (y / 3) * 3 + 3; ++j){
            if(v[i][j] == n) return false;
        }
    }

    return true;
}

bool dfs(int cur) {
    if (cur == f.size()) return true;

    int x = f[cur].first;
    int y = f[cur].second;
//
//    for (int i = 0; i < 9; ++i) {
//        for (int j = 0; j < 9; ++j) cout << v[i][j] << " ";
//        cout << "\n";
//    }
//
//    cout << "\n";

    for (int i = 1; i <= 9; ++i) {
        if (check(x, y, i)) {
            v[x][y] = i;
            if (dfs(cur + 1)) return true;
            v[x][y] = 0;
        }
    }
    return false;
}

int main() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> v[i][j];
            if (v[i][j] == 0) f.push_back({i, j});
        }
    }
//    cout << endl;

    dfs(0);

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) cout << v[i][j] << " ";
        cout << "\n";
    }
}