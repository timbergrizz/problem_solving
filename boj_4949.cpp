#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    while(true){
        string str;
        getline(cin, str);

        if(str == ".") break;

        stack<int> brackets;
        bool success = true;

        for(int i=0; i<str.length(); ++i){
            if(str[i] == '(') brackets.push(1);
            else if(str[i] == '[') brackets.push(2);
            else if(str[i] == ')'){
                if(brackets.empty() ) {
                    success = false;
                    break;
                }
                else if(brackets.top() != 1){
                    success = false;
                    break;
                }
                brackets.pop();
            }
            else if(str[i] == ']'){
                if(brackets.empty()){
                    success = false;
                    break;
                }
                else if(brackets.top() != 2){
                    success = false;
                    break;
                }

                brackets.pop();
            }
        }
        if(!brackets.empty()) success = false;

        if(success) cout << "yes\n";
        else cout << "no\n";
    }
}