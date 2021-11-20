#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, K; cin >> N >> K;
    vector<bool> v(N + 1, false);
    vector<int> order(N + 1);

    int position{0};
    for(int i=0; i < N; ++i){
        for(int j=0; j < K; ++j) {
            if(position >= N) position %= N;
            if(v[++position]) --j;
        }
        v[position] = true;
        order[i] = position;
    }
    cout << '<';
    for(int i=0; i<N -1; ++i) cout << order[i] <<", ";
    cout << order[N -1] << ">\n";
}