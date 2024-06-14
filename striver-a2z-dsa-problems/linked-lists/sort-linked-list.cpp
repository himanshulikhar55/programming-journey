#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* sortList(ListNode* head) {
    if(!head)
        return head;
    vector<int> arr;
    ListNode *temp = head;
    while(temp){
        arr.push_back(temp->val);
        temp = temp->next;
    }
    sort(arr.begin(), arr.end());
    temp = head;
    int i = 0;
    while(temp){
        temp->val = arr[i];
        temp = temp->next;
        ++i;
    }
    return head;
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
    head = sortList(head);
    printLL(head);
    return 0;
}