#include <bits/stdc++.h>
using namespace std;
int minSwaps(vector<int> &arr)
{
	// Write your code here.
	vector<int> copy = arr;
	int n = arr.size();
	sort(copy.begin(), copy.end());
    for(int n : copy)
        cout << n << ' ';
    cout << '\n';
    for(int n : arr)
        cout << n << ' ';
    cout << '\n';
	unordered_map<int,int> posMap;
	for(int i=0;i<n;i++){
		posMap[copy[i]] = i;
	}
	int ans = 0;
	for(int i=0;i<n;i++){
		if(i != posMap[arr[i]]){
            int temp = arr[i];
            arr[i] = arr[posMap[arr[i]]];
            arr[posMap[arr[i]]] = temp;
			ans++;
            i--;
		}
	}
	for(int i=0;i<n;i++){
		if(copy[i]!=arr[i]){
			cout << copy[i] << ' ' << arr[i] << " HERE!\n";
        }
	}
    cout  << '\n' << ans << '\n';
	return ans;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr = vector<int>(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    int ans = minSwaps(arr);
}