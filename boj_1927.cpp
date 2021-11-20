#include <iostream>
#include <queue>
using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int>> v;
    int N; cin >> N;
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    while(N--){
        int x; cin >> x;
        if(x == 0){
            if(v.empty()) cout << 0 << "\n";
            else{
                cout << v.top() << "\n";
                v.pop();
            }
        }
        else v.push(x);
    }
}