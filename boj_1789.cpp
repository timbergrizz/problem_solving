#include <iostream>
using namespace std;

typedef long long ll;

int main(){
    ll S; cin >> S;
    ll i = 1;
    for(; i <= S; ++i){
        ll sum = i * (i + 1) / 2;
        if(S - sum <= i) break;
    }
    cout << i << endl;
}