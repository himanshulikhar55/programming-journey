#include<bits/stdc++.h>
using namespace std;
/*
    You have been given weights and values of ‘N’ items. You are also given a knapsack of size ‘W’.

    Your task is to put the items in the knapsack such that the total value of items in the knapsack is maximum.

    Note:
    You are allowed to break the items.
    Example:
    If 'N = 4' and 'W = 10'. The weights and values of items are weights = [6, 1, 5, 3] and values = [3, 6, 1, 4]. 
    Then the best way to fill the knapsack is to choose items with weight 6, 1 and  3. The total value of knapsack = 3 + 6 + 4 = 13.00   

    Constraints:

    1 <= N <= 5000
    1 <= W <= 10^5
    1 <= weights[i] <= 10^5
    1 <= values[i] <= 10^5
*/
void printPair(pair<int, int> p1){
    cout << p1.first << ' ' << p1.second << '\n';
}
bool compareWeightToVal(const pair<int, int> &p1, const pair<int, int> &p2) {
    double wtToVal1 = ((double)p1.second)/p1.first;
    double wtToVal2 = ((double)p2.second)/p2.first;
    return wtToVal1 > wtToVal2; 
}
double maximumValue (vector<pair<int, int>>& items, int n, int w) {
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(), items.end(), compareWeightToVal);
    for_each(items.begin(), items.end(), printPair);
    double val = 0;
    for(int i=0; i<n; i++){
        if(w > items[i].first){
            w -= items[i].first;
            val += items[i].second;
        } else {
            val += ((double)(items[i].second)*(w))/items[i].first;
            break;
        }
    }
    return val;
}
int main(){
    int n, w;
    cout << "Enter the num of items and total wt:\n";
    cin >> n >> w;
    vector<pair<int, int>> items = vector<pair<int, int>>(n);
    for(int i=0;i<n;i++)
        cin >> items[i].first;
    for(int i=0;i<n;i++)
        cin >> items[i].second;
    cout << "The max value of knapsack is: " << maximumValue(items, n, w) << '\n';
    return 0;
}