#include <iostream>
using namespace std;

int R, C;

void v(long long x, long long y, long long s, long long o){
    if(x == R && y == C){
        cout << o << "\n";
        return;
    }
    if(s >= 2){
        long long _s = (s / 2);

        if(R >= x + _s){
            if(C >= y + _s) v(x + _s, y + _s, _s, o + 3 * _s * _s);
            else v(x + _s, y, _s, o + _s * _s);
        }
        else{
            if(C >= y + _s) v(x, y + _s, _s, o + 2 * _s * _s);
            else v(x, y, _s, o);
        }
    }
}

int main(){
    int N; cin >> N >> C >> R;
    int res{1};
    for(int i=0; i<N; ++i) res *= 2;
    v(0, 0, res, 0);
}