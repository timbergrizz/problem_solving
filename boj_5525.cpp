#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;

    int counter{0};
    int c{0};

    for (int i = 1; i < S.length(); ++i) {
        if (S[i - 1] == 'I' && S[i] == 'O'){
            c++;
        }
        else if(S[i] == 'I' && S[i - 1] == 'O'){
            if(c >= N) counter++;
        }
        else c = 0;
    }

    cout << counter << "\n";
}