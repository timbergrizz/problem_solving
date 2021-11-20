#include <iostream>
#include <vector>
using namespace std;

int K, N;
vector<int> v;

long long find(long long l, long long r){
    long long m;
    while(l < r){
        m = (l + r) >> 1;
        long t = 0;

        for(int i = 0; i < K; ++i){
            t += v[i] / m;
        }

        if(t >= N) l= m + 1;
        else r = m;
    }
    return l;
}

int main(){
    cin >> K >> N;
    for(int i=0; i<K; ++i) {
        int buf; cin >> buf;
        v.push_back(buf);
    }
    cout << find(0,100000000000000 ) - 1 << "\n";
}
