#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int M, N, x, y;
        cin >> M >> N >> x >> y;
        int counter{-1};

        //        x와 y의 관계는 모듈러 연산값으로 생각할 수 있다. x는 시행 횟수 % M, y는 시행횟수 % N
        //        x를 시행 횟수라고 여기고 M씩 증가시킬 때, 시행횟수 % N이 y값과 같은 경우 이때의 시행횟수가 정답이 되게 된다.
        for (; x <= M * N; x += M) {
            if (x % N == y % N) {
                counter = x;
                break;
            }
        }

        cout << counter << endl;
    }
}