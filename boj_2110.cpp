#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, C;
vector<long long> x(200000);

bool check(long long m){
    long long position{1}, count{0};
    for(int i=0; i < N; ++i){
        if(position <= x[i]){
            ++count;
            position = x[i] + m;
        }
        if(count == C){
            return true;
        }
    }
    return false;
}

int main(){
    cin >> N >> C;
    for(int i=0; i<N; ++i) cin >> x[i];
    sort(x.begin(), x.begin() + N);

    long long l = 0, r = 1000000001;
    long long m;
    while(l < r){
        m = (l + r) / 2;

        if(check(m)) l = m + 1;
        else r = m;
    }

    cout << l - 1 << endl;
}