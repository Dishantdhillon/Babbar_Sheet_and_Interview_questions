void inorder(Node* root, vector<int> &v) {
    if(root == NULL) {
        return;
    }
    inorder(root -> left, v);
    v.push_back(root -> data);
    inorder(root -> right, v);
}
Node* bToDLL(Node *root) {
    vector<int> v;
    inorder(root, v);
    Node* head = newNode(v[0]);
    Node* tail = head;
    for(int i=1; i<v.size(); i++) {
        Node* temp = newNode(v[i]);
        tail -> right = temp;
        temp -> left = tail;
        tail = temp;
    }
    return head;
}