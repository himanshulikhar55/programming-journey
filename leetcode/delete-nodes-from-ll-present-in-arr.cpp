#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    ListNode *prev = NULL, *curr = head, *temp;
    unordered_set<int> nums_in_nums, nums_in_head;
    for(int i : nums){
        nums_in_nums.insert(i);
    }
    temp = head;
    while(temp){
        nums_in_head.insert(temp->val);
        temp = temp->next;
    }
    unordered_set<int>::iterator it = nums_in_head.begin();
    while (it != nums_in_head.end()) {
        if (nums_in_nums.find(*it) == nums_in_nums.end())
            it = nums_in_head.erase(it);
        else
            ++it;
    }

    while(curr){
        if(nums_in_head.find(curr->val) != nums_in_head.end()){
            if(!prev){
                temp = curr->next;
                curr->next = NULL;
                curr = temp;
                head = curr;
            } else{
                prev->next = curr->next;
                curr->next = NULL;
                curr = prev->next;
            }
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}