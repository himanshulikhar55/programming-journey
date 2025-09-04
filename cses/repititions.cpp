#include <string>
#include <iostream>

int main(){
    std::string s;
    std::cin >> s;
    int start=0, end=0, n = s.length(), ans = 1;
    for(end=1;end<n;end++){
        if(s[end]!=s[start]){
            ans = std::max(ans, end-start);
            start = end;
        }
    }
    ans = std::max(ans, end-start);
    std::cout << ans<< '\n';
    return 0;
}