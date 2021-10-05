#include<bits/stdc++.h>
using namespace std;

class Node {
	public:
		int data;
    	Node* left;
    	Node* right;
    	Node(int x) {
        	data = x;
        	left = NULL;
        	right = NULL;
    	}
};

void diagonal_traversal_util(Node* root, int d, map<int, vector<int> > &diagonal) {
    if(root == NULL) {
        return;
    }
    diagonal[d].push_back(root -> data);
    diagonal_traversal_util(root -> left, d+1, diagonal);
    diagonal_traversal_util(root -> right, d, diagonal);
}

void diagonal_traversal(Node* root) {
    map<int, vector<int> > diagonal;
    diagonal_traversal_util(root, 0, diagonal);
    for(auto it:diagonal) {
        vector<int> v = it.second();
        for(auto it:v) {
            cout << it << " ";
        }
        cout << endl;
    }
}

int main() {
    Node* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);

    diagonal_traversal(root);
    return 0;
}
