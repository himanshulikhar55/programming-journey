#include<bits/stdc++.h>
using namespace std;
// void printElements(int a){
//     cout << a << ' ';
// }
int maxProfit(vector<int>& prices) {
    if(prices.size() < 2)
        return 0;
    int ans = 0, buy = 0, sell = 1, n = prices.size();
    while(sell < n){
        if(prices[buy] < prices[sell]){
            ans = max(ans, prices[sell] - prices[buy]);
        } else {
            while(prices[buy] >= prices[sell] && buy < sell){
                ++buy;
            }
            ans = max(ans, prices[sell] - prices[buy]);
        }
        ++sell;
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
    int ans = maxProfit(arr);
    cout << "The maximum profit we can get is: " << ans << '\n';
    // for_each(arr.begin(), arr.end(), printElements);
    // cout << '\n';
    return 0;
}