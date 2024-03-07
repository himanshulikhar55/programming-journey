#include<bits/stdc++.h>
using namespace std;

struct LinkedList {
    int val;
    LinkedList *next;
    LinkedList(int x){
        val = x;
        next = NULL;
    }
};

int main(){
    cout << "Enter the number of nodes: ";
    int len, temp;
    cin >> len;
    LinkedList *head = NULL;
    LinkedList *tempNode;
    for (int i=0;i<len;i++){
        cin >> temp;
        if(head){
            tempNode->next = new LinkedList(temp);
            tempNode = tempNode->next;
        } else {
            head = new LinkedList(temp);
            tempNode = head;
        }
    }
    while(head) {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << '\n';
    return 0;
}