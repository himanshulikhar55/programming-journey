/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as
descendants (where we allow a node to be a descendant of itself).”
Constraints:

    - The number of nodes in the tree is in the range [2, 10^5].
    - -10^9 <= Node.val <= 10^9
    - All Node.val are unique.
    - p != q
    - p and q will exist in the BST.

*/
#include <iostream>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root->val < p->val) {
        if(root->val < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        } else if(root->val == q->val) {
            return q;
        }
        return root;
    } else if(root->val == p->val) {
        return p;
    } else {
        if(root->val <= q->val) {
            return root;
        }
        return lowestCommonAncestor(root->left, p, q);
    }
    return root;
}
int main(){}