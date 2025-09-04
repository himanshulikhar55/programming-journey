#include <iostream>

int main(){
    long long n, len;
    std::cin >> n;
    len = n-1;
    n *= (n+1);
    n /= 2;
    int temp;
    for(int i=0;i<len;i++){
        std::cin >> temp;
        n -= temp;
    }
    std::cout << n << '\n';
}