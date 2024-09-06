#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};
vector <int> boundary(Node *root) {
    if(!root)
        return {};
    stack<Node*> nodes, rightBoundary;
    Node *temp = root;
    vector<int> ans;
    while(temp){
        if(temp->left || temp->right)
            nodes.push(temp);
        ans.push_back(temp->data);
        temp = temp->left;
    }
    while(!nodes.empty()){
        temp = nodes.top();
        if(temp == root){
            temp = temp->right;
            //now we have the right boundary
            while(temp){
                rightBoundary.push(temp);
                temp = temp->right;
            }
            //we can now continue to explore as we explored
        }
        nodes.pop();
        //go to this node's left until it has one and push that leaf.
        if(temp->right){
            temp = temp->right;
            while(temp){
                if(!temp->left && !temp->right){
                    ans.push_back(temp->data);
                    break;
                }
                nodes.push(temp);
                temp = temp->left;
            }
        }
    }
    while(!rightBoundary.empty()){
        ans.push_back((rightBoundary.top())->data);
        rightBoundary.pop();
    }
    return ans;
}