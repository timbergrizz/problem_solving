#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, K; cin >> N >> K;
    vector<int> A(N);
    for(int i=0; i<N; ++i){
        int buf; cin >> buf;
        A[i] = buf;
    }

    int counter{0};
    while(K > 0){
        int i=N-1;
        for(; i>=0; --i){
            if(A[i] <= K){
                break;
            }
        }
        K -= A[i]; ++counter;
    }
    cout << counter << endl;
}