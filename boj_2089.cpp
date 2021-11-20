#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v;
    int N; cin >> N;

    while(N != 0){
        v.push_back(N % -2);

        if(N % -2 == -1) N -= 2;
        N /= -2;
    }

    if(v.empty()) cout << 0;
    for(int i=v.size() - 1; i>=0; --i){
        if(v[i] == 0) cout << 0;
        else cout << 1;
    }
    cout << endl;
}