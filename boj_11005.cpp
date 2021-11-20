#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long n; int b; cin >> n >> b;
    vector<int> v;

    while(n != 0){
        v.push_back(n % b);
        n /= b;
    }

    for(int i = v.size() - 1; i >= 0; --i){
        if(v[i] < 10) cout << v[i];
        else {
            char c = 'A' + (v[i] - 10);
            cout << c;
        }
    }
    cout << endl;
}