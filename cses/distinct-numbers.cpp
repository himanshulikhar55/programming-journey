#include <iostream>
#include <set>
int main(){
    int n, temp;
    std::cin >> n;
    
    std::set<int> container;
    for(int i=0;i<n;i++){
        std::cin >> temp;
        container.insert(temp);
    }

    std::cout << container.size() << '\n';
    return 0;
}