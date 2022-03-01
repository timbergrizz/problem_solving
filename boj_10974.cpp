#include <bits/stdc++.h>

using namespace std;

bool visited[9]{false, };
int li[8]{0, };
int n{0};

void num(int s){
    if(s == n){
        for(int i=0; i < n; ++i) cout << li[i] << " ";
        cout << "\n";
        return;
    }

    for(int i=1; i <= n; ++i){
        if(visited[i]) continue;
        visited[i] = true, li[s] = i;
        num( s + 1);
        visited[i] = false;
    }
}

int main() {
    cin >> n;
    num(0);
}