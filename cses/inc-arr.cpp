#include <iostream>
#include <vector>

int main(){
    int n;
    long long ans = 0;
    std::cin >> n;
    std::vector<int> arr = std::vector<int>(n);
    for(int i=0;i<n;i++){
        std::cin >> arr[i];
    }
    for(int i=1;i<n;i++){
        if(arr[i] > arr[i-1])
            continue;
        else{
            ans += arr[i-1]-arr[i];
            arr[i] = arr[i-1];
        }
    }
    std::cout << ans << '\n';
}