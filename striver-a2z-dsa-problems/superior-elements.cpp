#include<bits/stdc++.h>
using namespace std;
void printElements(int a){
    cout << a << ' ';
}
vector<int> superiorElements(vector<int>&arr) {
    if(arr.size() < 2)
        return arr;
    vector<int> ans;
    int n = arr.size() - 2, lastMaxEle = arr[n+1];
    ans.push_back(arr.back());
    for(int i=n;i>=0;i--){
        if(arr[i] > lastMaxEle){
            ans.push_back(arr[i]);
            lastMaxEle = arr[i];
        }
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
    vector<int> ans = superiorElements(arr);
    cout << "The array of super elements is: \n";
    for_each(ans.begin(), ans.end(), printElements);
    cout << '\n';
    return 0;
}