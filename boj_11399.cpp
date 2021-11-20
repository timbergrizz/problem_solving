#include <iostream>
#include <queue>
using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int>> p;
    int N; cin >> N;
    int counter{0}, total{0};

    while(N--){
        int buf; cin >> buf;
        p.push(buf);
    }

    while(!p.empty()){
        counter += p.top();
        total += counter;
        p.pop();
    }

    cout << total << endl;
}