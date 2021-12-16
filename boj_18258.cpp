#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    deque<int> v;
    string oper;
    int buf;
    while (N--) {
        cin >> oper;
        if(oper == "push"){
            cin >> buf;
            v.push_back(buf);
        }
        else if(oper == "size") cout << v.size() << "\n";
        else if(oper == "empty") cout << v.empty() << "\n";
        else if(v.empty()) cout << -1 << "\n";
        else if(oper == "pop") {
            buf = v.front();
            v.pop_front();
            cout << buf << "\n";
        }
        else if(oper == "front") cout << v.front() << "\n";
        else if(oper == "back") cout << v.back() << "\n";
    }
}