#include<bits/stdc++.h>
#include<sstream>
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

void inOrder(Node* node) {
    if(node == NULL) {
        return;
    }
    inOrder(node -> left);
    cout << node -> data << " ";
    inOrder(node -> right);
}

void preOrder(Node* node) {
    if(node == NULL) {
        return;
    }
    cout << node -> data << " ";
    preOrder(node -> left);
    preOrder(node -> right);
}

void postOrder(Node* node) {
    if(node == NULL) {
        return;
    }
    postOrder(node -> left);
    postOrder(node -> right);
    cout << node -> data << " ";
}

Node* buildTree(string s) {
    if(s.length() == 0 || s[0] == 'N') {
        return NULL;
    }
    vector<string> ip;
    istringstream iss(s);
    for(string s; iss >> s; ) {
        ip.push_back(s);
    }
    Node* root = new Node(stoi(ip[0]));
    queue<Node*> q;
    q.push(root);
    int i = 1;
    while(!q.empty() && i < ip.size()) {
        Node* curr = q.front();
        q.pop();
        string currValue = ip[i];
        if(currValue != "N") {
            curr -> left = new Node(stoi(currValue));
            q.push(curr -> left);
        }
        i++;
        if(i > ip.size()) {
            break;
        }
        currValue = ip[i];
        if(currValue != "N") {
            curr -> right = new Node(stoi(currValue));
            q.push(curr -> right);
        }
        i++;
    }
    return root;
}

int main() {
    string s;
    cin >> s;
    Node* root = buildTree(s);
    inOrder(root);
    preOrder(root);
    postOrder(root);
    return 0;
}
