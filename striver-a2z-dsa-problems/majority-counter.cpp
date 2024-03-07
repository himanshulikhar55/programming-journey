#include<bits/stdc++.h>
using namespace std;
// void printElements(int a){
//     cout << a << ' ';
// }
int majorityElement(vector<int>& nums) {
    int candidate = INT_MAX, count = 1;
    for(int i : nums){
        if(candidate != i){
            --count;
            if(count == 0){
                candidate = i;
                count = 1;
            }
        } else {
            ++count;
        }
    }
    return candidate;
}
int main(){
    int n, temp;
    vector<int> arr;
    cin >> n;
    while(n--){
        cin >> temp;
        arr.push_back(temp);
    }
    int ans = majorityElement(arr);
    cout << "The majority element is: " << ans << '\n';
    // for_each(arr.begin(), arr.end(), printElements);
    // cout << '\n';
    return 0;
}