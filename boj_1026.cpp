#include <iostream>
#include <queue>
using namespace std;

int main(){
    int N; cin >> N;
    priority_queue<int, vector<int>, greater<int>> A;
    priority_queue<int, vector<int>, less<int>> B;

    int buf;
    for(int i=0 ; i < N; ++i){
        cin >> buf;
        A.push(buf);
    }

    for(int i=0 ; i < N; ++i){
        cin >> buf;
        B.push(buf);
    }

    long long result{0};
    while(N--){
        result += A.top() * B.top();
        A.pop();
        B.pop();
    }

    cout << result << "\n";
}