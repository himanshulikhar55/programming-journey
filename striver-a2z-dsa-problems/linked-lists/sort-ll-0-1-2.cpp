#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};
Node* segregate(Node *head) {
    //Base case
    if(!head || !head->next)
        return head;
    Node *zero = NULL, *one = NULL, *two = NULL, *temp;
    Node *zeroOrigin = NULL, *oneOrigin = NULL, *twoOrigin = NULL;
    // cout << "HERE\n";
    if(head->data == 0){
        zeroOrigin = head;
        head = head->next;
        zeroOrigin->next = NULL;
        zero = zeroOrigin;
    }
    else if(head->data == 1){
        oneOrigin = head;
        head = head->next;
        oneOrigin->next = NULL;
        one = oneOrigin;
    }
    else{
        twoOrigin = head;
        head = head->next;
        twoOrigin->next = NULL;
        two = twoOrigin;
    }
    // cout << head->data << ' ';
    temp = head;
    while(temp){
        // cout << temp->data << ' ';
        if(temp->data == 0){
            if(!zero){
                zero = temp;
                zeroOrigin = temp;
                temp = temp->next;
                if(oneOrigin)
                    zero->next = oneOrigin;
                else
                    zero->next = twoOrigin;
            } else {
                zero->next = temp;
                temp = temp->next;
                zero = zero->next;
                if(oneOrigin)
                    zero->next = oneOrigin;
                else
                    zero->next = twoOrigin;
                
            }
        } else if(temp->data == 1){
            if(!one){
                one = temp;
                oneOrigin = one;
                temp = temp->next;
                if(zero)
                    zero->next = one;
                one->next = twoOrigin;
            } else{
                one->next = temp;
                temp = temp->next;
                one = one->next;
                one->next = twoOrigin;
                
            }
        } else {
            if(!two){
                two = temp;
                twoOrigin = temp;
                temp = temp->next;
                //if we have 1s
                if(one)
                    one->next = two;
                else if(zero)
                    zero->next = two;
                two->next = NULL;
            } else{
                two->next = temp;
                temp = temp->next;
                two = two->next;
                two->next = NULL;
                
            }
        }
    }
    if(zeroOrigin)
        return zeroOrigin;
    else if(oneOrigin)
        return oneOrigin;
    return twoOrigin;
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
    head = segregate(head);
    printLL(head);
    return 0;
}