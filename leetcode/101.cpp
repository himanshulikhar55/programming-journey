struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
bool isSymmetricHelper(TreeNode *left, TreeNode *right) {
    if(!left && !right)
        return true;
    if(left && right && left->val == right->val)
        return isSymmetricHelper(left->right, right->left) && isSymmetricHelper(left->left, right->right);
    return false;
}
bool isSymmetric(TreeNode* root) {
    return !root || isSymmetricHelper(root->left, root->right);
}