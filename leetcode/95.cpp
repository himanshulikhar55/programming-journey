/*
Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values
from 1 to n. Return the answer in any order.

Example 1:
Input: n = 3
Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]

Example 2:
Input: n = 1
Output: [[1]]

Constraints:
1 <= n <= 8
*/
#include <bits/stdc++.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void print(TreeNode *root){
    if(root){
        print(root->left);
        std::cout << root->val << ' ';
        print(root->right);
    }
}

std::vector<TreeNode *> generateTreesHelper(int left, int right) {
    std::vector<TreeNode *> ans;
    if(left > right) {
        ans.push_back(NULL);
        return ans;
    }
    for(int i=left;i<=right;i++) {
        std::vector<TreeNode *> leftSubTree  = generateTreesHelper(left, i-1);
        std::vector<TreeNode *> rightSubTree = generateTreesHelper(i+1, right);
        for(int j=0;j<leftSubTree.size();j++) {
            for(int k=0;k<rightSubTree.size();k++) {
                TreeNode *root = new TreeNode(i);
                root -> left = leftSubTree[j];
                root->right  = rightSubTree[k];
                ans.push_back(root);
            }
        }
    }
    return ans;
}

std::vector<TreeNode*> generateTrees(int n) {
    return generateTreesHelper(1, n);
}

int main() {
    int n;
    std::cin >> n;
    std::vector<TreeNode *> ans = generateTrees(n);
    for(TreeNode* node : ans) {
        print(node);
        std::cout << std::endl;
    }
    return 0;
}