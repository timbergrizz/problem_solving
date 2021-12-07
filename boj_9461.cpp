#include <iostream>

using namespace std;
long long v[101]{0, 1, 1, 1,};

int main(void){
    for(int i=4; i<=100; ++i){
        v[i] = v[i-2] + v[i-3];
    }
    int T; cin >> T;
    while(T--){
        int buf; cin >> buf;
        cout << v[buf] << "\n";
    }
}