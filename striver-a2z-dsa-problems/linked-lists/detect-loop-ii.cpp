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
    Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
*/
ListNode *detectCycle(ListNode *head) {
    if(!head || !head->next)
        return NULL;
    ListNode *slow=head->next, *fast=head->next->next;
    while(slow && fast && fast->next){
        if(slow==fast){
            slow = head;
            while(slow!=fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return NULL;
}
void printLL(ListNode* head){
    while(head){
        cout << head->val << ' ';
        head = head->next;
    }
    cout << '\n';
}
int main(){
    cout << "At last, enter the position where the last node points to, '-1' means no loop and index starts from '1'\n";
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
    if(x>n || x<-1 || x ==0){
        cout << "Gotcha! Invalid index!\n";
        return 0;
    }
    ListNode *newTemp = head;
    while(x && x!=-1){
        --x;
        if(x == 0){
            temp->next = newTemp;
        }
        newTemp = newTemp->next;
    }
    ListNode *newHead = detectCycle(head);
    if(!newHead){
        cout << "There is no cycle. Printing the LL: ";
        printLL(head);
    } else {
        cout << "There is a cycle! Printing the LL, without the cycle: \n";
        newHead = head;
        for(int i=1;i<n;i++){
            newHead = newHead->next;
        }
        newHead->next = NULL;
        printLL(head);
    }
    return 0;
}