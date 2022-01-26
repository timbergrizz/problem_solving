#include <iostream>
#include <queue>
using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int>> pq;
    int N, res{0}, buf{0};
    cin >> N;

    while(N--){
        cin >> buf;
        pq.push(buf);
    }

    if(pq.size() != 1){
        while(true){
            buf = 0;

            buf += pq.top();
            pq.pop();

            buf += pq.top();
            pq.pop();

            res += buf;

            if(pq.empty()) break;
            pq.push(buf);
        }
    }
    cout << res << "\n";
}