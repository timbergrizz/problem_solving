#include <iostream>
#include <memory.h>
#include <cmath>

using namespace std;

bool broken[10];

int check(int n) {
    if(n == 0){
        if(broken[0]) return -1;
        else return 1;
    }

    int buf{n};
    int counter{0};

    while (buf) {
        ++counter;
        if (broken[buf % 10]) return -1;
        buf /= 10;
    }
    return counter;
}

int main() {
    int N;
    cin >> N;
    int M;
    cin >> M;
    memset(broken, false, sizeof(broken));

    int buf{0};
    while (M--) {
        cin >> buf;
        broken[buf] = true;
    }

    int count{abs(N - 100)};

    for (int i = 0; i <= 1000000; ++i) {
        if (i == 100) continue;

        int c = check(i);
        buf = abs(i - N) + c;

        if (c >= 0) {
            if (buf < count) {
                count = buf;
            }
        }
    }

    cout << count << "\n";
}