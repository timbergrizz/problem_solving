#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    
    const int NN{N};
    int real_sub[NN]; 
    for(int i=0; i<NN; i++){
        cin >> real_sub[i];
    }

    sort(real_sub, real_sub+NN);
    cout << real_sub[0] * real_sub[NN-1] << endl; 
}