#include<bits/stdc++.h>
using namespace std;
void printElem(int i){
    cout << i << ' ';
}
int findMaxConsecutiveOnes(vector<int>& nums) {
    int ans = 0, n = nums.size(), temp = 0;
    for(int i=0;i<n;i++){
        if(nums[i] == 1){
            temp = 0;
            while(i<n && nums[i] == 1){
                ++temp;
                ++i;
            }
            --i;
            ans = max(ans, temp);
        }
    }
    return ans;
}
int main(){
    int n, temp;
    vector<int> arr;
    cin >> n;
    while(n--){
        cin >> temp;
        arr.push_back(temp);
    }
    int ans = findMaxConsecutiveOnes(arr);
    cout << "Max no of consecutive ones is: " << ans << '\n';
    return 0;
}
/*
0 1 0 2 3 4 5
*/