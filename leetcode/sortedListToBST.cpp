#include<bits/stdc++.h>
using namespace std;
/**
 * Using the standard declaration provided by Leetcode for the node of linkedlist and tree .
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void convertListNodeToArr(ListNode *head, vector<int> &arr){
    while(head){
        arr.push_back(head->val);
        head = head->next;
    }
}
TreeNode* constructBST(vector<int> arr, int lo, int hi){
    if(lo <= hi){
        int mid = lo + (hi-lo)/2;
        TreeNode * root = new TreeNode(arr[mid]);
        root->left  = constructBST(arr, lo, mid - 1);
        root->right = constructBST(arr, mid + 1, hi);
        return root;
    }
    return NULL;
}
TreeNode *sortedListToBST(ListNode* head){
    vector<int> arr;
    convertListNodeToArr(head, arr);
    cout << "Constructed the Array!\n";
    int lo = 0, hi = arr.size() - 1;
    TreeNode *root = constructBST(arr, lo, hi);
    return root;
}
void inorder(TreeNode *root){
    if(!root)
        return;
    inorder(root->left);
    cout << root->val << ' ';
    inorder(root->right);
}
int main(){
    cout << "Enter the number of nodes followed by the nodes (in a sorted manner): ";
    int n, num;
    cin >> n;
    ListNode *head = NULL, *temp = NULL;
    for(int i=0;i<n;i++){
        cin >> num;
        if(!head){
            head = new ListNode(num);
            temp = head;
        }
        else{
            temp->next = new ListNode(num);
            temp = temp->next;
        }
    }
    cout << "Constructed Linked List!\n";
    TreeNode *root = sortedListToBST(head);
    cout << "Constructed the BST. Now if we do an inorder traversal of this, we should get integers in an ascending order.\n";
    inorder(root);
    cout << '\n';
    return 0;
}
/**
 * Since we need a height balanced BST, we should make the mid element as the root.
 * Then recursively make the root of left subtree as left child and right subtree as right child.
*/