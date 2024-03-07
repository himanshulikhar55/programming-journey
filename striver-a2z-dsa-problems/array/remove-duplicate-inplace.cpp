#include<bits/stdc++.h>
using namespace std;
void printElem(int i){
    cout << i << ' ';
}
int removeDuplicates(vector<int>& nums) {
    if(nums.size() < 2)
        return nums.size();
    unordered_map<int,int> occ;
    int n = nums.size(), currPos = 0, index = 0;
    while(index < n){
        if(occ.find(nums[index]) != occ.end()){
            ++index;
            continue;
        } else {
            occ[nums[index]] = 1;
            nums[currPos] = nums[index];
            ++index;
            ++currPos;
        }
    }
    return currPos;
}
int main(){
    int n, temp;
    vector<int> arr;
    cin >> n;
    while(n--){
        cin >> temp;
        arr.push_back(temp);
    }
    int uniqEle = removeDuplicates(arr);
    cout << "After removing the duplicates, there are " << uniqEle << " elements. They are: \n";
    for_each(arr.begin(), arr.end(), printElem);
    cout << '\n';
    return 0;
}
/*
1 2 3 3 3 3 3 4 4
*/