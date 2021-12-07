#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string buf;
    cin >> buf;

    stack<int> v;
    int val{0};

    for (int i = 0; i < buf.length(); ++i) {
        if (buf[i] == '+') {
            v.push(val);
            v.push(-2);
            val = 0;
        } else if (buf[i] == '-') {
            v.push(val);
            v.push(-1);
            val = 0;
        } else val = val * 10 + (buf[i] - '0');
    }

    if (val != 0) v.push(val);
    stack<int> minus;

    int result{0};

    while (!v.empty()) {
        int b1 = v.top();
        v.pop();

        if(!v.empty()){
            if (v.top() == -2) {
                v.pop();
                int b2 = v.top();
                v.pop();

                v.push(b1 + b2);
            }
            else if(v.top() == -1){
                v.pop();
                minus.push(b1);
            }
        }
        else result = b1;
    }

    while(!minus.empty()){
        result -= minus.top();
        minus.pop();
    }
    cout << result << "\n";
}