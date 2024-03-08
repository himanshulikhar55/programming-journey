#include<bits/stdc++.h>
using namespace std;
void printElements(int a){
    cout << a << ' ';
}
vector<int> majorityElement(vector<int>& nums) {
    if(nums.size() < 2)
        return nums;
    
    vector<int> ans;
    int len = nums.size(), candidate1 = 0, candidate2 = 0, count1 = 0, count2 = 0;
    for (int num : nums) {
        if (num == candidate1) {
            count1++;
        } else if (num == candidate2) {
            count2++;
        } else if (count1 == 0) {
            candidate1 = num;
            count1 = 1;
        } else if (count2 == 0) {
            candidate2 = num;
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }
    
    count1 = 0;
    count2 = 0;
    int threshold = len / 3;

    for (int num : nums) {
        if (num == candidate1) {
            count1++;
        } else if (num == candidate2) {
            count2++;
        }
    }

    if (count1 > threshold)
        ans.push_back(candidate1);
    if (count2 > threshold)
        ans.push_back(candidate2);

    return ans;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr = vector<int>(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    vector<int> ans = majorityElement(arr);
    cout << "The majority elements that occur atleast n/3 times are: \n";
    for_each(ans.begin(), ans.end(), printElements);
    cout << '\n';
    return 0;
}