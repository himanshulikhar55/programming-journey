#include<bits/stdc++.h>
using namespace std;
/*
    Given an infinite supply of Indian currency i.e. [1, 2, 5, 10, 20, 50, 100, 500, 1000] valued coins and an amount 'N'.

    Find the minimum coins needed to make the sum equal to 'N'. You have to return the list containing the value of coins required in
    decreasing order.

    For Example
    For Amount = 70, the minimum number of coins required is 2 i.e an Rs. 50 coin and a Rs. 20 coin.
    Note:
    It is always possible to find the minimum number of coins for the given amount. So, the answer will always exist.

    Constraints:

    1 <= 'N' <= 10^5
*/
vector<int> MinimumCoins(int v){
    vector<int> coins = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
    vector<int> ans;
    for(int i=0;i<9;i++){
        if(coins[i] > v)
            continue;
        while(v >= coins[i]){
            ans.push_back(coins[i]);
            v -= coins[i];
        }
    }
    return ans;
}
void printInt(int i){
    cout << i << ' ';
}
int main(){
    int v;
    cout << "Enter the total value:\n";
    cin >> v;
    cout << "The coins required are: ";
    vector<int> ans = MinimumCoins(v);
    for_each(ans.begin(), ans.end(), printInt);
    cout << '\n';
    return 0;
}