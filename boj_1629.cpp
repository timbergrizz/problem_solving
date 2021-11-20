#include <iostream>
using namespace std;

long long pow(long long a, long long b, long long mod){
    if(b == 0){
        return 1;
    }

    long long n = pow(a, b / 2 , mod);
    n = n * n % mod;

    if(b % 2 == 1) {
        return (n * a) % mod;
    }
    else{
        return (n) % mod;
    }
}

int main(){
    long long fir, sec, trd; cin >> fir >> sec >> trd;
    long long result = pow(fir, sec, trd);
    cout << result << endl;
}