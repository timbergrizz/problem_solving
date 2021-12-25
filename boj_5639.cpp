#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int elem;
    Node *par;
    Node *l;
    Node *r;

    Node(int n) {
        elem = n;
        par = l = r = NULL;
    }
};

class Tree {
public:
    vector<Node *> v;

    Tree(int r) {
        v.push_back(new Node{r});
    }

    void insert(int n) {
        Node * p;
        Node * c{v[0]};
        Node * N = new Node(n);

        while(c != NULL){
            p = c;
            if(c->elem > n) c = c->l;
            else c = c->r;
        }

        if(p->elem > n) p->l = N;
        else p->r = N;
        v.push_back(N);
    }

    void postTrav(Node *n) {
        if (n->l != NULL) postTrav(n->l);
        if (n->r != NULL) postTrav(n->r);
        cout << n->elem << endl;
    }

};

int main() {
    int input;
    cin >> input;
    Tree t{input};

    while(cin >> input) t.insert(input);
    t.postTrav(t.v[0]);
}