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
    bool isPal = isPalindrome(head);
    if(isPal)
        cout << "Yes, given LL is a palindrome\n";
    else
        cout << "No, given LL is not a palindrome\n";
    return 0;
}