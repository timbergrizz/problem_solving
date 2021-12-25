#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[15];
bool visit[15];
vector<char> c;
int L, C, cnt = 0;

void dfs(int n) {
    if (cnt == L) {
        int aeiou{0}, ee{0};
        for(int i=0; i<L; ++i){
            if(c[a[i]] == 'a' || c[a[i]] == 'e' || c[a[i]] == 'i' || c[a[i]] == 'o' || c[a[i]] == 'u') aeiou++;
            else ee++;
        }

        if(aeiou < 1 || ee < 2) return;

        for(int i=0; i<L; ++i) cout << c[a[i]];
        cout << endl;
        return;
    }

    for(int i=n; i<C; ++i){
        if(!visit[i]){
            a[cnt] = i, visit[i] = true, cnt++;
            dfs(i);
            visit[i] = false, cnt--;
        }
    }
}

int main() {
    cin >> L >> C;
    char buf;
    for(int i=0; i<C; ++i){
        cin >> buf;
        c.push_back(buf);
    }
    sort(c.begin(), c.end());
    dfs(0);
}