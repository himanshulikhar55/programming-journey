#include<bits/stdc++.h>
using namespace std;
int singleNumber(vector<int>& nums) {
    set<int> ele;
    for(int i : nums){
        if(ele.find(i) != ele.end())
            ele.erase(i);
        else
            ele.insert(i);
    }
    return *(ele.begin());
}
int main(){
    int n, temp;
    vector<int> arr;
    cin >> n;
    while(n--){
        cin >> temp;
        arr.push_back(temp);
    }
    int ans = singleNumber(arr);
    cout << "The only element occuring once is: " << ans << '\n';
    return 0;
}