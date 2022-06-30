#include <bits/stdc++.h>
using namespace std;

int pow(int n, int p){
    if(p == 1) return n;
    if(p == 0) return 1;
    int h = pow(n, p / 2);
    return h * h * (p % 2 ? n : 1);
}

int main(){
    string N; cin >> N;
    int result{0};

    for(char i : N){
        int cur = (int)(i - '0');
        result += pow(cur, (int)5);
    }
    cout << result << "\n";
}