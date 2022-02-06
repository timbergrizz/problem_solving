#include <bits/stdc++.h>

using namespace std;

int preOrder[1001]{0, }, inOrder[1001]{0, }, inOrderIdx[1001]{0, };

void getPostOrder(int inOrderStart, int inOrderEnd, int preOrderStart, int preOrderEnd){
//    cout << inOrderStart << inOrderEnd << preOrderStart << preOrderEnd;
    if(inOrderStart > inOrderEnd || preOrderStart > preOrderEnd) return;

    int rootIdx = inOrderIdx[preOrder[preOrderStart]];
    int leftTreeSize = rootIdx - inOrderStart, rightTreeSize = inOrderEnd - rootIdx;
//    cout << leftTreeSize << " " << rightTreeSize << "\n";

    getPostOrder(inOrderStart, rootIdx - 1, preOrderStart + 1, preOrderStart + leftTreeSize);
    getPostOrder(rootIdx + 1, inOrderEnd, preOrderEnd - rightTreeSize + 1, preOrderEnd);
    cout << preOrder[preOrderStart] << " ";
}

int main() {
    int T; cin >> T;
    while(T--){
        memset(preOrder, 0, sizeof preOrder);
        memset(inOrder, 0, sizeof inOrder);
        memset(inOrderIdx, 0, sizeof inOrderIdx);

        int N; cin >> N;
        for(int i=1; i <= N; ++i) cin >> preOrder[i];
        for(int i=1; i <= N; ++i) {
            cin >> inOrder[i];
            inOrderIdx[inOrder[i]] = i;
        }
        getPostOrder(1, N, 1, N);
        cout << "\n";
    }
}