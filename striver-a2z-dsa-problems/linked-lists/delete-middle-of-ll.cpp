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
    Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
*/
bool isPalindrome(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    //now reverse the second-half of the LL
    ListNode *curr=slow, *prev=NULL, *next=slow->next;
    while(curr){
        curr->next = prev;
        prev = curr;
        curr = next;
        if(curr)
            next = curr->next;
    }
    ListNode *newHead = prev;
    while(head && newHead){
        if(head->val == newHead->val){
            head = head->next;
            newHead = newHead->next;
        } else {
            return false;
        }
    }
    return true;
}
/*
    The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing,
    where ⌊x⌋ denotes the largest integer less than or equal to x.
    For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.
*/
ListNode* deleteMiddle(ListNode* head) {
    if(!head->next)
        return NULL;
    ListNode *slow=head, *fast=head, *prev;
    while(fast && fast->next){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;
    delete(slow);
    return head;
}
void printLL(ListNode *head){
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
    head = deleteMiddle(head);
    cout << "LL after removing the middle element is: ";
    printLL(head);
    return 0;
}