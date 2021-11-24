#include <iostream>

using namespace std;

int main() {
    const int format[3]{15, 28, 19};
    int E, S, M; cin >> E >> S >> M;
    int v[3]{1, 1, 1};
    int counter{1};
    while(v[0] != E || v[1] != S || v[2] != M){
        for(int i=0; i<3; ++i){
            v[i]++;
            if(format[i] < v[i]) v[i] = 1;
        }
        ++counter;
    }
    cout << counter << endl;
}