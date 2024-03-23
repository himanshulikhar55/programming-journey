
#include<bits/stdc++.h>
using namespace std;
bool canPaintArea(vector<int> &boards, int painters, int maxBoardArea){
    int n=boards.size(), areaPainted=0;
    --painters;
    for(int i=0;i<n;i++){
        areaPainted += boards[i];
        if(areaPainted > maxBoardArea){
            --painters;
                areaPainted = boards[i];
        }
    }
    return painters >= 0;
}
int findLargestMinDistance(vector<int> &boards, int k) {
    int n=boards.size(), lo=*max_element(boards.begin(), boards.end()), hi=0, boardArea;
    for(int i=0;i<n;i++)
        hi += boards[i];
    while(lo<=hi){
        boardArea = (hi+lo)/2;
        if(canPaintArea(boards, k, boardArea))
            hi = boardArea-1;
        else
            lo = boardArea+1;
    }
    return lo;
}
int main(){
    int n, k;
    cin >> n;
    vector<int> arr = vector<int>(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    cin >> k;
    int ans = findLargestMinDistance(arr, k);
    cout << "The  minimized max time to paint all the boards, with " << k << " painters painting together is: " << ans << '\n';
    return 0;
}