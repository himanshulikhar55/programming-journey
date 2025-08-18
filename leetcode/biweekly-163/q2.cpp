#include <bits/stdc++.h>
using namespace std;
long long countPerfectPairs(vector<int>& nums) {
    vector<long long> a;
    a.reserve(nums.size());
    long long zeros = 0;
    for (int v : nums) {
        long long x = llabs((long long)v);
        if (x == 0)
            ++zeros;
        else
            a.push_back(x);
    }

    long long ans = zeros * (zeros - 1) / 2; // zeros pair only with zeros

    sort(a.begin(), a.end()); // positive magnitudes

    // two-pointer: count pairs with a[r] <= 2*a[l], l < r
    long long l = 0;
    for (long long r = 0; r < (long long)a.size(); ++r) {
        while (l < r && 2 * a[l] < a[r])
            ++l;
        ans += (r - l);
        // std::cout << ans << " ";
    }
    std::cout << endl;
    return ans;
}
int main() {
    int n;
    cin >> n;
    vector<int> nums = vector<int>(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << countPerfectPairs(nums) << endl;
    
}