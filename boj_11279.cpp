#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    priority_queue<int> v;
    while(N--){
        int x; cin >> x;
        if(x == 0){
            if(v.empty()) cout << 0 << '\n';
            else{
                cout << v.top() << '\n';
                v.pop();
            }
        }
        else v.push(x);
    }
}