#include<bits/stdc++.h>
using namespace std;
/*
    There is a frog on the '1st' step of an 'N' stairs long staircase. The frog wants to reach the 'Nth' stair.
    'HEIGHT[i]' is the height of the '(i+1)th' stair.If Frog jumps from 'ith' to 'jth' stair, the energy lost in the jump is given by
    absolute value of ( HEIGHT[i-1] - HEIGHT[j-1] ). If the Frog is on 'ith' staircase, he can jump either to '(i+1)th' stair or to '(i+2)th'
    stair. Your task is to find the minimum total energy used by the frog to reach from '1st' stair to 'Nth' stair.
*/
int frogJump(int n, vector<int> &heights){
    if(heights.size() < 2)
        return 0;
    int len = heights.size();
    vector<int> minPowerToReach = vector<int>(len+1);
    minPowerToReach[1] = 0;
    minPowerToReach[2] = abs(heights[0]-heights[1]); 
    for(int i=3;i<=len;i++){
        minPowerToReach[i] = min(minPowerToReach[i-1] + abs(heights[i-2] - heights[i-1]),
                                                  minPowerToReach[i-2] + abs(heights[i-3] - heights[i-1]));
    }
    return minPowerToReach[len];
}
int main(){
    int n;
    cin >> n;
    vector<int> heights = vector<int>(n);
    for(int i=0;i<n;i++)
        cin >> heights[i];
    cout << "The min energy to climb " << n << " stairs is: " << frogJump(n, heights) << '\n';
    return 0;
}