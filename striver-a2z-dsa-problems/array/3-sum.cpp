#include<bits/stdc++.h>
using namespace std;
void printElements(int a){
    cout << a << ' ';
}
void printArray(vector<int> arr){
    for_each(arr.begin(), arr.end(), printElements);
    cout << '\n';
}
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    set<vector<int>> triplets;
    int n=nums.size(), lo, hi, sum;
    sort(nums.begin(), nums.end());
    for(int i=0;i<n;i++){
        lo = i+1, hi = n-1;
        while(lo<hi){
            sum = nums[i]+nums[lo]+nums[hi];
            if(sum > 0)
                --hi;
            else if(sum < 0)
                ++lo;
            else{
                triplets.insert({nums[i], nums[lo], nums[hi]});
                ++lo, --hi;
            }
        }
    }
    for(vector<int> triplet : triplets)
        ans.push_back(triplet);
    return ans;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr = vector<int>(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    vector<vector<int>> ans = threeSum(arr);
    cout << "The unique triplets that give sum 0 are: \n";
    for_each(ans.begin(), ans.end(), printArray);
    return 0;
}