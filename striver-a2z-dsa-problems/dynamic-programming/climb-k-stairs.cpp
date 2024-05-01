#include<bits/stdc++.h>
using namespace std;
/*
    There is an array of heights corresponding to 'n' stones. You have to reach from stone 1 to stone ‘n’.
    
    From stone 'i', it is possible to reach stones 'i'+1, ‘i’+2… ‘i’+'k' , and the cost incurred will be | Height[i]-Height[j] |,
    where 'j' is the landing stone.
    
    Return the minimum possible total cost incurred in reaching the stone ‘n’.
*/
int minimizeCost(int n, int k, vector<int> &height){
    // Write your code here.
    if(height.size() < 2)
        return 0;
    int len = height.size();
    vector<int> minCost = vector<int>(len+1, INT_MAX);
    minCost[1] = 0;
    for(int i=1;i<=len;i++){
        for(int j=1;j<=k;j++){
            if(i+j <= n)
                minCost[i+j] = min(minCost[i+j], minCost[i] + abs(height[i-1] - height[i+j-1]));
        }
    }
    return minCost[len];
}
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> heights = vector<int>(n);
    for(int i=0;i<n;i++)
        cin >> heights[i];
    cout << "The number of ways I can climb " << n << " stairs is: " << minimizeCost(n, k, heights) << '\n';
    return 0;
}