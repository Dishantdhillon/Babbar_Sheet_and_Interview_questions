#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int x) {
            data = x;
            left = right = NULL;
        } 
};

int sumOfGrandChildren(Node* node);
int sumTreeUtil(Node* root, map<Node*, int> m);

int sumTreeGrandchildren(Node* root, map<Node*, int> m) {
    int sum = 0;
    if(root -> left) {
        sum += sumTreeUtil(root -> left -> left, m) + sumTreeUtil(root -> left -> right, m);
    }
    if(root -> right) {
        sum += sumTreeUtil(root -> right -> left, m) + sumTreeUtil(root -> right -> right, m);
    }
    return sum;
}

int sumTreeUtil(Node* root, map<Node*, int>& m) {
    if(root == NULL) {
        return 0;
    }
    if(m.find(root) != m.end()) {
        return m[root];
    }
    int incl = root -> data + sumTreeGrandchildren(root, m);
    int excl = sumTreeUtil(root -> left, m) + sumTreeUtil(root -> right, m);
    m[root] = max(incl, excl);
    return m[root];
}

int sumTree(Node* root) {
    map<Node*, int> m;
    if(root == NULL) {
        return 0;
    }
    return sumTreeUtil(root, m);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    root->left->left = new Node(1);
 
    cout << sumTree(root) << endl;
    return 0;
}
