#include <iostream>

int main(){
    int n;
    std::cin >> n;
    if(n > 1 && n < 4)
        std::cout << "NO SOLUTION\n";
    else {
        for(int i=2;i<=n;i+=2){
            std::cout << i << ' ';
        }
        for(int i=1;i<=n;i+=2){
            std::cout << i << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}