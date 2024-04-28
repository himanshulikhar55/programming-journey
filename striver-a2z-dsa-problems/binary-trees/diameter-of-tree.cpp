#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int diameter = 0;
int calcDiameter(TreeNode *root){
    if(!root)
        return 0;
    int leftHeight = calcDiameter(root->left);
    int rightHeight = calcDiameter(root->right);
    diameter = max(leftHeight+rightHeight, diameter);
    return 1+max(leftHeight, rightHeight);
}
int diameterOfBinaryTree(TreeNode* root) {
    calcDiameter(root);
    return diameter;
}
TreeNode* constructBinTree(vector<int> &arr){
    if(arr.size() < 1)
        return NULL;
    int len = arr.size(), node=0;
    TreeNode *root = new TreeNode(arr[0]), *temp;
    queue<TreeNode*> nodes;
    nodes.push(root);
    while(!nodes.empty()){
        temp = nodes.front();
        nodes.pop();
        int idx = 2*node;
        if(idx+1 < len && arr[idx+1] != -1) {
            temp->left = new TreeNode(arr[idx+1]);
            nodes.push(temp->left);
        }
        if(idx+2 < len && arr[idx+2] != -1) {
                temp->right = new TreeNode(arr[idx+2]);
                nodes.push(temp->right);
        }
        ++node;
    }
    return root;
}
void printTreeLevelOrder(TreeNode *root){
    if(!root)
        return;
    queue<TreeNode*> nodes;
    TreeNode *temp;
    nodes.push(root);
    while(!nodes.empty()){
        temp = nodes.front();
        nodes.pop();
        if(!temp){
            cout << "-1 ";
            continue;
        }
        else
            cout << temp->val << ' ';
        if(!temp->left && !temp->right)
            continue;
        nodes.push(temp->left);
        nodes.push(temp->right);
    }
    cout << '\n';
}
int main(){
    int n;
    cout << "Enter the number of nodes and the level order traversal of the tree. Enter -1 if the node is null: \n";
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    TreeNode *root = constructBinTree(arr);
    //just to check if the tree is constructed right
    cout << "Printing the tree: \n";
    printTreeLevelOrder(root);
    int ans = diameterOfBinaryTree(root);
    cout << "The diameter of the given binary tree is: " << ans << '\n';
    return 0;
}