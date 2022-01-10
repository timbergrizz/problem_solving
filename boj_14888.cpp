#include <iostream>

using namespace std;

int op[4]{0,}, v[11]{0,};
int N;

int minimum{1000000000}, maximum{-1000000000};

void dfs(int idx, int val) {
    if (idx == N) {
        if(minimum > val) minimum = val;
        if(maximum < val) maximum = val;
        return;
    }

    for(int i=0; i < 4; ++i){
        if(!op[i]) continue;

        op[i]--;
        int buf = val;

        if(i == 0) buf += v[idx];
        if(i == 1) buf -= v[idx];
        if(i == 2) buf *= v[idx];
        if(i == 3) buf /= v[idx];

        dfs(idx + 1, buf);
        op[i]++;
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> v[i];
    for (int i = 0; i < 4; ++i) cin >> op[i];
    dfs(1, v[0]);
    cout << maximum << "\n" << minimum << "\n";
}