#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    while(N--){
        int K; cin >> K;
        vector<int> v(K + 1);

        for(int i=1; i<=K; ++i) cin >> v[i];

        int counter{0};
        for(int i=1; i<=K; ++i){
            if(v[i] != 0){
                ++counter;
                int k{i};
                while(v[k] != 0){
                    int buf{k};
                    k = v[k];
                    //                    cout << k << " " << v[k] << endl;
                    v[buf] = 0;
                }
            }
        }

        cout << counter << "\n";
    }
}