#include<bits/stdc++.h>
using namespace std;
vector<int> getSecondOrderElements(int n, vector<int> arr) {
    // Write your code here.
    vector<int> ans;
    int min1 = INT_MAX, min2 = INT_MAX, max1 = INT_MIN, max2 = INT_MIN;
    for(int i : arr){
        if(i < min1){
            min2 = min1;
            min1 = i;
        } else {
            min2 = min(i, min2);
        }
        if(i > max1){
            max2 = max1;
            max1 = i;
        } else {
            max2 = max(i, max2);
        }
    }
    ans.push_back(max2);
    ans.push_back(min2);
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
    vector<int> ans = getSecondOrderElements(arr.size(), arr);
    cout << "The 2nd largest ele: " << ans[0] << " the 2nd smallest ele: " << ans[1] << '\n';
    return 0;
}