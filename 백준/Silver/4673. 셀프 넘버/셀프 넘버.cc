#include <bits/stdc++.h>
#define FOR(i, N) for(int i=1; i <= N; ++i)
using namespace std;



int get_sum(int i){
    int ret{0};
    while(i) {
        ret += (i % 10);
        i /= 10;
    }
    return ret;
}

bool is_self(int n){
    FOR(i, n) {
        if(i + get_sum(i) == n) return false;
    }
    return true;
}

int main() {

    for(int i=1; i <= 10000; ++i){
        if(is_self(i)) cout << i << "\n";
    }
}