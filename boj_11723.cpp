#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<bool> v(21);
    int M; cin >> M;

    while(M--){
        string oper; cin >> oper;
        if(oper == "all"){
            for(int i=1; i<=20; ++i){
                v[i] = true;
            }
        }
        else if(oper == "empty"){
            for(int i=1; i<=20; ++i){
                v[i] = false;
            }
        }
        else{
            int x; cin >> x;
            if(oper == "add") v[x] = true;
            else if(oper == "remove") v[x] = false;
            else if(oper == "check") cout << v[x] << "\n";
            else if(oper == "toggle") {
                if(v[x]) v[x] = false;
                else v[x] = true;
            }
        }

    }
}