#include <bits/stdc++.h>

int search(std::vector<int>& nums, int target) {
    int lo = 0, hi = nums.size();
    while(lo < hi) {
        int mid = lo + (hi-lo)/2;
        if(nums[mid] > target)
            hi = mid-1;
        else if(nums[mid] < target)
            lo = mid + 1;
        else
            return mid;
    }
    if (nums[lo] == target)
        return lo;
    return -1;
}
int main() {
    int n, target;
    std::cin >> n;
    std::vector<int> nums = std::vector<int>(n);
    for(int i=0;i<n;i++)
        std::cin >> nums[i];
    std::cin >> target;
    std::cout << search(nums, target) << std::endl;
}