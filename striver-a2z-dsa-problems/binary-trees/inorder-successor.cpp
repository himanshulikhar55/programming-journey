#define NULL 0
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
Node * inOrderSuccessor(Node *root, Node *x) {
    if(!root)
        return NULL;
    if(root->data > x->data){
        Node *inorderSucc = inOrderSuccessor(root->left, x);
        if(inorderSucc){
            if(inorderSucc->data < root->data)
                return inorderSucc;
            return root;
        }
        return root;
    }
    return inOrderSuccessor(root->right, x);
}