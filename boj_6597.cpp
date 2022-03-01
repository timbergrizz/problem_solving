#include <bits/stdc++.h>

using namespace std;

string preOrder, inOrder;
int inOrderIdx[26]{0, };

void postOrderTraversal(int preOrderStart, int preOrderEnd, int inOrderStart, int inOrderEnd) {
    if (preOrderStart > preOrderEnd || inOrderStart > inOrderEnd) return;
//    cout << preOrderStart << " " << preOrderEnd << " " << inOrderStart << " " << inOrderEnd <<'\n' ;

    int rootIdx = inOrderIdx[preOrder[preOrderStart] - 'A'];
    int l = rootIdx - inOrderStart, r = inOrderEnd - rootIdx;

    postOrderTraversal(preOrderStart + 1, preOrderStart + l, inOrderStart, rootIdx - 1);
    postOrderTraversal(preOrderEnd - r + 1, preOrderEnd, rootIdx + 1, inOrderEnd);
    cout << inOrder[rootIdx];
}

int main() {
    string input;
    while (getline(cin, input) && !input.empty()) {
        int f = (int)input.find(' ');
        preOrder = input.substr(0, f);
        inOrder = input.substr(f+1, input.length() - f - 1);

        for (int i=0; i < inOrder.size(); ++i) inOrderIdx[inOrder[i] - 'A'] = i;
        int size = (int)preOrder.size();
        postOrderTraversal(0, size - 1, 0, size - 1);
        cout << endl;
    }
}