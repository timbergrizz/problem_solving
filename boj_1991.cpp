#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    char elem;
    Node * parent;
    Node * l;
    Node * r;

    Node(char c){
        parent = l = r = NULL;
        elem = c;
    }
};

class Tree{
public:
    vector<Node *> v;
    int N;
    Node * root;

    Tree(int _N){
        N = _N;
        for(int i=0; i<N; ++i){
            v.push_back(new Node ('A' + i));
        }
        root = v[0];
    }

    void connect(char a, char b, char c){
        if(b != '.'){
            v[b - 'A']->parent =v[a - 'A'];
            v[a - 'A']->l = v[b -'A'];
        }
        if(c != '.'){
            v[c - 'A']->parent = v[a - 'A'];
            v[a - 'A']->r = v[c - 'A'];
        }
    }

    void preTrav(Node * n){
        cout << n->elem;
        if(n->l != NULL) preTrav(n->l);
        if(n->r != NULL) preTrav(n->r);
    }

    void inTrav(Node * n){
        if(n->l != NULL) inTrav(n->l);
        cout << n->elem;
        if(n->r != NULL) inTrav(n->r);
    }

    void postTrav(Node * n){
        if(n->l != NULL) postTrav(n->l);
        if(n->r != NULL) postTrav(n->r);
        cout << n->elem;
    }
};

int main(){
    int N; cin >> N;
    Tree t{N};
    for(int i{0}; i<N; ++i){
        char a, b, c; cin >> a >> b >> c;
        t.connect(a, b, c);
    }

    t.preTrav(t.root);
    cout << endl;
    t.inTrav(t.root);
    cout << endl;
    t.postTrav(t.root);
    cout << endl;
}
