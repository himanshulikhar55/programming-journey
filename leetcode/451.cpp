#include <bits/stdc++.h>
std::vector<int> freqMap = std::vector<int>(256);
static bool customComparator(char a, char b) {
    return freqMap[a] > freqMap[b];
}
std::string frequencySort(std::string s) {
    for(char c : s) {
        freqMap[c]++;
    }
    std::sort(s.begin(), s.end(), customComparator);
    return s;
}

int main() {
    std::string s;
    std::cin >> s;
    std::cout << frequencySort(s) << std::endl;
    return 0;
}