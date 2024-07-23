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
    Given the heads of two singly linked-lists headA and headB,
    return the node at which the two lists intersect.
    If the two linked lists have no intersection at all, return null.
*/
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int len1=0, len2=0;
    ListNode *temp1=headA, *temp2=headB;
    while(temp1){
        ++len1;
        temp1 = temp1->next;
    }
    while(temp2){
        ++len2;
        temp2 = temp2->next;
    }
    temp1 = headA;
    temp2 = headB;
    if(len1>len2){
        while(len1!=len2){
            --len1;
            temp1 = temp1->next;
        }
    } else{
        while(len1!=len2){
            --len2;
            temp2 = temp2->next;
        }
    }
    while(temp1){
        if(temp1 == temp2)
            return temp1;
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return temp1;
}