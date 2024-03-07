#include<bits/stdc++.h>
using namespace std;
void printElements(int a){
    cout << a << ' ';
}
void rearrangeArray(vector<int>& nums) {
    queue<int> pos, neg;
    int i = 0, n = nums.size();
    while(i<n){
        if(nums[i]>0){
            pos.push(nums[i]);
        } else {
            neg.push(nums[i]);
        }
        i++;
    }
    i = 0;
    for(int i=0;i<n;i+=2){
        nums[i] = pos.front();
        nums[i+1] = neg.front();
        pos.pop();
        neg.pop();
    }
}
int main(){
    int n, temp;
    vector<int> arr;
    cin >> n;
    while(n--){
        cin >> temp;
        arr.push_back(temp);
    }
    rearrangeArray(arr);
    cout << "The rearranged array is: \n";
    for_each(arr.begin(), arr.end(), printElements);
    cout << '\n';
    return 0;
}