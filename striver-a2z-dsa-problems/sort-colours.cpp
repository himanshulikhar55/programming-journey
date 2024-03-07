#include<bits/stdc++.h>
using namespace std;
void printElements(int a){
    cout << a << ' ';
}
void sortColors(vector<int>& nums) {
    int n = nums.size(), lo = 0, mid = 0, hi = n-1;
    while(mid <= hi){
        if(nums[mid] == 0){
            nums[mid] = nums[lo];
            nums[lo] = 0;
            lo++;
            mid++;
        } else if(nums[mid] == 1){
            mid++;
        } else {
            nums[mid] = nums[hi];
            nums[hi] = 2;
            hi--;
        }
        for_each(nums.begin(), nums.end(), printElements);
        cout << '\n';
    }
}
int main(){
    int n, temp;
    vector<int> arr;
    cin >> n;
    while(n--){
        cin >> temp;
        arr.push_back(temp);
    }
    sortColors(arr);
    cout << "The sorted array is: \n";
    for_each(arr.begin(), arr.end(), printElements);
    cout << '\n';
    return 0;
}