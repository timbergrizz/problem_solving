#include <iostream>
#include <queue>
#include <utility>
using namespace std;

//
int e;

int bfs(long long s){
    queue<pair<long long, int>> q;
    q.push({s, 0});

    while(!q.empty()){
        pair<long long, int> val = q.front();
        q.pop();
        if(val.first == e) return val.second + 1;

        long long p[2]{val.first * 10 + 1, val.first * 2};
        for(int i=0; i<2; ++i){
            if(p[i] <= 1000000000){
                q.push({p[i], val.second + 1});
            }
        }
    }
    return -1;
}

int main(){
    int s; cin >> s >> e;
    cout << bfs(s) << "\n";
}