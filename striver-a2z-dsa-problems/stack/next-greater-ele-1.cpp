#include<bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int len1 = nums1.size(), len2 = nums2.size();
    stack<int> nextGrEle;
    vector<int> ans = vector<int>(len1);
    unordered_map<int,int> nextGrEleMap;
    for(int i=0;i<len2;i++){
        while(!nextGrEle.empty() && nextGrEle.top() < nums2[i]){
            nextGrEleMap.insert({nextGrEle.top(), nums2[i]});
            nextGrEle.pop();
        }
        nextGrEle.push(nums2[i]);
    }
    for(int i=0;i<len1;i++){
        if(nextGrEleMap.find(nums1[i]) == nextGrEleMap.end())
            ans[i] = -1;
        else
            ans[i] = nextGrEleMap[nums1[i]];
    }
    return ans;
}
void printInt(int i){
    cout << i << ' ';
}
int main(){
    int n, m;
    cout << "Enter nums1: ";
    cin >> n;
    vector<int> nums1 = vector<int>(n);
    for(int i=0;i<n;i++){
        cin >> nums1[i];
    }
    cout << "Enter nums2: ";
    cin >> m;
    vector<int> nums2 = vector<int>(m);
    for(int i=0;i<m;i++){
        cin >> nums2[i];
    }
    vector<int> ans = nextGreaterElement(nums1, nums2);
    for_each(ans.begin(), ans.end(), printInt);
    cout << '\n';
    return 0;
}