#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, c1; cin >> N;
    map<int, int> m;

    while(N--){
        cin >> c1;
        m[c1]++;
    }
    cin >> c1;
    cout << m[c1] << "\n";
}