#include <iostream>
#include <vector>
using namespace std;

int p;
int pow(int n){
    int result{1};
    for(int i=0; i<p; ++i){
        result *= n;
    }
    return result;
}

int dn(int A){
    int bufA{A}, result{0};
    while(bufA != 0){
        result += pow(bufA % 10);
        bufA /= 10;
    }
    return result;
}

int main(){
    int A; cin >> A >> p;

    vector<int> v;
    vector<int> exist(500000);
    v.push_back(A);

    int i{A};
    int counter{0};
    while(true){
        if(exist[i] != 0) break;
        exist[i] = ++counter;
        v.push_back(i);
        i = dn(i);
    }
    cout << exist[i] - 1 << endl;
}