/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void leftTraversal(TreeNode<int>* root, vector<int> &v) {
    if(root == NULL) {
        return;
    }
    if(root -> left) {
        v.push_back(root -> data);
        leftTraversal(root -> left, v);
    }
    else if(root -> right) {
        v.push_back(root -> data);
        leftTraversal(root -> right, v);
    }
}

void leafTraversal(TreeNode<int>* root, vector<int> &v) {
    if(root == NULL) {
        return;
    }
    leafTraversal(root -> left, v);
    if(!root -> left && !root -> right) {
        v.push_back(root -> data);
    }
    leafTraversal(root -> right, v);
}

void rightTraversal(TreeNode<int>* root, vector<int> &v) {
    if(root == NULL) {
        return;
    }
    if(root -> right) {
        rightTraversal(root -> right, v);
        v.push_back(root -> data);
    }
    else if(root -> left) {
        rightTraversal(root -> left, v);
        v.push_back(root -> data);
    }
}

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> v;
    v.push_back(root -> data);
    leftTraversal(root -> left, v);
    leafTraversal(root -> left, v);
    leafTraversal(root -> right, v);
    rightTraversal(root -> right, v);
    return v;
}