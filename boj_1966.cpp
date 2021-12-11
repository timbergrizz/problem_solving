#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    int cases; cin >> cases;
    for(int caseNum=0; caseNum < cases; ++caseNum){
        queue<int> printQueue;

        int elementNum, order; cin >> elementNum >> order;
        for(int i=0; i<elementNum; ++i){
            int buf; cin >> buf;
            printQueue.push(buf);
        }

        int counter{0};

        while(order != -1){
            int success{1};
            int buf1{printQueue.front()}; printQueue.pop();

            for(int i=0; i<printQueue.size(); ++i){
                int buf2{printQueue.front()}; printQueue.pop();
                if(buf2 > buf1){
                    success = 0;
                }
                printQueue.push(buf2);
            }

            if(success == 0){
                printQueue.push(buf1);
                if(order == 0){
                    order = printQueue.size() - 1;
                }
                else --order;
            }
            else if (success == 1) {
                --order, ++counter;
            }
        }
        cout << counter << endl;
    }
}