#include <iostream>
#include <vector>
using namespace std;

int g[100001] {0, };
int K;

vector<int> check(int n){
    return {n + 1, n - 1, n * 2};
}

bool checkExist(int n){
    if (n >= 0 && n < 100001)
        return g[n] == 0;
    else return false;
}

void bfs(vector<int> p, int counter){
    vector<int> n;
    for(int i=0; i < p.size(); ++i){

        vector<int> buf = check(p[i]);
        for(int j=0; j<3; ++j){
            if(checkExist(buf[j])){
                g[buf[j]] = counter + 1;
                if(buf[j] == K) return;
                n.push_back(buf[j]);
            }
        }
    }
    if(!n.empty()) bfs(n, counter + 1);
}

int main(){
    int N; cin >> N >> K;
    vector<int> p{N};

    if(N == K) cout << 0 << endl;
    else {
        bfs(p, 0);
        //        for(int i=0; i<=K; ++i){
        //            cout << g[i] << " ";
        //        }
        //        cout << endl;
        cout << g[K] << endl;
    }
}