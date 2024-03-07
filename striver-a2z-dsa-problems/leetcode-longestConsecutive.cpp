#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums){
    int ans = INT_MIN, temp = 0;
    unordered_map<int,int> arr;
    for(int i : nums)
        arr[i] = 1;
    unordered_map<int,int>::iterator it;
    for(it=arr.begin();it!=arr.end();++it){
        if(it->second == 0)
            continue;
        int num = it->first;
        cout << num << ' ';
        arr[num] = 0;
        --num;
        temp = 1;
        while(arr.find(num) != arr.end()){
            arr[num] = 0;
            ++temp;
            --num;
        }
        num = it->first;
        ++num;
        while(arr.find(num) != arr.end()){
            arr[num] = 0;
            ++temp;
            ++num;
        }
        ans = max(temp, ans);
    }
    return max(0, ans);
}

int main(){
    int n, temp;
    cin >> n;
    vector<int> arr;
    while(n--){
        cin >> temp;
        arr.push_back(temp);
    }
    int longestConsSeqSize = longestConsecutive(arr);
    
    cout << "The length of longest consecutive sequence is: "        
         << longestConsSeqSize << '\n';
    return 0;
}
//21 4 0 -4 -2 2 5 2 0 -8 -8 -8 -8 -1 7 4 5 5 -4 6 6 -3
// 