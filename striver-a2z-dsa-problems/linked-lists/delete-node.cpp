#include<bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x){
        val = x;
        next = NULL;
    }
};
void printLL(ListNode* head){
    while(head){
        cout << head->val << ' ';
        head = head->next;
    }
    cout << '\n';
}
/*
    Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:

    The value of the given node should not exist in the linked list.
    The number of nodes in the linked list should decrease by one.
    All the values before node should be in the same order.
    All the values after node should be in the same order.
*/
void deleteNode(ListNode* node) {
    while(true){
        node->val = node->next->val;
        if(!node->next->next){
            node->next = NULL;
            break;
        }
        node = node->next;
    }
}
int main(){
    int n, x;
    cin >> n;
    ListNode *head = NULL, *temp;
    for(int i=0;i<n;i++){
        cin >> x;
        if(!head){
            head = new ListNode(x);
            temp = head;
        } else {
            temp->next = new ListNode(x);
            temp = temp->next;
        }
    }
    cin >> x;
    temp = head;
    while(temp){
        if(temp->val == x){
            deleteNode(temp);
            break;
        }
        temp = temp->next;
    }
    printLL(head);
    return 0;
}