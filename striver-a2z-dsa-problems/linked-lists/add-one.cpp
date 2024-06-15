#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};
Node* addOne(Node *head) {
    // Your Code here
    if(!head)
        return;
    vector<int> arr;
    Node *temp = head;
    while(temp){
        arr.push_back(temp->data);
        temp = temp->next;
    }
    int len = arr.size(), carry = 1, sum;
    for(int i=len-1; i>=0;i--){
        sum = arr[i]+carry;
        arr[i] = sum%10;
        carry = sum/10;
    }
    temp = head;
    if(carry){
        head = new Node(1);
        head->next = temp;
    }
    for(int i=0;i<len;i++){
        temp->data = arr[i];
        temp = temp->next;
    }
    return head;
    // return head of list after adding one
}
void printLL(Node* head){
    while(head){
        cout << head->data << ' ';
        head = head->next;
    }
    cout << '\n';
}
int main(){
    int n, x;
    cin >> n;
    Node *head = NULL, *temp;
    for(int i=0;i<n;i++){
        cin >> x;
        if(!head){
            head = new Node(x);
            temp = head;
        } else {
            temp->next = new Node(x);
            temp = temp->next;
        }
    }
    head = addOne(head);
    printLL(head);
    return 0;
}
