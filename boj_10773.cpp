//boj_10773
#include <iostream>
#include <stack>
using namespace std;

int main(){
    int count; scanf("%d", &count);
    stack<int> input;

    for(int i=0; i<count; ++i){
        int num; scanf("%d", &num);
        if(num == 0){
            if(input.empty()){
                continue;
            }
            else input.pop();
        }
        else{
            input.push(num);
        }
    }

    int result{0};
    while(!input.empty()){
        result += input.top();
        input.pop();
    }
    printf("%d\n", result);
}