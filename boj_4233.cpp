#include <iostream>

using namespace std;

int p;

long long pow(long long a, long long r) {
    if(r == 1) return a % p;
    if(!r) return 1;

    long long buf = pow(a, r / 2) % p;
    if(r % 2) return (((buf * buf) % p) * a) % p;
    else return (buf * buf) % p;
}

int check() {
    for (int i = 2; i * i <= p; ++i) {
        if (!(p % i)) return false;
    }
    return true;
}

int main() {
    int a; cin >> p >> a;
    while(a && p){
        if(!check() && (pow(a, p) == a)) cout << "yes" << "\n";
        else cout << "no" << endl;

        cin >> p >> a;
    }
}