//boj_1874
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> input;
    vector<int> result;

    for(int i=0; i < n; ++i){
        int buf; scanf("%d", &buf);
        input.push_back(buf);
    }

    stack<int> st;
    int position{0};
    int counter{1};

    while(counter <= n + 1 && position < n){
        if(st.empty()){
            st.push(counter++);
            result.push_back(1);
        }
        else if(st.top() == input[position]){
            st.pop();
            result.push_back(2);
            ++position;
        }
        else{
            st.push(counter++);
            result.push_back(1);
        }
    }


    if(st.empty()){
        for(int i=0; i<result.size(); ++i){
            if(result[i] == 1){
                printf("+\n");
            }
            else if(result[i] == 2){
                printf("-\n");
            }
        }
    }
    else {
        printf("NO\n");
    }
}