#include <iostream>
#include <algorithm>
using namespace std;

int gcd(long long a, long long b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    long long A, B; cin >> A >> B;
    if(A > B) swap(A, B);

    long long g = gcd(B, A);
    if(g== A) g = A;

    for(int i=0; i<g; ++i) cout << 1;
    cout << endl;
}