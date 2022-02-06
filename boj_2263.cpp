#include <iostream>

using namespace std;

int inOrder[100001]{0,}, postOrder[100001]{0,}, idx[100001]{0,};


// 주어진 트리를 루트의 위치에 따라 반으로 쪼개간다.
// 인오더는 루트를 기준으로 왼쪽 / 오른쪽 서브트리로 나누어지게 되고, 포스트오더는 마지막 위치에 루트가 위치하게 된다.
// 그렇기 때문에, 포스트 오더를 통해 루트의 값을 찾고, 루트의 값을 바탕으로 인오더에서 루트 위치를 찾아, 왼쪽 / 오른쪽 서브트리로 나눌 수 있다.
// 이러한 과정을 통해 자식 서브 트리로 계속 나누고,
// 왼쪽 서브 트리부터 오른쪽 서브 트리까지 방문하면서 루트 값을 계속 출력해 주어진 트리를 전위 탐색한 결과값을 출력할 수 있다.

// 재귀 함수의 인자로 서브트리들이 시작되는 / 끝나는 인덱스를 입력한다.
void toPreOrder(int inOrderStart, int inOrderEnd, int postOrderStart, int postOrderEnd) {
    // 순회가 끝나는 기저 사례
    // 인덱스를 계속 줄여 start보다 작아질 때 끝낸다.
    if (inOrderStart > inOrderEnd || postOrderStart > postOrderEnd) return;

    // 중위 순회에서 루트가 위치하는 인덱스를 찾는다.
    // 이때 루트는 후위 순위의 가장 오른쪽 위치에 존재한다.
    int rootOnPost = idx[postOrder[postOrderEnd]];
    // 좌측의 서브 트리와 우측의 서브트리의 사이즈를 계산한다.
    int l = rootOnPost - inOrderStart, r = inOrderEnd - rootOnPost;
    // 루트의 값을 출력한다.
    cout << postOrder[postOrderEnd] << " ";

    // 좌측부터 서브트리에 대해 순회를 시작한다.
    toPreOrder(inOrderStart, rootOnPost - 1, postOrderStart, postOrderStart + l - 1);
    toPreOrder(rootOnPost + 1, inOrderEnd, postOrderStart + l, postOrderEnd - 1);
}

int main() {
    int N;
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        cin >> inOrder[i];
        idx[inOrder[i]] = i;
    }
    for (int i = 1; i <= N; ++i) cin >> postOrder[i];
    toPreOrder(1, N, 1, N);
}