#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


deque<int> split(string b){
    deque<int> ans;
    stringstream ss{b};
    string buf;

    while(getline(ss, buf, ',')) ans.push_back(stoi(buf)) ;
    return ans;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        string p;
        cin >> p;
        bool first = true, flag = false;

        int n;
        cin >> n;

        string buf;
        cin >> buf;

        buf = buf.substr(1, buf.size() - 2);
        deque<int> v = split(buf);

        for(int i=0; i<p.size(); ++i) {
            if(p[i] == 'R') first = !first;
            if(p[i] == 'D') {
                if(v.empty()){
                    cout << "error\n";
                    flag = true;
                    break;
                }
                if(first) v.pop_front();
                else v.pop_back();
            }
        }

        if(!flag){
            cout << "[";
            if(first){
                while(!v.empty()){
                    cout << v.front();
                    v.pop_front();
                    if(!v.empty()) cout <<",";
                }
            }
            else {
                while(!v.empty()){
                    cout << v.back();
                    v.pop_back();
                    if(!v.empty()) cout <<",";
                }
            }
            cout << "]\n";
        }
    }
};