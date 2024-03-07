#include<bits/stdc++.h>
using namespace std;
bool check(vector<int>& nums) {
    if(nums.size() < 2)
        return true;
    int minPos=0, tempPos, n = nums.size();
    for(int i=0;i<n;i++){
        if(nums[i] < nums[minPos]){
            minPos = i;
        }
    }
    if(minPos == 0){
        tempPos = n-1;
        while(nums[minPos] == nums[tempPos])
            tempPos--;
        minPos = (tempPos+1)%n;
    }
    int prevPos = minPos, currPos = (minPos + 1)%n;
    while(currPos != minPos){
        if(nums[currPos] < nums[prevPos])
            return false;
        prevPos = currPos;
        currPos = (currPos+1)%n;
    }
    return true;
}
int main(){
    int n, temp;
    vector<int> arr;
    cin >> n;
    while(n--){
        cin >> temp;
        arr.push_back(temp);
    }
    bool ans = check(arr);
    if(ans){
        cout << "Yes it was sorted and rotated!\n";
    } else {
        cout << "No it was not sorted!\n";
    }
    return 0;
}
/*
The challenge here was to place minPos at the start of the array.
Now the start could be at any position. It is the index of the least element but that could position
n-3 with position 0 also having the least number as numbers are not distinct.
Hence we put the while loop after then for loop, to take care of this.
*/