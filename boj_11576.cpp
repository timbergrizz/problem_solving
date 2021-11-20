#include <iostream>
#include <vector>
using namespace std;

int main(){
    int A, B; cin >> A >> B;
    int N; cin >> N;
    vector<int> v(N);
    for(int i=0; i < v.size(); ++i) cin >> v[i];

    int r{0}, b{1};
    for(int i=v.size() - 1; i >= 0; --i){
        r += v[i] * b;
        b *= A;
    }

    v.clear();

    while(r != 0){
        v.push_back(r % B);
        r /= B;
    }

    for(int i=v.size() - 1; i>=0; --i) cout << v[i] << " ";
    cout << endl;
}