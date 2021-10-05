#include<bits/stdc++.h>
using namespace std;

class Node {
	public:
	    int data;
	    Node* left;
	    Node* right;
	    Node(int x) {
	        data = x;
	        left = right = NULL;
	    }
};

Node* insert(Node* root, int key) {
    if(root == NULL) {
        return new Node(key);
    }
    if(root -> data < key) {
        insert(root -> right, key);
    }
    else if(root -> data > key) {
        insert(root -> left, key);
    }
    return root;
}

void inorder(Node* root, vector<int> &v) {
	if(root == NULL) {
		return;
	}
	inorder(root -> left, v);
	v.push_back(root -> data);
	inorder(root -> right, v);
}

Node* construct_bst(int pre[], int n) {
    Node* root = NULL;
	root = insert(root, pre[0]);
    for(int i=1; i<n; i++) {
        insert(root, pre[i]);
    }
    vector<int> v;
    inorder(root, v);
    for(int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
}

int main() {
    int n;
    cin >> n;
    int pre[n];
    for(int i=0; i<n; i++) {
        cin >> pre[i];
    }
    Node* root = construct_bst(pre, n);
    return 0;
}
