#include <iostream>
using namespace std;

int main(){
    int N; cin >> N;
    int i{2};
    int counter{0};
    while(i * i <= N){
        while(N % i == 0){
            cout << i << endl;
            ++counter;
            N /= i;
        }
        ++i;
    }
    if(N != 1) cout << N << endl;
}