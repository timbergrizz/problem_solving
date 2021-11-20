#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a % b);
}

int main(){
    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        vector<long long> input(n);
        for(int i{0}; i<n; ++i) cin >> input[i];
        long long result{0};
        for(int i{0}; i<n; ++i){
            for(int j{i + 1}; j < n; ++j) result += gcd(input[i], input[j]);
        }
        cout << result << '\n';
    }
}