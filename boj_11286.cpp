#include <iostream>
#include <queue>

using namespace std;

struct val {
    int v;
    val(int _v){
        v = _v;
    }
};

bool operator<(val A, val B){
    int bufA{A.v}, bufB{B.v};
    if(bufA < 0) bufA *= -1;
    if(bufB < 0) bufB *= -1;
    if(bufA == bufB) return A.v > B.v;
    return bufA > bufB;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    int buf;
    priority_queue<val> v;
    while(N--){
        cin >> buf;
        if(!buf){
            if(v.empty()) cout << 0 << "\n";
            else{
                cout << v.top().v << endl;
                v.pop();
            }
        }
        else{
            v.push({buf});
        }
    }
}
