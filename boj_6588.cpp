#include <iostream>
using namespace std;

int check(int n){
    for(int i=2; i * i <= n; ++i){
        if(n % i == 0) return false;
    }
    return true;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base :: sync_with_stdio(false);
    int n;

    while(true){
        cin >> n;
        if(n == 0) break;
        bool success{false};


        for(int i=1; i < n / 2; i++){
            int a = 2 * i + 1;
            int b = n - a;
            if(check(a) && check(b)){
                cout << n << " = " << a << " + " << b << '\n';
                success = true;
                break;
            }
        }
        if(!success) cout << "Goldbach's conjecture is wrong\n";
    }
}