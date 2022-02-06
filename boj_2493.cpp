#include <bits/stdc++.h>
#define loop(i, n) for(int i=0; i < n; ++i)
using namespace std;

typedef pair<int, int> pii;

int result[500000];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin >> N;
    stack<pii> s;

    int buf;
    loop(i, N) {
        cin >> buf;
        s.push({buf, i});
    }

    stack<pii> q;

    while(!s.empty()){
        pii top = s.top();
        s.pop();

        if(!q.empty()){
            while(top.first >= q.top().first){
                result[q.top().second] = top.second + 1;
                q.pop();
                if(q.empty()) break;
            }
        }
        q.push(top);
    }

    loop(i, N) cout << result[i] << " ";
}