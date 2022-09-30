#include <bits/stdc++.h>

using namespace std;

int main() {
    int count{4}, total{0}, c1;
    while(count--){
        cin >> c1;
        total += c1;
    }
    cout << total / 60 << " "  << total % 60;
}