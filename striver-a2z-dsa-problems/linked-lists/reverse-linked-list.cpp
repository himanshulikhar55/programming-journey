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
/*
    Given the head of a singly linked list, reverse the list, and return the reversed list.
*/
ListNode* reverseList(ListNode* head) {
    if(!head || !head->next)
        return head;
    ListNode *prevNode=NULL, *nextNode=head->next, *currNode=head;
    while(currNode){
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
        if(nextNode)
            nextNode = nextNode->next;
    }
    return prevNode;
}
void printLL(ListNode* head){
    while(head){
        cout << head->val << ' ';
        head = head->next;
    }
    cout << '\n';
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
    head = reverseList(head);
    printLL(head);
    return 0;
}