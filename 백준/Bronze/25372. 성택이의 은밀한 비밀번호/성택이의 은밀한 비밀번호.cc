#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    string buf;
    while(N--){
        cin >> buf;
        cout << (buf.size() >= 6 && buf.size() <= 9 ? "yes" : "no") << "\n";
    }
}