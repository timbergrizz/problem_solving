//#include <bits/stdc++.h>
//
//#define loop(i, n) for(long long i=1; i <= n ; ++i)
//using namespace std;
//
//long long v[80001]{0,};
//long long res[80001]{0,};
//
//int main() {
//    long long N;
//    cin >> N;
//
//    stack<long long> s;
//
//    s.push(1000000001);
//    long long result{0};
//
//    loop(i, N) {
//        cin >> v[i];
//        while (v[i] >= s.top()) s.pop();
//        // 스택을 이용해서 문제를 처리하는게 관권이었다.
//        // 우선 스택 내부는 항상 내림 차순으로 되어있다고 가정하자.
//        // 이때, 새로 입력된 값보다 작거나 같은 원소들은 다 스택에서 제외해간다.
//        // 그럼, 스택의 사이즈와 옥상이 보이는 건물의 수가 같아질 수 있게 된다.
//        // 이러한 설계에 집중을 해보도록 하자.
//        if (s.size() != 1) result += (s.size() - 1);
//        s.push(v[i]);
//    }
//
//    cout << result << "\n";
//}

// 두 번째 풀이
#include <bits/stdc++.h>

#define loop(i, n) for(long long i=1; i <= n ; ++i)
using namespace std;

long long v[80001]{0,};
long long res[80001]{0,};

int main() {
    long long N;
    cin >> N;
    loop(i, N) cin >> v[i];

    stack<long long> s;

    s.push(1000000000);
    long long result{0};

    loop(i, N) {
        while (v[i] >= s.top()) {
            result += s.size() - 2;
            //결국 동일한 풀이긴 한데, 이 경우는 비울때만 정답에 더해서, 마지막에 추가적인 처리를 수행했어야 한다.
            s.pop();
        }
        s.push(v[i]);
    }

    long long size = (long long)s.size() - 2;
    result += (size * (size + 1)) / 2;

    cout << result << "\n";
}