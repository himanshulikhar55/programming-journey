#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if(!root)
        return {};
    vector<vector<int>> zigZagTraversal;
    queue<TreeNode*> nodes;
    nodes.push(root);
    //tells how we are traversing the current level
    bool leftToRight = true;
    TreeNode *temp;
    int len = 1;
    while(!nodes.empty()){
        len = nodes.size();
        vector<int> tempNodes(len);
        //if we have to go left to right, fill from index 0, else from end to 0
        for(int i=0;i<len;i++){
            temp = nodes.front();
            nodes.pop();
            if(leftToRight){
                tempNodes[i] = temp->val;
            } else {
                tempNodes[len-1-i] = temp->val;
            }
            if(temp->left)
                nodes.push(temp->left);
            if(temp->right)
                nodes.push(temp->right);
        }
        zigZagTraversal.push_back(tempNodes);
        leftToRight = !leftToRight;
    }
    return zigZagTraversal;
}