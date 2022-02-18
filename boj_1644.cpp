#include <bits/stdc++.h>
using namespace std;

bool checkPrime(int n){
    if(n == 1) return false;
    for(int i=2; i * i <= n; ++i){
        if(!(n % i)) return false;
    }
    return true;
}

int main(){
    vector<int> primeNum;
    int N; cin >> N;
    primeNum.push_back(2);
    for(int i=3; i <= N; i += 2){
        if(checkPrime(i)) primeNum.push_back(i);
    }

    auto l = primeNum.begin();
    auto r = primeNum.begin();
    long long sum{0}, result{0};

    while(l <= r){
        if(sum < N) {
            if(r == primeNum.end()) break;
            sum += *r;
            r++;
        }
        else{
            if(sum == N) result++;
            sum -= *l;
            l++;
        }
    }
    cout << result << "\n";
}