#include <bits/stdc++.h>
using namespace std;

int main(){
    string c1; cin >> c1;
    for(char c : c1){
        cout << (char)(c < 'a' ? c + 32 : c - 32);
    }
    cout << "\n";
}