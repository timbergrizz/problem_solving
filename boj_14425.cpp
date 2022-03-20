#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M; cin >> N >> M;
    map<string, bool> s;
    int result{0};

    string buf;
    while(N--) {
        cin >> buf;
        s[buf] = true;
    }

    while(M--){
        cin >> buf;
        if(s[buf]) result++;
    }
    cout << result << "\n";
}