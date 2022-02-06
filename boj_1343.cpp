#include <bits/stdc++.h>
using namespace std;

char v[50];

int main(){
    string buf; cin >> buf;
    queue<int> v;
    int cnt{0};

    for(int i=0; i < buf.size(); ++i){
        if(buf[i] == '.'){
            v.push(cnt);
            cnt = 0;
        }
        else cnt++;
    }
    v.push(cnt);

    string result;
    while(!v.empty()){
        if(v.front() % 2){
            result = "-1";
            break;
        }

        int f = v.front();
        v.pop();

        while(f){
            if(f >= 4){
                result += "AAAA";
                f -= 4;
            }
            else {
                result += "BB";
                f -= 2;
            }
        }
        if(!v.empty()) result += '.';
    }
    cout << result << endl;
}